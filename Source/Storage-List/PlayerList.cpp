// 
// Created on:  6/5/21

#include "PlayerList.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for PlayerList
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//===========================================================================
PlayerList::PlayerList(){
	
}

//============================================================================
PlayerList& PlayerList::shared(){
	static PlayerList instance;
	return instance ;
}

//===========================================================================
std::size_t PlayerList::size()  {
	std::lock_guard lock(_list_lock);
	return _players.size();
}
//===========================================================================
std::list<std::shared_ptr<Player>> PlayerList::player() {
	std::lock_guard lock(_list_lock);
	return _players;

}
//===========================================================================
void PlayerList::add(std::shared_ptr<Player> &player) {
	std::lock_guard lock(_list_lock);
	_players.push_back(player);
}
//===========================================================================
void PlayerList::remove(std::shared_ptr<Player> &player){
	std::lock_guard lock(_list_lock);
	auto iter = _players.begin();
	while (iter != _players.end()){
		if (player == *iter) {
			_players.erase(iter);
			break;
		}
		iter++;
	}
}
