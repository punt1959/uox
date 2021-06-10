// 
// Created on:  6/6/21

#ifndef PacketHandler_hpp
#define PacketHandler_hpp

#include <cstdint>
#include <string>
#include <memory>
#include <queue>
#include <deque>
#include "incoming_classfwd.h"
#include "bidirectional_classfwd.h"

class Packet ;
class PacketHandler {
private:
	
protected:
	std::deque<std::shared_ptr<Packet>> _pending ;
	
	void dispatchPacket (std::shared_ptr<Packet> &packet);
	void appendPackets(std::queue<std::shared_ptr<Packet>> &incoming) ;
	
	//----------------- Bidirectional Packet Processing ---------------
	virtual void processPacket0x0C(std::shared_ptr<Packet0x0C> &packet){}
	virtual void processPacket0x15(std::shared_ptr<Packet0x15> &packet){}
	virtual void processPacket0x22(std::shared_ptr<Packet0x22> &packet){}
	virtual void processPacket0x2C(std::shared_ptr<Packet0x2C> &packet){}
	virtual void processPacket0x39(std::shared_ptr<Packet0x39> &packet){}
	virtual void processPacket0x3A(std::shared_ptr<Packet0x3A> &packet){}
	virtual void processPacket0x56(std::shared_ptr<Packet0x56> &packet){}
	virtual void processPacket0x66(std::shared_ptr<Packet0x66> &packet){}
	virtual void processPacket0x6C(std::shared_ptr<Packet0x6C> &packet){}
	virtual void processPacket0x6F(std::shared_ptr<Packet0x6F> &packet){}
	virtual void processPacket0x71(std::shared_ptr<Packet0x71> &packet){}
	virtual void processPacket0x72(std::shared_ptr<Packet0x72> &packet){}
	virtual void processPacket0x73(std::shared_ptr<Packet0x73> &packet){}
	virtual void processPacket0x93(std::shared_ptr<Packet0x93> &packet){}
	virtual void processPacket0x95(std::shared_ptr<Packet0x95> &packet){}
	virtual void processPacket0x98(std::shared_ptr<Packet0x98> &packet){}
	virtual void processPacket0x99(std::shared_ptr<Packet0x99> &packet){}
	virtual void processPacket0x9A(std::shared_ptr<Packet0x9A> &packet){}
	virtual void processPacket0xB8(std::shared_ptr<Packet0xB8> &packet){}
	virtual void processPacket0xBB(std::shared_ptr<Packet0xBB> &packet){}
	virtual void processPacket0xBD(std::shared_ptr<Packet0xBD> &packet){}
	virtual void processPacket0xBE(std::shared_ptr<Packet0xBE> &packet){}
	virtual void processPacket0xBF(std::shared_ptr<Packet0xBF> &packet){}
	virtual void processPacket0xC2(std::shared_ptr<Packet0xC2> &packet){}
	virtual void processPacket0xC8(std::shared_ptr<Packet0xC8> &packet){}
	virtual void processPacket0xC9(std::shared_ptr<Packet0xC9> &packet){}
	virtual void processPacket0xCA(std::shared_ptr<Packet0xCA> &packet){}
	virtual void processPacket0xD0(std::shared_ptr<Packet0xD0> &packet){}
	virtual void processPacket0xD1(std::shared_ptr<Packet0xD1> &packet){}
	virtual void processPacket0xD4(std::shared_ptr<Packet0xD4> &packet){}
	virtual void processPacket0xD6(std::shared_ptr<Packet0xD6> &packet){}
	virtual void processPacket0xD7(std::shared_ptr<Packet0xD7> &packet){}
	virtual void processPacket0xF1(std::shared_ptr<Packet0xF1> &packet){}
	
