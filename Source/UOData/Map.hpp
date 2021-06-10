// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#ifndef Map_hpp
#define Map_hpp

#include <cstdint>
#include <string>
#include <vector>
#include "UOPData.hpp"
#include "BaseMap.hpp"
#include "Tiles.hpp"
namespace UO {
	struct map_tile{
		std::shared_ptr<Land_Tile> tile ;
		int altitude ;
		int xloc ;
		int yloc ;
		map_tile(){tile=nullptr;altitude=0;xloc=0;yloc=0;}
	};

	class Map : public UOPData, public BaseMap {
	private:
		static const std::string _uopformat ;
		
		std::vector<unsigned char> _mapdata ;
	protected:
		void updateHash() ;
		void processData(std::vector<unsigned char> &data, std::uint32_t chunkid) override;
		std::size_t calcIndex(int x, int y) ;

	public:
		Map(int mapnum=0,const std::string &mapfile="",int cellX=0,int cellY=0);
		void load(const std::string &mapfile,int mapnum =-1,int cellX=-1,int cellY=-1 );
		map_tile tile(int x, int y);
		int applyDiff(const std::string &difflpath, const std::string &diffpath);

	};
}


#endif /* Map_hpp */
