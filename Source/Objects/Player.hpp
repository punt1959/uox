// 
// Created on:  6/4/21

#ifndef Player_hpp
#define Player_hpp

#include <cstdint>
#include <string>
#include <memory>
#include "incoming_classfwd.h"
#include "bidirectional_classfwd.h"
#include "PacketHandler.hpp"
class GSocket ;

class Player : public PacketHandler{
private:
	std::shared_ptr<GSocket> _mysocket ;
protected:
	std::string _accountName ;
public:
	Player(std::shared_ptr<GSocket> &socket );
	std::shared_ptr<GSocket> mysocket() ;
	void mysocket(std::shared_ptr<GSocket> &socket);
	std::string accountName() const ;
	void accountName(const std::string &value);
	void processPacket() ;

	void processPacket0x80(std::shared_ptr<Packet0x80> &packet) override;


};

#endif /* Player_hpp */
