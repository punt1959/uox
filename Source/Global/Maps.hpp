// 
// Created on:  6/9/21

#ifndef Maps_hpp
#define Maps_hpp

#include <cstdint>
#include <string>
#include <memory>
#include <map>
#include <filesystem>
#include "StaMap.hpp"
#include "DataSection.hpp"
class Maps {
private:
	
	std::map<int,UO::StaMap> _maps ;
	

	Maps(const std::filesystem::path& uodir, std::map<std::string,std::shared_ptr<DataSection> > &mapsections);
	
protected:
	
	
public:
	Maps( const Maps &) = delete;
	Maps& operator=(const Maps&) = delete ;
	static Maps& shared(const std::filesystem::path& uodir, std::map<std::string,std::shared_ptr<DataSection> > &mapsections) ;
	int mapDiffCount(int mapnum);
	int staDiffCount(int mapnum);
};

#endif /* Maps_hpp */
