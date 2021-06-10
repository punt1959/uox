// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  5/25/21

#include "Packet.hpp"
#include "ConfigOS.h"
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <sstream>

#if PLATFORM == MACOS
#include <zlib.h>
#else
#include "zlib.h"
#endif
#include "StringUtility.hpp"
#include "TimeUtility.hpp"

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Packet
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
#include "packet_sizes.h"    // Get our packet sizes
//======================================================================
Packet::Packet(unsigned char id) : Buffer(){
	_id = id ;
	
	try {
		auto info = infoPacket(_id) ;
		_name = std::get<1>(info) ;
		auto amount  = std::get<0>(info) ;
		if (amount != 0xFFFF) {
			this->_data.resize(amount,0);
			_variable = false;
			position(1);
			
		}
		else {
			this->_data.resize(3,0);
			_variable = true ;
			position(3);
		}
		this->write(_id) ;
		_creation_time = timeutil::timenow();
	}
	catch(...) {
		_name = "NOT IN PACKET TABLE";
		this->_data.resize(3,0);
		_variable = true ;
		this->write(_id) ;
		_creation_time = timeutil::timenow();
		
	}
	
}

//======================================================================
unsigned char Packet::id() const {
	return _id ;
}

//======================================================================
std::tuple<unsigned short, std::string> Packet::infoPacket(unsigned char packetid){
	try{
		auto info = _packet_info.at(packetid) ;
		return std::make_tuple(info.size,info.name);
	}
	catch(...){
		// The packet wasn't in our list! Totally unkown
		auto packid = strutil::format("0x%2u",static_cast<unsigned short>(packetid));
		throw std::out_of_range(std::string("Packet info was not found: ")+std::to_string(static_cast<unsigned short>(packetid)));
	}
}
//======================================================================
std::vector<unsigned char> Packet::applyHuffman() const {
	std::vector<unsigned char> rvalue ;
	rvalue.reserve(_data.size() * 3);
	rvalue.resize(_data.size()*2, 0) ;
	
	std::size_t packedLength = 0;
	unsigned int bitByte = 0;
	unsigned int nrBits;
	unsigned int value ;
	auto len = _data.size() ;
	auto pIn = _data.data() ;
	while( len> 0 )
	{
		nrBits = huffman_table[*pIn][0];
		value	= huffman_table[*pIn++][1];
		
		while( nrBits-- )
		{
			rvalue[packedLength] = static_cast<unsigned char>((rvalue[packedLength] << 1) | ((value >> nrBits) & 0x1));
			
			bitByte = (bitByte + 1) & 0x07;
			if( !bitByte ){
				++packedLength;
				if (rvalue.size() <= packedLength) {
					rvalue.resize(rvalue.size()*2);
				}
			}
		}
		len = len - 1;
	}
	
	nrBits	= huffman_table[256][0];
	value	= huffman_table[256][1];
	
	while( nrBits-- )
	{
		rvalue[packedLength] = static_cast<unsigned char>((rvalue[packedLength] << 1) | ((value >> nrBits) & 0x1));
		
		bitByte = (bitByte + 1) & 0x07;
		if( !bitByte ){
			++packedLength;
			if (rvalue.size() <= packedLength) {
				rvalue.resize(rvalue.size()*2);
			}
		}
	}
	
	if( bitByte )
	{
		while( bitByte < 8 )
		{
			rvalue[packedLength] <<= 1;
			++bitByte;
		}
		++packedLength;
	}
	rvalue.resize(packedLength);
	return rvalue ;
}

//===============================================================
void Packet::zip(std::vector<unsigned char> &source, std::vector<unsigned char> &dest) {
	auto destsize = static_cast<unsigned long>(dest.size());
	auto srcsize = static_cast<unsigned long>(source.size()) ;
	
	auto status = compress2(dest.data(), &destsize, source.data(), srcsize, Z_DEFAULT_COMPRESSION);
	if (status != Z_OK){
		throw std::runtime_error(std::string("Error Packet zlib compress: ")+ std::to_string(status));
	}
}

//===============================================================
std::string Packet::description() const {
	std::stringstream output ;
	auto title = strutil::format("Created: %s | Packet: 0x%02X | Size: %d: | %s ",_creation_time.c_str(),static_cast<unsigned short>(_id),_data.size(),_name.c_str());
	output << title << "\n" << _buffer_description<<"\n";
	return output.str() ;
}

//===============================================================
std::size_t Packet::size() {
	return _data.size();
}

//===============================================================
unsigned char * Packet::data() {
	return _data.data();
}

//===============================================================
void Packet::finalize(){
	if (_variable) {
		auto size = static_cast<unsigned short>(_data.size()) ;
		*reinterpret_cast<unsigned short*>(_data.data()+1) = size ;
	}
	_buffer_description = Buffer::description();
	position(0);
}

//==============================================================================
// Include the file for createPacket
#include "create_packet.h"

