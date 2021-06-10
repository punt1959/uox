// 
// Created on:  6/5/21

#ifndef PlayerList_hpp
#define PlayerList_hpp

#include <cstdint>
#include <string>
#include <list>
#include <memory>
#include <mutex>

class Player ;

class PlayerList {
private:
	std::list<std::shared_ptr<Player>> _players ;
	
	std::mutex _list_lock ;
protected:
	PlayerList();

public:
	PlayerList( const PlayerList &) = delete;
	PlayerList& operator=(const PlayerList&) = delete ;
	static PlayerList& shared() ;
	
	std::size_t size()  ;
	std::list<std::shared_ptr<Player>> player() ;
	void add(std::shared_ptr<Player> &player) ;
	void remove(std::shared_ptr<Player> &player);
};

#endif /* PlayerList_hpp */
