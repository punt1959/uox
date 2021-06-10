// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#include "Map.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <filesystem>

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Map
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++

namespace UO {
	const std::string Map::_uopformat = "build/map#legacymul/%08d.dat";
	
	//==============================================================================
	void Map::updateHash(){
		auto hash = _uopformat ;
		auto num = std::to_string(_mapnum);
		auto iter = hash.find("#") ;
		_hashformat = hash.replace(iter, 1, num);
	}
	
	//==============================================================================
	void Map::processData(std::vector<unsigned char> &data, std::uint32_t chunkid) {
		auto offset = chunkid*0xC4000 ;
		if (_mapdata.size() < (offset+data.size())) {
			_mapdata.resize(offset+data.size(),0);
		}
		std::swap_ranges(data.begin(), data.end(), _mapdata.begin()+offset);

	}
	//=======================================================================
	std::size_t  Map::calcIndex(int x, int y) {
		auto blocknum = calcBlock(x, y);
		auto index = blocknum * _mapblocksize + 4;
		
		auto basecoord = baseXY(blocknum) ;
		auto baseX = std::get<0>(basecoord) ;
		auto baseY = std::get<1>(basecoord) ;
		auto deltax = x - baseX ;
		auto deltay = y - baseY ;
		index = index + (deltay*24) + deltax*3 ;
		return index ;
	}
	//==============================================================================
	Map::Map(int mapnum,const std::string &mapfile,int cellX,int cellY): UOPData(), BaseMap(mapnum,cellX,cellY){
		_mytype=UOPData::map ;
		_maxhashes = 0x300 ;
		if (!mapfile.empty()) {
			load(mapfile,mapnum);
		}
	}
	//==============================================================================
	void Map::load(const std::string &mapfile,int mapnum,int cellX,int cellY ){
		auto path = std::filesystem::path(mapfile);
		auto size = std::filesystem::file_size(path);
		setMap(mapnum,cellX,cellY);
		updateHash();
		_mapdata.clear();
		std::ifstream input(mapfile, std::ios::in|std::ios::binary);
		if (!input.is_open()){
			throw std::runtime_error(std::string("Unable to open mapfile: ")+mapfile);
		}
		if (path.extension() == ".uop"){
			loadUOP(input);
		}
		else {
			_mapdata.resize(size, 0);
			input.read(reinterpret_cast<char*>(_mapdata.data()),size);
		}
		
	}

	//==============================================================================
	map_tile Map::tile(int x, int y){
		
		auto offset = calcIndex(x, y);
		auto tileid = *reinterpret_cast<unsigned short*>(_mapdata.data()+offset) ;
		map_tile tile ;
		tile.tile = Tiles::shared().land(tileid);
		tile.altitude = static_cast<int>(*reinterpret_cast<char*>(_mapdata.data()+offset+2)) ;
		tile.xloc=x ;
		tile.yloc=y;
		return tile ;
	}
	
	//=======================================================================
	int Map::applyDiff(const std::string &difflpath, const std::string &diffpath) {
		std::ifstream diffl(difflpath, std::ios::in|std::ios::binary);
		if (!diffl.is_open()) {
			throw std::runtime_error(std::string("Unable to open: ")+difflpath) ;
		}
		
		std::ifstream diff(diffpath, std::ios::in|std::ios::binary);
		if (!diff.is_open()) {
			throw std::runtime_error(std::string("Unable to open: ")+diffpath) ;
		}
		int blocknum = 0 ;
		auto count = 0 ;
		std::vector<unsigned char> tempdata ;
		tempdata.resize(_mapblocksize);
		while (!diffl.eof()) {
			
			diffl.read(reinterpret_cast<char*>(&blocknum),4);
			if (diffl.gcount()==4){
				count++ ;
				diff.read(reinterpret_cast<char*>(tempdata.data()),_mapblocksize);
				
				std::swap_ranges(tempdata.begin(), tempdata.end(), _mapdata.begin()+blocknum*_mapblocksize);
			}
		}
		diff.close();
		diffl.close();
		_diffCount= count ;
		return _diffCount ;
	}
}
