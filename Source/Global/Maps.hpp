// 
// Created on:  6/9/21

#ifndef Maps_hpp
#define Maps_hpp

#include <cstdint>
#include <string>
#include <memory>
#include <map>
#include "StaMap.hpp"
#include "DataSection.hpp"
class Maps {
private:
	
	std::map<int,UO::StaMap> _maps ;
	

	Maps(const std::string& uodir, std::shared_ptr<DataSection> &mapsection);
	
protected:
	
	
public:
	Maps( const Maps &) = delete;
	Maps& operator=(const Maps&) = delete ;
	static Maps& shared(const std::string& uodir, std::shared_ptr<DataSection> &mapsection) ;

};

#endif /* Maps_hpp */
