// 
// Created on:  6/9/21

#include "Maps.hpp"
#include "DataCategory.hpp"
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include "StringUtility.hpp"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Maps
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//StaMap(int  mapnum,int cellX, int cellY, const std::string &mapfile, const std::string &staidx, const std::string &stamul);

//==============================================================================
Maps::Maps(const std::filesystem::path& uodir, std::map<std::string,std::shared_ptr<DataSection> > &mapsections){
	for (auto &entry : mapsections){
		auto name = entry.first ;
		auto two = strutil::split(name, " ");
		if (strutil::toupper(std::get<0>(two))=="MAP"){
			// We need to make map!
			// we need at least these 5 items
			auto mapnum = std::stoi(std::get<1>(two));
			// we need at least these 5 items
			int cellX = 0 ;
			int cellY = 0 ;
			auto width = entry.second->firstKey("X");
			if (width != nullptr){
				cellX = width->first_number ;
			}
			auto height = entry.second->firstKey("Y");
			if (height != nullptr){
				cellY = height->first_number ;
			}
			
			auto mapmul = entry.second->firstKey("MAP");
			if (mapmul == nullptr){
				throw std::runtime_error(std::string("Map not specified for  ")+std::get<1>(two));
			}
			auto stamul = entry.second->firstKey("STATICS");
			if (stamul == nullptr){
				throw std::runtime_error(std::string("Statics not specified for  ")+std::get<1>(two));
			}
			auto staidx = entry.second->firstKey("STAIDX");
			if (staidx == nullptr){
				throw std::runtime_error(std::string("StaIdx not specified for  ")+std::get<1>(two));
			}
			
			
			_maps.insert_or_assign(mapnum,
						     UO::StaMap(mapnum, cellX, cellY,
								    (uodir / std::filesystem::path(mapmul->text)).string(),
								    (uodir / std::filesystem::path(staidx->text)).string(),
								    (uodir / std::filesystem::path(stamul->text)).string() )) ;
			// apply diffs
			auto mapdiff = entry.second->firstKey("MAPDIFF");
			auto maplist = entry.second->firstKey("MAPDIFFLIST");
			if((mapdiff != nullptr) && (maplist != nullptr)){
				_maps[mapnum].applyMapDiff((uodir / std::filesystem::path(maplist->text)).string(), (uodir / std::filesystem::path(mapdiff->text)).string());
			}
			auto stadiff = entry.second->firstKey("STATICSDIFF");
			auto stalist = entry.second->firstKey("STATICSDIFFLIST");
			auto staind = entry.second->firstKey("STATICSDIFFINDEX");
			if((stadiff != nullptr) && (stalist != nullptr)&& (staind != nullptr)){
				_maps[mapnum].applyStaDiffs(
								    (uodir / std::filesystem::path(stalist->text)).string(),
								     (uodir / std::filesystem::path(staind->text)).string(),
								    (uodir / std::filesystem::path(stadiff->text)).string());
			}

		}
	}
}

//============================================================================
Maps& Maps::shared(const std::filesystem::path& uodir, std::map<std::string,std::shared_ptr<DataSection>> &mapsections){
	static Maps instance(uodir,mapsections);
	return instance ;
}
//============================================================================
int Maps::mapDiffCount(int mapnum){
	return _maps.at(mapnum).mapDiffs();
}
//============================================================================
int Maps::staDiffCount(int mapnum){
	return _maps.at(mapnum).staDiffs();
}
