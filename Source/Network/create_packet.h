#include "incoming_packets.h"
#include "outgoing_packets.h"
#include "bidirectional_packets.h"

//==============================================================================
std::shared_ptr<Packet> Packet::createPacket(unsigned char id){
	try {
		auto info = Packet::Packet::infoPacket(id); // Just to figure the catch for unknown packets
	}
	catch(...){
		return std::make_shared<Packet>(id);
	}
	switch( id ) {
			
			//-------------------- Bidrectional ----------------------------
			
		case 0x0c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x0C>());
			break;
		case 0x15:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x15>());
			break;
		case 0x22:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x22>());
			break;
		case 0x2c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x2C>());
			break;
		case 0x39:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x39>());
			break;
		case 0x3a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x3A>());
			break;
		case 0x56:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x56>());
			break;
		case 0x66:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x66>());
			break;
		case 0x6c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x6C>());
			break;
		case 0x6f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x6F>());
			break;
		case 0x71:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x71>());
			break;
		case 0x72:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x72>());
			break;
		case 0x73:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x73>());
			break;
		case 0x93:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x93>());
			break;
		case 0x95:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x95>());
			break;
		case 0x98:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x98>());
			break;
		case 0x99:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x99>());
			break;
		case 0x9a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x9A>());
			break;
		case 0xb8:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB8>());
			break;
		case 0xbb:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xBB>());
			break;
		case 0xbd:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xBD>());
			break;
		case 0xbe:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xBE>());
			break;
		case 0xbf:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xBF>());
			break;
		case 0xc2:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC2>());
			break;
		case 0xc8:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC8>());
			break;
		case 0xc9:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC9>());
			break;
		case 0xca:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xCA>());
			break;
		case 0xd0:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD0>());
			break;
		case 0xd1:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD1>());
			break;
		case 0xd4:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD4>());
			break;
		case 0xd6:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD6>());
			break;
		case 0xd7:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD7>());
			break;
		case 0xf1:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xF1>());
			break;
			
			//-------------------- Incoming ----------------------------
			
		case 0x00:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x00>());
			break;
		case 0x01:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x01>());
			break;
		case 0x02:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x02>());
			break;
		case 0x03:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x03>());
			break;
		case 0x04:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x04>());
			break;
		case 0x05:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x05>());
			break;
		case 0x06:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x06>());
			break;
		case 0x07:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x07>());
			break;
		case 0x08:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x08>());
			break;
		case 0x09:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x09>());
			break;
		case 0x0a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x0A>());
			break;
		case 0x12:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x12>());
			break;
		case 0x13:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x13>());
			break;
		case 0x14:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x14>());
			break;
		case 0x1e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x1E>());
			break;
		case 0x34:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x34>());
			break;
		case 0x35:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x35>());
			break;
		case 0x37:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x37>());
			break;
		case 0x38:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x38>());
			break;
		case 0x3b:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x3B>());
			break;
		case 0x45:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x45>());
			break;
		case 0x46:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x46>());
			break;
		case 0x47:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x47>());
			break;
		case 0x48:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x48>());
			break;
		case 0x49:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x49>());
			break;
		case 0x4a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x4A>());
			break;
		case 0x4b:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x4B>());
			break;
		case 0x4c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x4C>());
			break;
		case 0x4d:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x4D>());
			break;
		case 0x50:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x50>());
			break;
		case 0x51:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x51>());
			break;
		case 0x52:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x52>());
			break;
		case 0x57:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x57>());
			break;
		case 0x58:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x58>());
			break;
		case 0x59:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x59>());
			break;
		case 0x5a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x5A>());
			break;
		case 0x5b:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x5B>());
			break;
		case 0x5c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x5C>());
			break;
		case 0x5d:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x5D>());
			break;
		case 0x5e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x5E>());
			break;
		case 0x5f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x5F>());
			break;
		case 0x60:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x60>());
			break;
		case 0x61:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x61>());
			break;
		case 0x62:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x62>());
			break;
		case 0x63:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x63>());
			break;
		case 0x64:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x64>());
			break;
		case 0x69:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x69>());
			break;
		case 0x75:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x75>());
			break;
		case 0x7d:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x7D>());
			break;
		case 0x80:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x80>());
			break;
		case 0x83:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x83>());
			break;
		case 0x8d:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x8D>());
			break;
		case 0x91:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x91>());
			break;
		case 0x9b:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x9B>());
			break;
		case 0x9f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x9F>());
			break;
		case 0xa0:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA0>());
			break;
		case 0xa4:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA4>());
			break;
		case 0xac:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xAC>());
			break;
		case 0xad:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xAD>());
			break;
		case 0xb1:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB1>());
			break;
		case 0xb3:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB3>());
			break;
		case 0xb5:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB5>());
			break;
		case 0xb6:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB6>());
			break;
		case 0xc5:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC5>());
			break;
		case 0xd9:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD9>());
			break;
		case 0xe0:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xE0>());
			break;
		case 0xe1:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xE1>());
			break;
		case 0xec:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xEC>());
			break;
		case 0xed:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xED>());
			break;
		case 0xef:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xEF>());
			break;
		case 0xf8:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xF8>());
			break;
		case 0xfa:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xFA>());
			break;
		case 0xfb:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xFB>());
			break;
			
			//-------------------- Outgoing ----------------------------
			
		case 0x11:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x11>());
			break;
		case 0x16:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x16>());
			break;
		case 0x17:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x17>());
			break;
		case 0x1a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x1A>());
			break;
		case 0x1b:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x1B>());
			break;
		case 0x1c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x1C>());
			break;
		case 0x1d:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x1D>());
			break;
		case 0x1f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x1F>());
			break;
		case 0x20:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x20>());
			break;
		case 0x21:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x21>());
			break;
		case 0x23:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x23>());
			break;
		case 0x24:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x24>());
			break;
		case 0x25:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x25>());
			break;
		case 0x26:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x26>());
			break;
		case 0x27:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x27>());
			break;
		case 0x28:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x28>());
			break;
		case 0x29:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x29>());
			break;
		case 0x2a:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x2A>());
			break;
		case 0x2b:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x2B>());
			break;
		case 0x2d:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x2D>());
			break;
		case 0x2e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x2E>());
			break;
		case 0x2f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x2F>());
			break;
		case 0x30:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x30>());
			break;
		case 0x31:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x31>());
			break;
		case 0x32:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x32>());
			break;
		case 0x33:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x33>());
			break;
		case 0x36:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x36>());
			break;
		case 0x3c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x3C>());
			break;
		case 0x3e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x3E>());
			break;
		case 0x3f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x3F>());
			break;
		case 0x4e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x4E>());
			break;
		case 0x4f:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x4F>());
			break;
		case 0x53:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x53>());
			break;
		case 0x54:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x54>());
			break;
		case 0x55:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x55>());
			break;
		case 0x65:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x65>());
			break;
		case 0x6e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x6E>());
			break;
		case 0x70:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x70>());
			break;
		case 0x74:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x74>());
			break;
		case 0x76:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x76>());
			break;
		case 0x77:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x77>());
			break;
		case 0x78:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x78>());
			break;
		case 0x7c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x7C>());
			break;
		case 0x82:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x82>());
			break;
		case 0x86:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x86>());
			break;
		case 0x88:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x88>());
			break;
		case 0x89:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x89>());
			break;
		case 0x8c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x8C>());
			break;
		case 0x90:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x90>());
			break;
		case 0x97:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x97>());
			break;
		case 0x9c:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x9C>());
			break;
		case 0x9e:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0x9E>());
			break;
		case 0xa1:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA1>());
			break;
		case 0xa2:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA2>());
			break;
		case 0xa3:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA3>());
			break;
		case 0xa5:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA5>());
			break;
		case 0xa8:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA8>());
			break;
		case 0xa9:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xA9>());
			break;
		case 0xaa:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xAA>());
			break;
		case 0xab:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xAB>());
			break;
		case 0xae:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xAE>());
			break;
		case 0xaf:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xAF>());
			break;
		case 0xb0:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB0>());
			break;
		case 0xb2:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB2>());
			break;
		case 0xb7:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB7>());
			break;
		case 0xb9:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xB9>());
			break;
		case 0xba:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xBA>());
			break;
		case 0xbc:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xBC>());
			break;
		case 0xc0:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC0>());
			break;
		case 0xc1:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC1>());
			break;
		case 0xc4:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC4>());
			break;
		case 0xc6:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC6>());
			break;
		case 0xc7:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xC7>());
			break;
		case 0xcb:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xCB>());
			break;
		case 0xcc:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xCC>());
			break;
		case 0xd2:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD2>());
			break;
		case 0xd3:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD3>());
			break;
		case 0xd8:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xD8>());
			break;
		case 0xdb:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xDB>());
			break;
		case 0xdd:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xDD>());
			break;
		case 0xde:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xDE>());
			break;
		case 0xdf:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xDF>());
			break;
		case 0xe2:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xE2>());
			break;
		case 0xe3:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xE3>());
			break;
		case 0xf0:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xF0>());
			break;
		case 0xf3:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xF3>());
			break;
		case 0xf5:
			return std::static_pointer_cast<Packet>(std::make_shared<Packet0xF5>());
			break;
			
			
			
	}
	return std::make_shared<Packet>(id);
}
