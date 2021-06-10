// 
// Created on:  6/9/21

#ifndef StaMap_hpp
#define StaMap_hpp

#include <cstdint>
#include <string>
#include "Statics.hpp"
#include "Map.hpp"

namespace UO {
	class StaMap {
	private:
		Map _map ;
		Statics _statics ;
		int _mapnum ;
	protected:
		
	public:
		
		// -1 for default sizes on cellX,cellY
		StaMap(int  mapnum,int cellX, int cellY, const std::string &mapfile, const std::string &staidx, const std::string &stamul);
		
		int applyMapDiff(const std::string &difflpath, const std::string &diffpath){return _map.applyDiff(difflpath,diffpath);}
		int applyStaDiffs(const std::string &difflpath, const std::string &diffipath, const std::string &diffpath){ return _statics.applyDiffs(difflpath, diffipath, diffpath);}
		
		map_tile mapTile(int x, int y){ return _map.tile(x,y);}
		
		std::list<mapstatic_tile> staTile(int x, int y) { return _statics.tilesAt(x, y);}
		std::list<mapstatic_tile> staBlockContaining(int x, int y){return _statics.blockContaining(x, y);};
		
		std::tuple<int,int> dimensions(){return _map.dimensions();}
		int mapNumber() { return _mapnum;}

		int mapDiffs() { return _map.numberOfDiffEntries();}
		int staDiffs() { return _statics.numberOfDiffEntries();};
	};
}
#endif /* StaMap_hpp */
