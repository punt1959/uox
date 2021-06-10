// 
// Created on:  6/3/21

#ifndef Character_hpp
#define Character_hpp

#include <cstdint>
#include <string>
#include "enums.h"
#include "BaseObject.hpp"
class Character {
private:
	AIType _behavior ;
protected:
	
public:
	std::shared_ptr<Character> owner ;
	std::shared_ptr<Character> target ;

	AIType ai() { return _behavior;}  ;
	void   ai(AIType type) { _behavior = type;}
};

#endif /* Character_hpp */
