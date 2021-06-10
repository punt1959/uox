// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#include "IDX.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <filesystem>
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for IDX
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
namespace UO {
	//========================================================================
	IDX::IDX(const std::string &filename){
		if (!filename.empty()){
			load(filename);
		}
	}
	//========================================================================
	void IDX::load(const std::string &filename){
		if (filename.empty()){
			throw std::runtime_error(std::string("No IDX file specified"));
		}
		_entries.clear() ;
		auto size = std::filesystem::file_size(std::filesystem::path(filename));
		_entries.reserve(size/12);
		std::ifstream input(filename, std::ios::in|std::ios::binary);
		if (!input.is_open()){
			throw std::runtime_error(std::string("Unable to open IDX file: ")+filename);
		}
		unsigned int data = 0 ;
		while (!input.eof() && input.good()){
			idxentry entry ;
			input.read(reinterpret_cast<char*>(&data),4);
			if (input.gcount()!=4){
				break;
			}
			entry.offset = data ;
			input.read(reinterpret_cast<char*>(&data),4);
			entry.length = data ;
			input.read(reinterpret_cast<char*>(&data),4);
			entry.extra = data ;
			_entries.push_back(entry);
		}
		input.close();
	}
	//========================================================================
	std::size_t IDX::maxEntry() const {
		return _entries.size();
	}
	//========================================================================
	const std::vector<UO::idxentry>& IDX::entries() const{
		return _entries;
	}
	//========================================================================
	const UO::idxentry& IDX::entry(std::size_t id)const {
		return _entries.at(id) ;
	}
	
}
