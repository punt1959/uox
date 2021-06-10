// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  5/24/21

#ifndef Buffer_hpp
#define Buffer_hpp

#include <cstdint>
#include <string>
#include <cstring>
#include <vector>
class Buffer {
protected:
	std::vector<unsigned char> _data ;
	std::size_t _current ;
	bool _auto_resize ;

	std::size_t calcPos(std::size_t pos,std::size_t size);
	bool overflow(std::size_t pos, std::size_t size);

public:
	Buffer(std::size_t capacity = 0);
	bool autoResize() const ;
	void autoResize(bool value);
	std::size_t size() const ;
	void size(std::size_t value) ;
	std::size_t position() const ;
	void position(std::size_t value);
	template<typename T>
	T read(std::size_t offset = SIZE_MAX){
		auto amount = sizeof(T) ;
		offset = calcPos(offset, amount);
		if (overflow(offset, amount)) {
			throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(offset)+std::string(",")+std::to_string(amount)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
			
		}
		return *reinterpret_cast<T*>(_data.data()+offset);
	}
	
	template<typename T>
	void write(T &data,std::size_t offset = SIZE_MAX){
		auto amount = sizeof(T) ;
		offset = calcPos(offset, amount);
		if (overflow(offset, amount)) {
			throw std::out_of_range(std::string("Position,Amount: ")+std::to_string(offset)+std::string(",")+std::to_string(amount)+std::string(" exceeds size of buffer: ") + std::to_string(_data.size()));
		}

		std::memcpy(_data.data()+offset,reinterpret_cast<unsigned char*>(&data) , amount);
	}
	
	void read(char *values, std::size_t amount, std::size_t offset = -1);
	void write(char *values, std::size_t amount, std::size_t offset = -1);
	std::string readString(std::size_t amount=0, std::size_t offset=-1);
	void writeString(const std::string &value, std::size_t amount=0, std::size_t offset = -1);
	
	std::string description() const ;
	
	std::vector<unsigned char> rawData() const ;

};

#endif /* Buffer_hpp */
