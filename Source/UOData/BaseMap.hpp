// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#ifndef BaseMap_hpp
#define BaseMap_hpp

#include <cstdint>
#include <string>
#include <tuple>
namespace UO {
	class BaseMap {

	protected:
		static constexpr int _defaultsizes[12] =
		{7168,4096,7196,4096,2304,1600,2560,2048,1448,1448,1280,4096};
		
		static constexpr std::size_t _mapblocksize = (64 * 3) + 4 ; // 64 cells, 3 bytes each, + 4 byte header


		int _diffCount ;
		int _cellXSize ;
		int _cellYSize ;
		int _mapnum ;
		
		int calcBlock(int x, int y) ;
		std::tuple<int,int> baseXY(int block) ;

	public:
		BaseMap(int mapnum ,int cellX = 0, int cellY=0) ;
		void setMap(int mapnum,int cellX = 0,int cellY=0 );
		int numberOfDiffEntries() const { return _diffCount;};
		std::tuple<int,int> dimensions() const { return std::make_tuple(_cellXSize,_cellYSize) ;}
		int mapNumber() const { return _mapnum;}

	};
}
#endif /* BaseMap_hpp */
