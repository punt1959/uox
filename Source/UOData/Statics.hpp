// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#ifndef Statics_hpp
#define Statics_hpp

#include <cstdint>
#include <string>
#include "BaseMap.hpp"
#include <list>
#include <vector>
#include <map>
#include <memory>
namespace UO {
	struct Art_Tile;

	struct mapstatic_tile{
		int altitude ;
		int xloc ;
		int yloc ;
		std::shared_ptr<Art_Tile> tile ;
		mapstatic_tile(){tile=nullptr;altitude=0;xloc=0;yloc=0;}
	};

	class Statics : public BaseMap{
		std::map<std::size_t , std::list<mapstatic_tile> > _data ;
	protected:
		std::list<mapstatic_tile> processBlock(int blockid, std::vector<unsigned char> &rawdata);
	public:
		Statics(int mapnum=0,const std::string &idxfile="",const std::string &mulfile="",int cellX=0,int cellY=0);
		void load(const std::string &idxfile,const std::string &mulfile,int mapnum =-1,int cellX=-1,int cellY=-1 );
		int applyDiffs(const std::string &difflpath, const std::string &diffipath, const std::string &diffpath);
		std::size_t size() const {return _data.size();}
		
		std::list<mapstatic_tile> tilesAt(int x, int y);
		std::list<mapstatic_tile> blockContaining(int x, int y);

	};
}

#endif /* Statics_hpp */
