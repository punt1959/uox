


#include "Packet0xA8.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Packet0xA8
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++


//======================================================================
Packet0xA8::Packet0xA8() : Packet(0xa8) {
	_data.resize(6,0) ;
	_data[3] = 0xCC ;
	this->position(6);
	
}

//=====================================================================
void Packet0xA8::finalize(){
	
	Packet::finalize();
}
