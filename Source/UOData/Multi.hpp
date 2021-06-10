// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#ifndef Multi_hpp
#define Multi_hpp

#include <cstdint>
#include <string>
#include <list>
#include <map>
#include <algorithm>

#include "Tiles.hpp"
#include "UOPData.hpp"
#include "IDX.hpp"
//============================================================================
// This is meant to be ued with the Tiles.hpp/cpp.  Since it stores a shared
// pointer of the tile for each multi component, it assumes that Tile() has
// been initialized and LOADED prior to loading the multi file.
//============================================================================
namespace UO {
	
	struct multi_component {
		int xoffset ;
		int yoffset ;
		int zoffset ;
		unsigned long long component_flag ;
		std::shared_ptr<Art_Tile> tile ;
		multi_component(){xoffset = 0;zoffset=0;yoffset=0;component_flag=0;tile=nullptr;}
	};
	struct multi_structure {
		std::list<multi_component> components;
		int maxXOffset ;
		int minXOffset ;
		int maxYOffset ;
		int minYOffset ;
		int maxZOffset ;
		int minZOffset ;
		int height ;
		multi_structure() { maxXOffset=0;maxYOffset=0;maxZOffset=0;minXOffset=0;minYOffset=0;minZOffset=0;height=0;}
		void calcOffset() {
			bool firsttime = true ;
			for (auto &entry: components){
				if (firsttime){
					maxXOffset=entry.xoffset;
					minXOffset=entry.xoffset;
					
					maxYOffset=entry.yoffset;
					minYOffset=entry.yoffset;
					
					minZOffset=entry.zoffset;
					maxZOffset=entry.zoffset;
					firsttime=false ;
				}
				else {
					maxXOffset=std::max(maxXOffset,entry.xoffset);
					minXOffset=std::min(minXOffset,entry.xoffset);
					
					maxYOffset=std::max(maxYOffset,entry.yoffset);
					minYOffset=std::min(minYOffset,entry.yoffset);
					
					maxZOffset=std::max(maxZOffset,entry.zoffset);
					minZOffset=std::min(minZOffset,entry.zoffset);
					
					
				}
				if (entry.tile->flag != 0){
					height = std::max(height,entry.tile->height+entry.zoffset) ;
				}
			}
		}
		
	};
	
	class Multi : public UOPData {
	private:
		std::map<std::size_t,multi_structure> _multis ;
		static constexpr std::size_t hssize = 908592;
		static const std::string _uopformat ;
	protected:
		void processData(std::vector<unsigned char> &data, std::uint32_t chunkid) override;
	public:
		Multi() ;
		Multi(const std::string &idxfile, const std::string &mulfile);
		Multi(const std::string &uopfile);
		
		bool load(const std::string &idxfile, const std::string &mulfile);
		bool load(const std::string &uopfile);
		
		bool exists(std::size_t id);
		const multi_structure& multi(std::size_t id);
		
		std::size_t size() const ;
	};
}
#endif /* Multi_hpp */
