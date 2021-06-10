// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#include "Multi.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <filesystem>

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Multi
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
namespace UO {

	const std::string Multi::_uopformat = "build/multicollection/%06d.bin";
	//==============================================================================
	void Multi::processData(std::vector<unsigned char> &data, std::uint32_t chunkid){
		std::list<multi_component> components ;
		std::size_t offset = 4 ;  // skip the first 32 bit word
		auto count = (*reinterpret_cast<std::uint32_t *>((data.data()+offset))) ;;
		
		
		offset = offset + 4 ;
		for (unsigned  int i = 0 ; i < count ; i++){
			multi_component component ;
			
			component.tile  = Tiles::shared().art(*reinterpret_cast<std::uint16_t *>((data.data()+offset))) ;
			offset = offset + 2 ;
			component.xoffset = (*reinterpret_cast<std::int16_t *>((data.data()+offset))) ;
			offset = offset + 2 ;
			component.yoffset = (*reinterpret_cast<std::int16_t *>((data.data()+offset))) ;
			offset = offset + 2 ;
			component.zoffset = (*reinterpret_cast<std::int16_t *>((data.data()+offset))) ;
			offset = offset + 2 ;
			auto flags = (*reinterpret_cast<std::uint16_t *>((data.data()+offset))) ;
			offset = offset + 2 ;
			switch (flags) {
				default:
				case 0: 					// background
					component.component_flag = TileFlag::background ;
					break;
				case 1:					// none
					break;
				case 257:					// generic
					component.component_flag = TileFlag::generic ;
					break;
			}
			auto clilocs = (*reinterpret_cast<std::uint32_t *>((data.data()+offset))) ;
			offset = offset + 4 ;
			if (clilocs != 0 ) {
				offset = offset + (clilocs * 4);
			}
			components.push_back(component);
			
		}
		multi_structure structure ;
		structure.components = components;
		structure.calcOffset();
		_multis.insert_or_assign(chunkid, structure);
	}

	//==============================================================================
	Multi::Multi():UOPData(){
		_mytype=UOPData::multi ;
		_hashformat = _uopformat;
		_maxhashes = 0x10000 ;
	}
	
	//==============================================================================
	Multi::Multi(const std::string &idxfile, const std::string &mulfile):Multi(){
		if (!load(idxfile,mulfile)) {
			throw std::runtime_error(std::string("Failed to load Multis. IDX: ")+idxfile+std::string(" MUL: ")+mulfile);
		}
	}
	
	//==============================================================================
	Multi::Multi(const std::string &uopfile): Multi(){
		if (!load(uopfile)) {
			throw std::runtime_error(std::string("Failed to load Multis. UOP: ")+uopfile);
		}

	}
	
	//==============================================================================
	bool Multi::load(const std::string &idxfile, const std::string &mulfile){
		_multis.clear();
		IDX idx(idxfile);
		std::ifstream input(mulfile,std::ios::in|std::ios::binary);
		if (!input.is_open()){
			throw std::runtime_error(std::string("Unable to open multi mul: ")+mulfile);
		}
		auto useHS = false ;
		auto mulsize = std::filesystem::file_size(std::filesystem::path(mulfile));
		if (mulsize >= hssize) {
			useHS = true ;
		}
		
		std::size_t count = 0 ;
		for (auto &entry : idx.entries()){
		
			if (!entry.valid()){
				count = count + 1 ;
				continue ;
			}
			std::list<multi_component> components ;
			components.clear();
			input.seekg(entry.offset,std::ios::beg);
			auto length = entry.length ;
			while (length >0){
				multi_component item ;
				short temp = 0 ;
				// Read in Tileid
				input.read(reinterpret_cast<char*>(&temp),2);
				item.tile = Tiles::shared().art(static_cast<unsigned short>(temp));
				length = length-2 ;
				// Read in xoffset
				input.read(reinterpret_cast<char*>(&temp),2);
				item.xoffset = temp;
				length = length-2 ;
				
				// Read in yoffset
				input.read(reinterpret_cast<char*>(&temp),2);
				item.yoffset = temp;
				length = length-2 ;

				// Read in zoffset
				input.read(reinterpret_cast<char*>(&temp),2);
				item.zoffset = temp;
				length = length-2 ;
				
				// Read in the flag
				if (useHS){
					unsigned long long dummy ;
					input.read(reinterpret_cast<char*>(&dummy),8);
					length = length - 8;
					item.component_flag = dummy ;
					
				}
				else {
					unsigned int dummy ;
					input.read(reinterpret_cast<char*>(&dummy),4);
					length = length - 4;
					item.component_flag=dummy;

				}
				components.push_back(item);
			}
			multi_structure structure ;
			structure.components = components;
			structure.calcOffset();
			
			_multis.insert_or_assign(count, structure);
			count = count+1 ;
		}
		input.close();
		return true ;
	}
	
	//==============================================================================
	bool Multi::load(const std::string &uopfile){
		_multis.clear();
		std::ifstream input(uopfile,std::ios::in|std::ios::binary);
		if (!input.is_open()){
			return false ;
		}
		
		return loadUOP(input);
	}
	
	//==============================================================================
	bool Multi::exists(std::size_t id){
		auto iter = _multis.find(id) ;
		if (iter != _multis.end()){
			return true ;
		}
		return false;
	}
	
	//==============================================================================
	const multi_structure& Multi::multi(std::size_t id){
		return _multis.at(id);
	}

	//==============================================================================
	std::size_t Multi::size() const{
		return _multis.size();
	}
}
