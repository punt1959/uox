// 
// Created on:  6/5/21

#include "ServerSocket.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "Logger.hpp"
#include "GSocket.hpp"
#include "Player.hpp"
#include "PlayerList.hpp"
#include "StringUtility.hpp"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for ServerSocket
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//============================================================================
ServerSocket::ServerSocket(){
	_listen = false ;
	_mysocket = nullptr ;
	_log = false ;
	_logDefault = false ;
}
//============================================================================
ServerSocket::~ServerSocket(){
	stop();
	
}
//============================================================================
ServerSocket& ServerSocket::shared(){
	static ServerSocket instance;
	return instance ;
}

//============================================================================
void ServerSocket::stop() {
	if (_listen) {
		_listen = false ;
		_listener.join() ;
		_service.join() ;
		_mysocket->close() ;
		_mysocket = nullptr;
		_sockets.clear();
	}

}
//============================================================================
void ServerSocket::setLogging(bool value) {
	_log = value ;
}

//============================================================================
bool ServerSocket::checkFirewall(const IP4Address &ipaddress){
	std::vector<IP4Address> templist ;
	{
		std::lock_guard lock(_ban_lock);
		templist = _banlist;
	}
	
	for (auto &entry : templist){
		if (entry == ipaddress){
			return true ;
		}
	}
	return false ;
}

//============================================================================
void ServerSocket::connections(){
	while (_listen) {
		if (_mysocket == nullptr) {
			_listen = false ;
			break;
		}
		auto info = _mysocket->accept() ;
		if (std::get<0>(info) != INVALID_SOCKET) {
			// We got a socket!
			if (!checkFirewall(std::get<1>(info))) {
				// we need to close the socket
				Socket::closeSocket(std::get<0>(info));
				if (_log) {
					Logger::shared().log("Blocked connection: %s - %s",std::get<1>(info).string().c_str(),std::get<2>(info).c_str());
				}
				continue ;
			}
			if (_log) {
				Logger::shared().log("Connection: %s - %s",std::get<1>(info).string().c_str(),std::get<2>(info).c_str());

			}
			auto port = std::stoi(std::get<2>(info));
			auto sock = std::make_shared<GSocket>(std::get<0>(info),std::get<1>(info),port);
			sock->setLogging(_logDefault);
			auto player = std::make_shared<Player>(sock);
			sock->player(player);
			PlayerList::shared().add(player) ;
			std::weak_ptr<GSocket> weak = sock ;
			{
				std::lock_guard lock(_read_write_lock) ;
				_sockets.push_back(weak);
			}
			
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(_read_write_time));
		}
	}
}
//==============================================================================
void ServerSocket::readAndWrite(){
	while (_listen){
		std::list<std::weak_ptr<GSocket>> _service ;
		{
			std::lock_guard lock(_read_write_lock) ;
			_service = _sockets ;
		}
		//std::cout << "Connected size to service " << _service.size() << std::endl;
		auto iter = _service.begin();
		while (iter != _service.end()) {
			auto current = iter->lock() ;
			if ((current!= nullptr) && (current->valid())) {
				current->read();
				current->send();
			}
			else {
				std::cout <<"INVALID/NULL" << std::endl;
			}
			iter++;
		}
		// Now clean up
		{
			std::lock_guard lock(_read_write_lock) ;
			_sockets.remove_if([](std::weak_ptr<GSocket> &sock){
				auto current = sock.lock();
				return ((current == nullptr) || (!current->valid()));
			});

		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(_read_write_time));
	}
}

//===============================================================================
void ServerSocket::start(const std::string &port) {
	try {
		auto value = std::stoi(port);
		start(value);
	}
	catch(const std::exception& e){
		throw std::runtime_error(std::string("Unable to start server socket with port: ")+port + std::string(" Error was: ")+e.what());
	}
}

//===============================================================================
void ServerSocket::start(int port){
	_mysocket = std::make_unique<Socket>(port);
	_listen = true ;
	_service = std::thread(&ServerSocket::readAndWrite,this) ;
	_listener = std::thread(&ServerSocket::connections,this) ;
}

//===============================================================================
void ServerSocket::logDefault(bool value) {
	_logDefault = value ;
}


//========================================================================
void ServerSocket::loadFirewall(const std::string &filename){
	std::ifstream input(filename,std::ios::in);
	_banlist.clear() ;
	if (filename.empty()){
		return ;
	}
	std::vector<IP4Address> templist ;
	if (input.is_open()) {
		char buffer[2028];
		do{
			input.getline(buffer, 2027);
			buffer[input.gcount()] = 0 ;
			auto line = std::string(buffer);
			line = strutil::stripTrim(line);
			if (line.empty()){
				continue ;
			}
			auto parts = IP4Address(line);
			if (parts.valid()){
				templist.push_back(parts);
			}
			
		} while((!input.eof()) && input.good());
		input.close();
		std::lock_guard lock(_ban_lock);
		std::swap(templist, _banlist);
	}
}
