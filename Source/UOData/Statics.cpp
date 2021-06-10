// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#include "Statics.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include "Tiles.hpp"
#include "IDX.hpp"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Statics
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
namespace UO {
	
	//==============================================================================
	std::list<mapstatic_tile> Statics::processBlock(int blockid, std::vector<unsigned char> &rawdata){
		auto base = baseXY(blockid) ;
		auto size = rawdata.size() ;
		std::size_t offset = 0 ;
		std::list<mapstatic_tile> rvalue ;
		unsigned short tileid = 0 ;
		while (size > 0){
			tileid = *(reinterpret_cast<unsigned short*>(rawdata.data()+offset)) ;
			offset = offset + 2 ;
			size = size -2 ;
			auto x = *(rawdata.data()+offset) ;
			offset = offset + 1 ;
			size = size -1 ;
			auto y = *(rawdata.data()+offset) ;
			offset = offset + 1 ;
			size = size -1 ;
			auto z = *(reinterpret_cast<char*>(rawdata.data()+offset)) ;
			offset = offset + 1 ;
			size = size -1 ;
			// we dont need the hue
			offset = offset + 2 ;
			size = size - 2;
			mapstatic_tile entry ;
			entry.xloc = std::get<0>(base) + x ;
			entry.yloc = std::get<1>(base) + y ;
			entry.altitude = z ;
			entry.tile = Tiles::shared().art(tileid);
			
			
			rvalue.push_back(entry);
		}
		return rvalue ;
	}

	//==============================================================================
	Statics::Statics(int mapnum,const std::string &idxfile,const std::string &mulfile,int cellX,int cellY):  BaseMap(mapnum,cellX,cellY){
		
		
		if (!idxfile.empty() && !mulfile.empty()) {
			load(idxfile,mulfile,mapnum);
		}
	}
	//==============================================================================
	void Statics::load(const std::string &idxfile,const std::string &mulfile,int mapnum ,int cellX,int cellY ){
		setMap(mapnum,cellX,cellY);
		_data.clear();
		IDX index(idxfile) ;
		int count = 0 ;
		std::ifstream input(mulfile,std::ios::in|std::ios::binary);
		if (!input.is_open()){
			throw std::runtime_error(std::string("Unable to open static file: ")+mulfile);
		}
		for (auto &entry: index.entries()){
			if (entry.valid()){
				input.seekg(entry.offset,std::ios::beg);
				if (!input.good()){
					count = count + 1;
					continue ;
				}
				std::vector<unsigned char> rawdata;
				rawdata.resize(entry.length,0);
				input.read(reinterpret_cast<char*>(rawdata.data()),entry.length) ;
				
				auto entries = processBlock(count, rawdata);
				_data.insert_or_assign(count, entries);
			}
			count = count + 1 ;
		}

		
	}
	//==============================================================================
	int Statics::applyDiffs(const std::string &difflpath, const std::string &diffipath, const std::string &diffpath) {
		int count = 0 ;
		std::ifstream blockinput(difflpath,std::ios::in|std::ios::binary);
		if (!blockinput.is_open()){
			throw std::runtime_error(std::string("Unable to open static diff file: ")+difflpath);
		}
		IDX index(diffipath) ;
		std::ifstream input(diffpath,std::ios::in|std::ios::binary) ;
		if (!input.is_open()){
			throw std::runtime_error(std::string("Unable to open static diff file: ")+diffpath);
		}
		int blocknumber = 0 ;
		while (!blockinput.eof()){
			blockinput.read(reinterpret_cast<char*>(&blocknumber), 4);
			if (blockinput.gcount() != 4){
				
				break ;
			}
			auto entry = index.entry(count) ;
			if (entry.valid()){
				std::vector<unsigned char> temp(entry.length,0);
				input.seekg(entry.offset) ;
				input.read(reinterpret_cast<char*>(temp.data()),entry.length);
				processBlock(blocknumber, temp);
			}
			else {
				auto iter = _data.find(blocknumber) ;
				if (iter != _data.end()){
					_data.erase(iter);
				}
			}
			count = count + 1 ;
		}
		_diffCount = count ;
		return count ;
	}

	//==============================================================================
	std::list<mapstatic_tile> Statics::tilesAt(int x, int y){
		auto blockid = calcBlock(x, y) ;
		std::list<mapstatic_tile> rvalue ;
		auto iter = _data.find(blockid);
		if (iter != _data.end()){
			for (auto &entry: iter->second) {
				if ((entry.xloc == x) && (entry.yloc == y)){
					rvalue.push_back(entry);
				}
			}
			return rvalue ;
		}
		return rvalue;

	}
	//==============================================================================
	std::list<mapstatic_tile> Statics::blockContaining(int x, int y){
		auto blockid = calcBlock(x, y) ;
		auto iter = _data.find(blockid);
		if (iter != _data.end()){
			return iter->second ;
		}
		return std::list<mapstatic_tile>();
	}


}
