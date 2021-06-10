// 
// Created on:  6/5/21

#ifndef ServerSocket_hpp
#define ServerSocket_hpp

#include <cstdint>
#include <string>
#include <thread>
#include <list>
#include <memory>
#include <mutex>
#include <atomic>
#include <vector>
#include "IP4Address.hpp"

class Socket ;
class GSocket ;
class ServerSocket {
private:
	ServerSocket();
	std::atomic<bool> _listen ;
	std::atomic<bool> _log ;
	
	std::vector<IP4Address> _banlist ;
	std::mutex _ban_lock ;
	
	std::unique_ptr<Socket> _mysocket ;
	
	std::thread _listener ;
	std::thread _service ;
	
	std::mutex _read_write_lock ;
	std::list<std::weak_ptr<GSocket>> _sockets ;
	
	std::atomic<bool> _logDefault ;
	
	static constexpr int _connection_time = 1000 ; // milliseconds, so 1 second
	static constexpr int _read_write_time = 100 ; // Every 100 milliseconds?
	bool checkFirewall(const IP4Address &ipaddress);
	void connections() ;
	void readAndWrite() ;

public:
	static std::vector<std::string> parseIP(const std::string &ip);

	ServerSocket( const ServerSocket &) = delete;
	ServerSocket& operator=(const ServerSocket&) = delete ;
	~ServerSocket() ;
	static ServerSocket& shared() ;
	
	void start(int port) ;
	void start(const std::string &port) ;
	void stop() ;
	void setLogging(bool value);
	void logDefault(bool value) ;
	void loadFirewall(const std::string &filename);

};

#endif /* ServerSocket_hpp */
