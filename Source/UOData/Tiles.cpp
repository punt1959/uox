// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  5/31/21

#include "Tiles.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include <filesystem>

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Tiles
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
namespace UO {
	
	//============================================================================
	Tiles::Tiles(const std::string& filename){
		_usingHS=false ;
		load(filename);
	}
	//============================================================================
	std::vector<std::shared_ptr<Art_Tile>> Tiles::loadArt(std::ifstream& input, bool useHS){
		std::vector<std::shared_ptr<Art_Tile>> rvalue ;
		rvalue.reserve(0xFFFE) ;
		unsigned short tileid = 0 ;
		do {
			unsigned int dummy ;
			unsigned long long dummy64 ;

			if (input.eof()) {
				break;
			}
			if ( (tileid & 0x1f) == 0) {
				input.read(reinterpret_cast<char*>(&dummy),4); // read off the group header
			}
			auto entry = std::make_shared<Art_Tile>(tileid);
			if (useHS) {
				input.read(reinterpret_cast<char*>(&dummy64),8);
				entry->flag = dummy64;
				
			}
			else {
				input.read(reinterpret_cast<char*>(&dummy),4);
				entry->flag = static_cast<unsigned long long>(dummy);
				
			}
			unsigned char  dum8 ;
			unsigned short val ;
			
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->weight = dum8;
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->quality = dum8 ;
			//first unkown
			input.read(reinterpret_cast<char*>(&val),2);
			entry->unknown0 = val ;
			//Second unkown
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->unknown1 = dum8 ;
			// Quantity
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->quantity = dum8;
			// Animation
			input.read(reinterpret_cast<char*>(&val),2);
			entry->animation = val ;
			
			//Third a byte
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->unknown2 = dum8 ;

			// Hue/Value
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->hue_value = dum8;
			//Fourth unknown
			input.read(reinterpret_cast<char*>(&val),2);
			entry->unknown3 = val ;
			// Height
			input.read(reinterpret_cast<char*>(&dum8),1);
			entry->height = dum8 ;
			// Name
			char buf[21] ;
			input.read(buf,20);
			buf[input.gcount()]=0 ;
			entry->name = std::string(buf);
			if (input.good()){
				rvalue.push_back(entry);
			}
			
			tileid = tileid + 1;
		}while ( (!input.eof()) && (input.good()) );

		return rvalue;
	}
	//============================================================================
	std::vector<std::shared_ptr<Land_Tile>> Tiles::loadLand(std::ifstream& input, bool useHS){
		std::vector<std::shared_ptr<Land_Tile>> rvalue ;
		rvalue.reserve(0x4000);
		unsigned int dummy =0;
		unsigned long long dummy64 =0;
		
		for (auto i = 0 ; i < 0x4000; i++){
			if (useHS) {
				if ( (((i & 0x1F)==0) && (i>0)) || (i == 1)){
					input.read(reinterpret_cast<char*>(&dummy),4); // read off the group header
				}
			}
			else {
				if ( (i & 0x1f) == 0) {
					input.read(reinterpret_cast<char*>(&dummy),4); // read off the group header
				}
			}
			auto land = std::make_shared<Land_Tile>(static_cast<unsigned short>(i));
			
			if (useHS) {
				input.read(reinterpret_cast<char*>(&dummy64),8);
				land->flag = dummy64 ;
				
			}
			
			else{
				input.read(reinterpret_cast<char*>(&dummy),4);
				land->flag = dummy ;
			}
			unsigned short texid =0;
			input.read(reinterpret_cast<char*>(&texid),2);
			land->texture = texid;
			char buf[21] ;
			input.read(buf,20);
			buf[input.gcount()]=0 ;
			land->name = std::string(buf) ;
			
			rvalue.push_back(land);
			
		}
		return rvalue;	}

	//============================================================================
	Tiles& Tiles::shared(const std::string& filename){
		static Tiles instance(filename);
		return instance ;
	}
	//============================================================================
	void Tiles::load(const std::string& filename){
		if (!filename.empty()){
			auto size = std::filesystem::file_size(std::filesystem::path(filename));
			auto useHS = false ;
			if (size >= sizeForHS){
				useHS = true ;
			}
			_usingHS=useHS ;
			
			std::ifstream input(filename,std::ios::in|std::ios::binary);
			if (!input.is_open()){
				throw std::runtime_error(std::string("Unable to open Tile file: ")+filename);
			}
			
			_land = loadLand(input, useHS);
			_art = loadArt(input, useHS);
			input.close();
		}
	}
	//============================================================================
	std::size_t Tiles::maxLand() const{
		return _land.size();
	}
	//============================================================================
	std::size_t Tiles::maxTile() const{
		return _art.size();
	}
	//============================================================================
	std::shared_ptr<Land_Tile> Tiles::land(std::size_t tileid) const{
		try {
			return _land.at(tileid) ;
		}
		catch(...){
			return nullptr ;
		}
	}
	//============================================================================
	std::shared_ptr<Art_Tile> Tiles::art(std::size_t tileid) const {
		try {
			return _art.at(tileid) ;
		}
		catch(...){
			return nullptr ;
		}

	}
}
