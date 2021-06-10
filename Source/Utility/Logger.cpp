// 
// Created on:  6/4/21

#include "Logger.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <cstdarg>
#include <cstdio>

#include "TimeUtility.hpp"

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Logger
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++

const std::string Logger::_default_file = "./UOX3log.txt" ;
const std::string Logger::_logheader = "UOX3 Refresh Log File";
//============================================================================
Logger::Logger(const std::string &filename) {
	_loop_time = _default_loop_time;
	_endloop = false ;
	setLogFile(filename);
	_logloop = std::thread(&Logger::runLoop,this);  // Startup our thread
}
//============================================================================
Logger::~Logger() {
	_endloop = true ;
	_logloop.join();
}
//============================================================================
Logger& Logger::shared(const std::string& filename){
	static Logger instance(filename);
	return instance ;
}
//============================================================================
void Logger::setLoopDelay(std::size_t milliseconds){
	_loop_time = milliseconds ;
}
//============================================================================
void Logger::setLogFile(const std::string &filename){
	auto temp_filename = filename ;
	auto path = std::filesystem::path(temp_filename) ;
	if (std::filesystem::is_directory(path)){
		// We need to move the file name over
		auto defpath = std::filesystem::path(_logfile) ;
		auto fpath = defpath.filename() ;
		if (fpath.empty()){
			fpath = std::filesystem::path(_default_file) ;
		}
		path = path / fpath ;
		temp_filename = path.string() ;
		
	}
	
	std::lock_guard lock(_file_lock) ;
	if (temp_filename.empty()){
		_logfile = _default_file ;
	}
	else {
		_logfile = temp_filename ;
	}
	// create the file
	std::ofstream output(_logfile,std::ios::app);
	if (!output.is_open()) {
		throw std::runtime_error(std::string("Logger: Unable to open: " + _logfile));
	}
	output << "\n" << _logheader <<" " << timeutil::timenow() << "\n"<<std::endl;
	output.close() ;
	
}

//=============================================================================
void Logger::log(const std::string &value){
	
	std::cout << value << std::endl;
	std::lock_guard lock(_queue_lock) ;
	_values.push(value);
}
//=============================================================================
void Logger::log(const char* format,...){
	char buffer[2048] ;
	va_list v1 ;
	va_start(v1, format);
	vsnprintf(buffer, 2048, format, v1);
	va_end(v1) ;
	log(std::string(buffer));
}

//=============================================================================
void  Logger::flush(std::queue<std::string> &values){
	std::ofstream output;
	if (values.size()>0) {
		{
			std::lock_guard lock(_file_lock) ;
			output.open(_logfile,std::ios::app) ;
			
			while (values.size() != 0){
				auto value = values.front();
				values.pop() ;
				output << "Logged: " << timeutil::timenow() <<"\n"<< value << "\n";
				
			}
		}
		
		output.close();
	}
}
//=============================================================================
void Logger::runLoop() {
	while (!_endloop){
		std::queue<std::string> dummy ;
		{
			// We drop down a scope so our lock will go out after swap
			std::lock_guard lock(_queue_lock) ;
			std::swap(dummy, _values) ;
		}
		flush(dummy) ;
		std::this_thread::sleep_for(std::chrono::milliseconds(_loop_time));
	}
	std::queue<std::string> dummy ;
	{
		// We drop down a scope so our lock will go out after swap
		std::lock_guard lock(_queue_lock) ;
		std::swap(dummy, _values) ;
	}
	flush(dummy) ;
	
}
//=============================================================================
void Logger::stop(){
	_endloop = true ;
}
