// 
// Created on:  6/4/21

#include "Player.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include "GSocket.hpp"

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Player
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//=============================================================================
Player::Player(std::shared_ptr<GSocket> &socket ):PacketHandler() {
	_mysocket = socket ;
	_accountName = "UNDEFINED";
}
//=============================================================================
std::shared_ptr<GSocket> Player::mysocket() {
	return _mysocket;
}
//=============================================================================
void Player::mysocket(std::shared_ptr<GSocket> &socket) {
	_mysocket = socket ;
}
//=============================================================================
std::string Player::accountName() const {
	return _accountName ;
}
//=============================================================================
void Player::accountName(const std::string &value) {
	_accountName = value ;
}
//==============================================================================
void Player::processPacket() {
	if (_mysocket!= nullptr){
		auto packets = _mysocket->popAll() ;
		appendPackets(packets);
	}
	if (_pending.size() >0) {
		auto packet = _pending.front();
		_pending.pop_front();
		dispatchPacket(packet);
	}
}

//=============================================================================
void Player::processPacket0x80(std::shared_ptr<Packet0x80> &packet) {
	std::cout <<"Processing packet 0x80"<<std::endl;
}

