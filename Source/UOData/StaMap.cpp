// 
// Created on:  6/9/21

#include "StaMap.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for StaMap
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++

namespace UO {
	//=====================================================================================
	StaMap::StaMap(int mapnum,int cellX, int cellY, const std::string &mapfile, const std::string &staidx, const std::string &stamul){
		_mapnum = mapnum;
		_map.setMap(mapnum,cellX,cellY);
		_map.load(mapfile);
		// Get the size incase it was defaulted
		
		_statics.setMap(mapnum,cellX,cellY);
		_statics.load(staidx, stamul);
	}
	//=====================================================================================
	StaMap::StaMap() {
		_mapnum = 0 ;
	}
	
}
