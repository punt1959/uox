// 
// Created on:  6/6/21

#include "PacketHandler.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "Packet.hpp"
#include "incoming_packets.h"
#include "bidirectional_packets.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for PacketHandler
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//=============================================================================
void PacketHandler::dispatchPacket(std::shared_ptr<Packet> &packet){
	switch (packet->id()) {
			
			//----------------- Bidirectional Packet Processing ---------------
		case 0x0c:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x0C>(packet);
			processPacket0x0C(ptr);
		}
			break;
		case 0x15:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x15>(packet);
			processPacket0x15(ptr);
		}
			break;
		case 0x22:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x22>(packet);
			processPacket0x22(ptr);
		}
			break;
		case 0x2c:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x2C>(packet);
			processPacket0x2C(ptr);
		}
			break;
		case 0x39:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x39>(packet);
			processPacket0x39(ptr);
		}
			break;
		case 0x3a:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x3A>(packet);
			processPacket0x3A(ptr);
		}
			break;
		case 0x56:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x56>(packet);
			processPacket0x56(ptr);
		}
			break;
		case 0x66:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x66>(packet);
			processPacket0x66(ptr);
		}
			break;
		case 0x6c:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x6C>(packet);
			processPacket0x6C(ptr);
		}
			break;
		case 0x6f:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x6F>(packet);
			processPacket0x6F(ptr);
		}
			break;
		case 0x71:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x71>(packet);
			processPacket0x71(ptr);
		}
			break;
		case 0x72:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x72>(packet);
			processPacket0x72(ptr);
		}
			break;
		case 0x73:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x73>(packet);
			processPacket0x73(ptr);
		}
			break;
		case 0x93:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x93>(packet);
			processPacket0x93(ptr);
		}
			break;
		case 0x95:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x95>(packet);
			processPacket0x95(ptr);
		}
			break;
		case 0x98:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x98>(packet);
			processPacket0x98(ptr);
		}
			break;
		case 0x99:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x99>(packet);
			processPacket0x99(ptr);
		}
			break;
		case 0x9a:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x9A>(packet);
			processPacket0x9A(ptr);
		}
			break;
		case 0xb8:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xB8>(packet);
			processPacket0xB8(ptr);
		}
			break;
		case 0xbb:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xBB>(packet);
			processPacket0xBB(ptr);
		}
			break;
		case 0xbd:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xBD>(packet);
			processPacket0xBD(ptr);
		}
			break;
		case 0xbe:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xBE>(packet);
			processPacket0xBE(ptr);
		}
			break;
		case 0xbf:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xBF>(packet);
			processPacket0xBF(ptr);
		}
			break;
		case 0xc2:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xC2>(packet);
			processPacket0xC2(ptr);
		}
			break;
		case 0xc8:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xC8>(packet);
			processPacket0xC8(ptr);
		}
			break;
		case 0xc9:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xC9>(packet);
			processPacket0xC9(ptr);
		}
			break;
		case 0xca:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xCA>(packet);
			processPacket0xCA(ptr);
		}
			break;
		case 0xd0:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xD0>(packet);
			processPacket0xD0(ptr);
		}
			break;
		case 0xd1:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xD1>(packet);
			processPacket0xD1(ptr);
		}
			break;
		case 0xd4:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xD4>(packet);
			processPacket0xD4(ptr);
		}
			break;
		case 0xd6:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xD6>(packet);
			processPacket0xD6(ptr);
		}
			break;
		case 0xd7:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xD7>(packet);
			processPacket0xD7(ptr);
		}
			break;
		case 0xf1:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xF1>(packet);
			processPacket0xF1(ptr);
		}
			break;
			
			//----------------- Incoming Packet Processing ---------------
		case 0x00:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x00>(packet);
			processPacket0x00(ptr);
		}
			break;
		case 0x01:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x01>(packet);
			processPacket0x01(ptr);
		}
			break;
		case 0x02:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x02>(packet);
			processPacket0x02(ptr);
		}
			break;
		case 0x03:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x03>(packet);
			processPacket0x03(ptr);
		}
			break;
		case 0x04:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x04>(packet);
			processPacket0x04(ptr);
		}
			break;
		case 0x05:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x05>(packet);
			processPacket0x05(ptr);
		}
			break;
		case 0x06:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x06>(packet);
			processPacket0x06(ptr);
		}
			break;
		case 0x07:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x07>(packet);
			processPacket0x07(ptr);
		}
			break;
		case 0x08:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x08>(packet);
			processPacket0x08(ptr);
		}
			break;
		case 0x09:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x09>(packet);
			processPacket0x09(ptr);
		}
			break;
		case 0x0a:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x0A>(packet);
			processPacket0x0A(ptr);
		}
			break;
		case 0x12:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x12>(packet);
			processPacket0x12(ptr);
		}
			break;
		case 0x13:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x13>(packet);
			processPacket0x13(ptr);
		}
			break;
		case 0x14:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x14>(packet);
			processPacket0x14(ptr);
		}
			break;
		case 0x1e:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x1E>(packet);
			processPacket0x1E(ptr);
		}
			break;
		case 0x34:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x34>(packet);
			processPacket0x34(ptr);
		}
			break;
		case 0x35:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x35>(packet);
			processPacket0x35(ptr);
		}
			break;
		case 0x37:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x37>(packet);
			processPacket0x37(ptr);
		}
			break;
		case 0x38:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x38>(packet);
			processPacket0x38(ptr);
		}
			break;
		case 0x3b:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x3B>(packet);
			processPacket0x3B(ptr);
		}
			break;
		case 0x45:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x45>(packet);
			processPacket0x45(ptr);
		}
			break;
		case 0x46:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x46>(packet);
			processPacket0x46(ptr);
		}
			break;
		case 0x47:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x47>(packet);
			processPacket0x47(ptr);
		}
			break;
		case 0x48:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x48>(packet);
			processPacket0x48(ptr);
		}
			break;
		case 0x49:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x49>(packet);
			processPacket0x49(ptr);
		}
			break;
		case 0x4a:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x4A>(packet);
			processPacket0x4A(ptr);
		}
			break;
		case 0x4b:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x4B>(packet);
			processPacket0x4B(ptr);
		}
			break;
		case 0x4c:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x4C>(packet);
			processPacket0x4C(ptr);
		}
			break;
		case 0x4d:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x4D>(packet);
			processPacket0x4D(ptr);
		}
			break;
		case 0x50:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x50>(packet);
			processPacket0x50(ptr);
		}
			break;
		case 0x51:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x51>(packet);
			processPacket0x51(ptr);
		}
			break;
		case 0x52:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x52>(packet);
			processPacket0x52(ptr);
		}
			break;
		case 0x57:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x57>(packet);
			processPacket0x57(ptr);
		}
			break;
		case 0x58:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x58>(packet);
			processPacket0x58(ptr);
		}
			break;
		case 0x59:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x59>(packet);
			processPacket0x59(ptr);
		}
			break;
		case 0x5a:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x5A>(packet);
			processPacket0x5A(ptr);
		}
			break;
		case 0x5b:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x5B>(packet);
			processPacket0x5B(ptr);
		}
			break;
		case 0x5c:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x5C>(packet);
			processPacket0x5C(ptr);
		}
			break;
		case 0x5d:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x5D>(packet);
			processPacket0x5D(ptr);
		}
			break;
		case 0x5e:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x5E>(packet);
			processPacket0x5E(ptr);
		}
			break;
		case 0x5f:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x5F>(packet);
			processPacket0x5F(ptr);
		}
			break;
		case 0x60:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x60>(packet);
			processPacket0x60(ptr);
		}
			break;
		case 0x61:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x61>(packet);
			processPacket0x61(ptr);
		}
			break;
		case 0x62:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x62>(packet);
			processPacket0x62(ptr);
		}
			break;
		case 0x63:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x63>(packet);
			processPacket0x63(ptr);
		}
			break;
		case 0x64:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x64>(packet);
			processPacket0x64(ptr);
		}
			break;
		case 0x69:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x69>(packet);
			processPacket0x69(ptr);
		}
			break;
		case 0x75:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x75>(packet);
			processPacket0x75(ptr);
		}
			break;
		case 0x7d:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x7D>(packet);
			processPacket0x7D(ptr);
		}
			break;
		case 0x80:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x80>(packet);
			processPacket0x80(ptr);
		}
			break;
		case 0x83:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x83>(packet);
			processPacket0x83(ptr);
		}
			break;
		case 0x8d:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x8D>(packet);
			processPacket0x8D(ptr);
		}
			break;
		case 0x91:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x91>(packet);
			processPacket0x91(ptr);
		}
			break;
		case 0x9b:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x9B>(packet);
			processPacket0x9B(ptr);
		}
			break;
		case 0x9f:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0x9F>(packet);
			processPacket0x9F(ptr);
		}
			break;
		case 0xa0:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xA0>(packet);
			processPacket0xA0(ptr);
		}
			break;
		case 0xa4:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xA4>(packet);
			processPacket0xA4(ptr);
		}
			break;
		case 0xac:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xAC>(packet);
			processPacket0xAC(ptr);
		}
			break;
		case 0xad:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xAD>(packet);
			processPacket0xAD(ptr);
		}
			break;
		case 0xb1:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xB1>(packet);
			processPacket0xB1(ptr);
		}
			break;
		case 0xb3:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xB3>(packet);
			processPacket0xB3(ptr);
		}
			break;
		case 0xb5:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xB5>(packet);
			processPacket0xB5(ptr);
		}
			break;
		case 0xb6:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xB6>(packet);
			processPacket0xB6(ptr);
		}
			break;
		case 0xc5:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xC5>(packet);
			processPacket0xC5(ptr);
		}
			break;
		case 0xd9:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xD9>(packet);
			processPacket0xD9(ptr);
		}
			break;
		case 0xe0:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xE0>(packet);
			processPacket0xE0(ptr);
		}
			break;
		case 0xe1:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xE1>(packet);
			processPacket0xE1(ptr);
		}
			break;
		case 0xec:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xEC>(packet);
			processPacket0xEC(ptr);
		}
			break;
		case 0xed:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xED>(packet);
			processPacket0xED(ptr);
		}
			break;
		case 0xef:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xEF>(packet);
			processPacket0xEF(ptr);
		}
			break;
		case 0xf8:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xF8>(packet);
			processPacket0xF8(ptr);
		}
			break;
		case 0xfa:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xFA>(packet);
			processPacket0xFA(ptr);
		}
			break;
		case 0xfb:
		{
			auto ptr = std::dynamic_pointer_cast<Packet0xFB>(packet);
			processPacket0xFB(ptr);
		}
			break;
	}
}

//==========================================================================
void PacketHandler::appendPackets(std::queue<std::shared_ptr<Packet>> &incoming) {
	while (!incoming.empty()){
		auto value = incoming.front();
		incoming.pop();
		_pending.push_back(value);
	}
}

//----------------------- Default Packet handling -----------------------------
//==========================================================================
