// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  5/24/21

#include "Buffer.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cctype>
#include "StringUtility.hpp"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Buffer
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//=========================================================
std::size_t Buffer::calcPos(std::size_t pos,std::size_t size){
	if (pos == SIZE_MAX) {
		pos = _current ;
		_current = _current + size ;
	}
	return pos ;
}
//=========================================================
bool Buffer::overflow(std::size_t pos, std::size_t size){
	if (!_auto_resize){
		return ((pos+size) > _data.size()) ;
	}
	else {
		if (_data.size() < (pos + size)) {
			auto value = (pos+size) - _data.size();
			if (value > 0) {
				_data.resize(_data.size()+value,0);
			}

		}
		return false ;
	}
}

//=========================================================
Buffer::Buffer(std::size_t capacity){
	_data.resize(capacity,0);
	_current = 0 ;
	_auto_resize = false ;
}
//=========================================================
bool Buffer::autoResize() const {
	return _auto_resize;
}
//=========================================================
void Buffer::autoResize(bool value){
	_auto_resize = value ;
}

//=========================================================
std::size_t Buffer::size() const {
	return _data.size();
}
//=========================================================
void Buffer::size(std::size_t value){
	_data.resize(value,0);
}
//=========================================================
std::size_t Buffer::position() const {
	return _current;
}
//=========================================================
void Buffer::position(std::size_t value) {
	if (value > _data.size()) {
		throw std::out_of_range(std::string("Position: ")+std::to_string(value)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
	}
	_current = value ;
}
//=========================================================
void Buffer::read(char *values, std::size_t amount, std::size_t offset ){
	offset = calcPos(offset, amount);
	if (overflow(offset, amount)) {
		throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(offset)+std::string(",")+std::to_string(amount)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));

	}
	std::copy(_data.data()+offset,_data.data()+offset+amount,values);
}
//=========================================================
void Buffer::write(char *values, std::size_t amount, std::size_t offset){
	offset = calcPos(offset, amount);
	if (overflow(offset, amount)) {
		throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(offset)+std::string(",")+std::to_string(amount)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
		
	}

	std::copy(values,values+amount,_data.data()+offset);
}

//=========================================================
std::string Buffer::readString(std::size_t amount, std::size_t offset){
	if (amount > 0) {
		offset = calcPos(offset, amount);
		return std::string(reinterpret_cast<char*>(_data.data()+offset),amount);
	}
	else {
		auto delta = offset ;
		if (offset == -1) {
			delta = _current ;
		}
		auto loc = std::find(_data.begin()+delta,_data.end(),0);
		amount = std::distance(_data.begin()+delta, loc) + 1;
		calcPos(offset, amount);

		if (overflow(delta, amount)) {
			throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(delta)+std::string(",")+std::to_string(amount)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
			
		}
		if (amount == 1) {
			return std::string() ;
		}
		std::vector<char> temp(_data.begin()+delta,loc);
		if (loc == _data.end()) {
			temp.push_back(0); // null terminate
		}
		return std::string(temp.data());
		
	}
}
//=========================================================
void Buffer::writeString(const std::string &value, std::size_t amount, std::size_t offset ){
	if (amount > 0) {
		offset = calcPos(offset, amount);
		if (overflow(offset, amount)) {
			throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(offset)+std::string(",")+std::to_string(amount)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
			
		}

		if (value.size()> amount) {
			std::copy(value.c_str(),value.c_str()+amount,_data.begin()+offset);
		}
		else {
			std::copy(value.begin(),value.end(),_data.begin()+offset);
			
			std::fill(_data.begin()+offset+value.size(), _data.begin()+offset+amount, 0);
		}
	}
	else {
		auto size = value.size()+1 ; // (null terminate)
		offset = calcPos(offset, size) ;
		if (overflow(offset, size)) {
			throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(offset)+std::string(",")+std::to_string(size)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
			
		}
		std::memcpy(_data.data()+offset, value.c_str(), size);
		
	}
}

//======================================================================
std::string Buffer::description() const {
	auto size = static_cast<int>(_data.size()) ;
	const int rowsize = 10 ;
	
	std::stringstream output ;
	auto index = 0 ;
	auto amount = rowsize ;
	bool notfirst = false ;
	output << "\n          " ;
	
	for (auto i = 0 ; i < rowsize;i++){
		output << strutil::format("%2d  ",i);
	}
	output << "\n          " ;

	for (auto i = 0 ; i < rowsize;i++){
		output << "--  ";
	}
	output << "\n";
	while (size> 0) {
		if (notfirst){
			output << "\n";
		}
		output << strutil::format("%05i:    ",(index/rowsize)*rowsize);
		auto delta = size - amount ;
		if (delta < 0) {
			amount = amount + delta ;  // Plus because delta is negative
		}
		std::stringstream text ;

		for (auto i = 0 ; i < amount ; i++){
			output << strutil::format("%02x  ",_data[index]);
			if (std::isalpha(static_cast<char>(_data[index]))!= 0){
				text << strutil::format("%c",static_cast<char>(_data[index])) ;
			}
			else {
				text << "." ;
			}
			index++ ;
			size-- ;
		}
		if (amount < rowsize) {
			for (auto i = amount ; i<rowsize; i++){
				output << "    ";
			}
		}
		output << "   " << text.str() ;
		
		
		notfirst = true ;

	}
	

	return output.str();
}

//===========================================================================
std::vector<unsigned char> Buffer::rawData() const {
	return _data;
}
