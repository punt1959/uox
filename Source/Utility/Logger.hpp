// 
// Created on:  6/4/21

#ifndef Logger_hpp
#define Logger_hpp

#include <cstdint>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <atomic>

class Logger {
private:
	static const std::string _default_file ;
	static const std::string _logheader ;
	static constexpr std::size_t _default_loop_time = 500 ; // 500 milliseconds
	Logger(const std::string& filename);
	void output(const std::string &value);
	
	std::queue<std::string> _values ;
	std::recursive_mutex _queue_lock ;
	
	std::mutex _file_lock ;
	
	std::thread _logloop;
	std::string _logfile ;
	std::atomic<std::size_t> _loop_time ;
	std::atomic<bool> _endloop ;
	
	void runLoop() ;
	void flush(std::queue<std::string> &values) ;
	
public:
	Logger( const Logger &) = delete;
	Logger& operator=(const Logger&) = delete ;
	~Logger() ;
	
	static Logger& shared(const std::string& filename="") ;
	
	void setLoopDelay(std::size_t milliseconds);
	
	void setLogFile(const std::string &filename);
	void log(const std::string &value);
	void log(const char* format,...);
	void stop() ;
};

#endif /* Logger_hpp */
