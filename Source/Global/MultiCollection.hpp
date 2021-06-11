// 
// Created on:  6/10/21

#ifndef MultiCollection_hpp
#define MultiCollection_hpp

#include <cstdint>
#include <string>
#include <filesystem>
#include "Multi.hpp"
class MultiCollection {
private:
	UO::Multi _multi ;
	MultiCollection();
protected:
	
public:
	MultiCollection( const MultiCollection &) = delete;
	MultiCollection& operator=(const MultiCollection&) = delete ;
	static MultiCollection& shared() ;
	void load(std::filesystem::path &uopath);
	bool exists(std::size_t id);
	const UO::multi_structure& multi(std::size_t id);
	
	std::size_t size() const ;

};

#endif /* MultiCollection_hpp */
