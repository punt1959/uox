// 
// Created on:  6/4/21

#ifndef GSocket_hpp
#define GSocket_hpp

#include <cstdint>
#include <string>
#include <queue>
#include <mutex>
#include <memory>
#include <atomic>
#include "Socket.hpp"

class Packet;
class Player;
class ServerSocket ;
class IP4Address ;
class GSocket : public Socket{
private:
	
protected:
	enum class readstate { packet,length,data};
	// Queue for outgoing packets
	std::queue<std::shared_ptr<Packet>> _outgoing ;
	std::recursive_mutex _outgoing_lock ;
	
	std::shared_ptr<Packet> _current_outgoing ;
	std::size_t _amount_sent ;
	
	
	std::atomic<bool> _compress ;
	
	// For reading
	std::queue<std::shared_ptr<Packet>> _incoming ;
	std::recursive_mutex _incoming_lock ;
	
	std::shared_ptr<Packet> _current_incoming ;
	std::size_t _amount_read ;
	unsigned char _read_buffer[2] ;
	int		_read_index;
	readstate _state ;

	std::weak_ptr<Player> _myplayer ;    // Who does this socket belong to?

	std::atomic<bool> _log ;
	friend class Packet ;
	friend class ServerSocket ;
public:

	
	
	GSocket(SOCKET fd, IP4Address& ipaddress, int port);
	GSocket() ;
	void read();
	void send() ;

	std::shared_ptr<Player> player()  ;
	void player(std::shared_ptr<Player> &value) ;
	
	void push(std::shared_ptr<Packet> &packet);		// Send a packet
	
	std::shared_ptr<Packet> pop() ;			// get packets
	std::queue<std::shared_ptr<Packet>> popAll() ;
	
	bool valid()  ;
	void setLogging(bool value) { _log = value;} ;

};

#endif /* GSocket_hpp */
