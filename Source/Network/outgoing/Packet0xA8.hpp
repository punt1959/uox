#ifndef Packet0xA8_hpp
#define Packet0xA8_hpp

#include <cstdint> 
#include <string>

#include "Packet.hpp"
//===============================================================================
//		Packet 0xA8  - Game Server List
//
//		Size: variable
//
//		Format:
//			unsigned char 	cmd (packet id)
//			unsigned short  	length
//			char			System Info
//				0xCC - 	Don't send
//				0x5D =	Unknown (sent by runuo)
//				0x64 =	Send Video card info
//			unsigned short	Number of servers (0 indexed)
//			For each server
//				unsigned short		server index (0-based)
//				char[32]			server name
//				char				percent full
//				char				timezone
//				unsigned int		ping ip of server
//								(this is in big endian, example,
//								192.168.0.1 is sent as 0100A8C0)
//
//==============================================================================

class Packet0xA8 : public Packet {
private:
	static constexpr std::size_t server_entry_size = 38 ;
	unsigned char countServer ;
protected:
public:

	Packet0xA8();
	unsigned short numberServer() ;
	
	void addServer(const std::string &name,char percentfull,char timezone,const std::string &ipaddress);
	void finalize() override ;
	std::tuple<std::string,char,char,std::string> server(unsigned short index) ;

};

#endif
