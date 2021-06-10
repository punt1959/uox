// 
// Created on:  6/4/21

#include "MiscFunction.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include "BaseObject.hpp"

bool ValidateObject(const std::shared_ptr<BaseObject> &object){
	if ((object == nullptr) || (object->isDeleted)){
		return false ;
	}
	return true ;
}
