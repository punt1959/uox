// 
// Created on:  6/10/21

#include "MultiCollection.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for MultiCollection
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++

//============================================================================
MultiCollection& MultiCollection::shared(){
	static MultiCollection instance;
	return instance ;
}
//==========================================================================
MultiCollection::MultiCollection(){
	
}
//==========================================================================
void MultiCollection::load(std::filesystem::path &uopath) {
	_multi.load(uopath.string());
}
//==========================================================================
bool MultiCollection::exists(std::size_t id){
	return _multi.exists(id);
}
//==========================================================================
const UO::multi_structure& MultiCollection::multi(std::size_t id){
	return _multi.multi(id);
}

//==========================================================================
std::size_t MultiCollection::size() const {
	return _multi.size();
}