	//----------------- Incoming Packet Processing ---------------
	virtual void processPacket0x00(std::shared_ptr<Packet0x00> &packet){}
	virtual void processPacket0x01(std::shared_ptr<Packet0x01> &packet){}
	virtual void processPacket0x02(std::shared_ptr<Packet0x02> &packet){}
	virtual void processPacket0x03(std::shared_ptr<Packet0x03> &packet){}
	virtual void processPacket0x04(std::shared_ptr<Packet0x04> &packet){}
	virtual void processPacket0x05(std::shared_ptr<Packet0x05> &packet){}
	virtual void processPacket0x06(std::shared_ptr<Packet0x06> &packet){}
	virtual void processPacket0x07(std::shared_ptr<Packet0x07> &packet){}
	virtual void processPacket0x08(std::shared_ptr<Packet0x08> &packet){}
	virtual void processPacket0x09(std::shared_ptr<Packet0x09> &packet){}
	virtual void processPacket0x0A(std::shared_ptr<Packet0x0A> &packet){}
	virtual void processPacket0x12(std::shared_ptr<Packet0x12> &packet){}
	virtual void processPacket0x13(std::shared_ptr<Packet0x13> &packet){}
	virtual void processPacket0x14(std::shared_ptr<Packet0x14> &packet){}
	virtual void processPacket0x1E(std::shared_ptr<Packet0x1E> &packet){}
	virtual void processPacket0x34(std::shared_ptr<Packet0x34> &packet){}
	virtual void processPacket0x35(std::shared_ptr<Packet0x35> &packet){}
	virtual void processPacket0x37(std::shared_ptr<Packet0x37> &packet){}
	virtual void processPacket0x38(std::shared_ptr<Packet0x38> &packet){}
	virtual void processPacket0x3B(std::shared_ptr<Packet0x3B> &packet){}
	virtual void processPacket0x45(std::shared_ptr<Packet0x45> &packet){}
	virtual void processPacket0x46(std::shared_ptr<Packet0x46> &packet){}
	virtual void processPacket0x47(std::shared_ptr<Packet0x47> &packet){}
	virtual void processPacket0x48(std::shared_ptr<Packet0x48> &packet){}
	virtual void processPacket0x49(std::shared_ptr<Packet0x49> &packet){}
	virtual void processPacket0x4A(std::shared_ptr<Packet0x4A> &packet){}
	virtual void processPacket0x4B(std::shared_ptr<Packet0x4B> &packet){}
	virtual void processPacket0x4C(std::shared_ptr<Packet0x4C> &packet){}
	virtual void processPacket0x4D(std::shared_ptr<Packet0x4D> &packet){}
	virtual void processPacket0x50(std::shared_ptr<Packet0x50> &packet){}
	virtual void processPacket0x51(std::shared_ptr<Packet0x51> &packet){}
	virtual void processPacket0x52(std::shared_ptr<Packet0x52> &packet){}
	virtual void processPacket0x57(std::shared_ptr<Packet0x57> &packet){}
	virtual void processPacket0x58(std::shared_ptr<Packet0x58> &packet){}
	virtual void processPacket0x59(std::shared_ptr<Packet0x59> &packet){}
	virtual void processPacket0x5A(std::shared_ptr<Packet0x5A> &packet){}
	virtual void processPacket0x5B(std::shared_ptr<Packet0x5B> &packet){}
	virtual void processPacket0x5C(std::shared_ptr<Packet0x5C> &packet){}
	virtual void processPacket0x5D(std::shared_ptr<Packet0x5D> &packet){}
	virtual void processPacket0x5E(std::shared_ptr<Packet0x5E> &packet){}
	virtual void processPacket0x5F(std::shared_ptr<Packet0x5F> &packet){}
	virtual void processPacket0x60(std::shared_ptr<Packet0x60> &packet){}
	virtual void processPacket0x61(std::shared_ptr<Packet0x61> &packet){}
	virtual void processPacket0x62(std::shared_ptr<Packet0x62> &packet){}
	virtual void processPacket0x63(std::shared_ptr<Packet0x63> &packet){}
	virtual void processPacket0x64(std::shared_ptr<Packet0x64> &packet){}
	virtual void processPacket0x69(std::shared_ptr<Packet0x69> &packet){}
	virtual void processPacket0x75(std::shared_ptr<Packet0x75> &packet){}
	virtual void processPacket0x7D(std::shared_ptr<Packet0x7D> &packet){}
	virtual void processPacket0x80(std::shared_ptr<Packet0x80> &packet){}
	virtual void processPacket0x83(std::shared_ptr<Packet0x83> &packet){}
	virtual void processPacket0x8D(std::shared_ptr<Packet0x8D> &packet){}
	virtual void processPacket0x91(std::shared_ptr<Packet0x91> &packet){}
	virtual void processPacket0x9B(std::shared_ptr<Packet0x9B> &packet){}
	virtual void processPacket0x9F(std::shared_ptr<Packet0x9F> &packet){}
	virtual void processPacket0xA0(std::shared_ptr<Packet0xA0> &packet){}
	virtual void processPacket0xA4(std::shared_ptr<Packet0xA4> &packet){}
	virtual void processPacket0xAC(std::shared_ptr<Packet0xAC> &packet){}
	virtual void processPacket0xAD(std::shared_ptr<Packet0xAD> &packet){}
	virtual void processPacket0xB1(std::shared_ptr<Packet0xB1> &packet){}
	virtual void processPacket0xB3(std::shared_ptr<Packet0xB3> &packet){}
	virtual void processPacket0xB5(std::shared_ptr<Packet0xB5> &packet){}
	virtual void processPacket0xB6(std::shared_ptr<Packet0xB6> &packet){}
	virtual void processPacket0xC5(std::shared_ptr<Packet0xC5> &packet){}
	virtual void processPacket0xD9(std::shared_ptr<Packet0xD9> &packet){}
	virtual void processPacket0xE0(std::shared_ptr<Packet0xE0> &packet){}
	virtual void processPacket0xE1(std::shared_ptr<Packet0xE1> &packet){}
	virtual void processPacket0xEC(std::shared_ptr<Packet0xEC> &packet){}
	virtual void processPacket0xED(std::shared_ptr<Packet0xED> &packet){}
	virtual void processPacket0xEF(std::shared_ptr<Packet0xEF> &packet){}
	virtual void processPacket0xF8(std::shared_ptr<Packet0xF8> &packet){}
	virtual void processPacket0xFA(std::shared_ptr<Packet0xFA> &packet){}
	virtual void processPacket0xFB(std::shared_ptr<Packet0xFB> &packet){}

public:
	PacketHandler() = default;
};

#endif /* PacketHandler_hpp */
