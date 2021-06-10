// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#include "BaseMap.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for BaseMap
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
namespace UO {
	
	//============================================================================
	int BaseMap::calcBlock(int x, int y) {
		auto xblock = x/8 ;
		auto yblock = y/8 ;
		return (xblock * (_cellYSize/8)) + yblock ;
	}
	
	//============================================================================
	std::tuple<int,int> BaseMap::baseXY(int block){
		auto height = (_cellYSize/8) ;
		int x = (block/ height) * 8 ;
		int y = (block % height) * 8 ;
		return std::make_tuple(x,y);
		
	}
	
	//=========================================================================
	BaseMap::BaseMap(int mapnum ,int cellX,int cellY) {
		_diffCount = 0 ;
		setMap(mapnum,cellX,cellY);
	}
	
	
	//=========================================================================
	void BaseMap::setMap(int mapnum,int cellX ,int cellY ){
		if (mapnum > -1){
			_mapnum=mapnum ;
		}
		if (cellX > -1){
			_cellXSize = cellX;
			if (cellX == 0){
				_cellXSize = _defaultsizes[mapnum*2] ;
			}

		}
		if (cellY > -1){
			_cellYSize = cellY;

			if (cellY == 0){
				_cellYSize = _defaultsizes[(mapnum*2)+1] ;
			}
		}
	}
}
