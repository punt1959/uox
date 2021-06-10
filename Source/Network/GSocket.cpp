// 
// Created on:  6/4/21

#include "GSocket.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include "TimeUtility.hpp"
#include "StringUtility.hpp"
#include "Logger.hpp"
#include "Player.hpp"
#include "Packet.hpp"
#include "IP4Address.hpp"

class IP4Address;
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for GSocket
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++

//============================================================================
GSocket::GSocket(SOCKET fd, IP4Address& ipaddress, int port) : Socket(fd,ipaddress,port){
	_myplayer = std::weak_ptr<Player>();
	_state = readstate::packet ;
	
}
//============================================================================
GSocket::GSocket() : Socket() {
	_myplayer = std::weak_ptr<Player>();
}

//============================================================================
std::shared_ptr<Player> GSocket::player()  {
	
	return _myplayer.lock() ;
}

//============================================================================
void GSocket::player(std::shared_ptr<Player> &value) {
	_myplayer = value ;
}


//============================================================================
void GSocket::push(std::shared_ptr<Packet> &packet){
	packet->finalize();
	if (_compress) {
		packet->_data = packet->applyHuffman();
	}
	std::lock_guard lock(_outgoing_lock) ;
	_outgoing.push(packet);
}
//============================================================================
std::shared_ptr<Packet> GSocket::pop() {
	std::lock_guard lock(_incoming_lock) ;
	if (_incoming.size()>0){
		auto value = _incoming.front();
		_incoming.pop();
		return value ;
	}
	return nullptr;
}
//============================================================================
std::queue<std::shared_ptr<Packet>> GSocket::popAll(){
	std::queue<std::shared_ptr<Packet>> rvalue ;
	std::lock_guard lock(_incoming_lock);
	std::swap(rvalue,_incoming);
	return rvalue ;
}


//=============================================================================
bool GSocket::valid() {
	return (descriptor() != INVALID_SOCKET);
}

//=============================================================================
void GSocket::read() {
	
	if (_state == readstate::packet){
		unsigned char packid ;
		auto size = this->receive(&packid, 1);
		if (size == 1) {
			
			_amount_read = 1 ;
			_current_incoming = Packet::createPacket(packid);
			if (!_current_incoming->variable()) {
				_state = readstate::data ;
				
			}
			else {
				_state = readstate::length ;
				_read_index=0 ;
			}
			
		}
	}
	if (_state == readstate::length){
		
		auto size = this->receive(_read_buffer + _read_index, 2 -_read_index) ;
		switch (size) {
			case 0:
				// Didn't read anything, so wait
				break;
			case 1:
				// this can mean one of two things
			{
				if (_read_index == 0) {
					_read_index = 1 ;
				}
				else {
					// we got all the data!
					
					_current_incoming->Buffer::size(*reinterpret_cast<unsigned short*>(_read_buffer)) ;
					_amount_read = 3 ;
					_current_incoming->write(*reinterpret_cast<unsigned short*>(_read_buffer));
					_state = readstate::data;
				}
				break;
			}
			case 2:
			default:
				// We got it all in one swoop!
				// we got all the data!
				_current_incoming->Buffer::size(*reinterpret_cast<unsigned short*>(_read_buffer)) ;
				_amount_read = 3 ;
				_current_incoming->write(*reinterpret_cast<unsigned short*>(_read_buffer));
				_state = readstate::data;
				break;
		}
		
	}
	if (_state == readstate::data) {
		if ((_current_incoming->size()-_amount_read) == 0){
			// we do this if it is a packet number only
			_state = readstate::packet ;
			_amount_read = 0 ;
			{
				_current_incoming->finalize();
				if (_log) {
					
					std::stringstream output ;
					output << strutil::format("Received: %s | Server-->%s \n",timeutil::timenow().c_str(),this->_ipaddress.string().c_str());
					output << _current_incoming->description();
					Logger::shared().log(output.str());
				}
				std::lock_guard lock(_incoming_lock);
				_incoming.push(_current_incoming);
				_current_incoming = nullptr;
			}
			
		}
		else {
			auto size = this->receive(_current_incoming->data()+_amount_read, _current_incoming->size()-_amount_read);
			_amount_read += size ;
			if ((_current_incoming->size()-_amount_read) == 0){
				_state = readstate::packet ;
				_amount_read = 0 ;
				{
					_current_incoming->finalize();
					if (_log) {
						std::stringstream output ;
						output << strutil::format("Received: %s | %s -->Server\n",timeutil::timenow().c_str(),this->_ipaddress.string().c_str());
						output << _current_incoming->description();
						Logger::shared().log(output.str());
					}
					std::lock_guard lock(_incoming_lock);
					_incoming.push(_current_incoming);
					_current_incoming = nullptr;
				}
			}
			
		}
	}
}

//=============================================================================
void GSocket::send() {
	if (_current_outgoing == nullptr) {
		// see if we have a packet
		{
			std::lock_guard lock(_outgoing_lock) ;
			if (_outgoing.size() > 0){
				_current_outgoing = _outgoing.front();
				_outgoing.pop();
				_amount_sent = 0 ;
			}
		}
	}
	if (_current_outgoing != nullptr) {
		
		auto size = Socket::send(_current_outgoing->_data.data()+_amount_sent, _current_outgoing->_data.size() - _amount_sent);
		_amount_sent = _amount_sent + size ;
		if (_amount_sent == _current_outgoing->_data.size()){
			// we sent it!
			_amount_sent = 0 ;
			if (_log) {
				std::stringstream output ;
				output << strutil::format("Client: %s Sent: %s ---Outgoing->\n",this->_ipaddress.string().c_str(),timeutil::timenow().c_str());
				output << _current_outgoing->description();
				Logger::shared().log(output.str());
				
			}
			_current_outgoing = nullptr;
		}
		
		
	}
}
