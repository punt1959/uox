// 
// Created on:  6/4/21

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <thread>
#include <atomic>

#include "Configuration.hpp"
#include "IP4Address.hpp"
#include "ServerSocket.hpp"
#include "Logger.hpp"
#include "Tiles.hpp"
#include "PlayerList.hpp"

int main(int argc, const char * argv[]) {
	std::atomic<bool> loop_state = false ;
	std::string config_file = "uoxr.cfg" ;
	if (argc > 1) {
		config_file = argv[1] ;
	}
	try {
		// Get our ips for the devices
		std::cout <<"Gather device IPs" << std::endl;
		IP4Address::loadIPs();
		// Load the base configuration file
		std::cout << "Processing configuration file: " << config_file << std::endl;
		Configuration::shared().loadBase(config_file);
		
		// Load UO data. Tiles must be loaded before anything else, as it is used in all other loadinds of UO data.
		auto uodir = Configuration::shared().uodir();
		auto tiledata = uodir / std::filesystem::path("tiledata.mul");
		std::cout <<"Loading Tile data from "<<tiledata.string()<<std::endl;
		UO::Tiles::shared(tiledata.string());
		
		
		std::cout <<"Loading definitions"<< std::endl;
		Configuration::shared().loadDefinitions( Configuration::shared().definition());
		
		std::cout <<"Setting external IP to " <<Configuration::shared().ip()<<std::endl;
		// Set the ip to use for wan users ;
		IP4Address::setExternal(Configuration::shared().ip());

		std::cout <<"Setting default logging to " <<std::boolalpha<<Configuration::shared().defaultlog()<< std::endl;
		// Setup the default log state
		ServerSocket::shared().setLogging(Configuration::shared().defaultlog());
		
		std::cout <<"Starting up services"<< std::endl;
		// Start up the services
		// Start and set  the log location
		Logger::shared(Configuration::shared().log());
		// Start listening for connections ;
		ServerSocket::shared().start(Configuration::shared().port());
		
		loop_state = true ;
		do {
			std::this_thread::sleep_for(std::chrono::milliseconds(25));
		}while (loop_state);
		// we need to shut down some things ;
		ServerSocket::shared().stop() ;
		Logger::shared().stop();
		
	}
	catch(const std::exception &e) {
		std::cout <<"Unrecoverable error: "<< e.what()<< std::endl;
	}
	return EXIT_SUCCESS;
}
