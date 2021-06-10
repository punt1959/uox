// 
// Created on:  6/4/21

#ifndef Combat_hpp
#define Combat_hpp

#include <cstdint>
#include <string>
#include <memory>
class Character ;

void attackTarget(std::shared_ptr<Character> &owner, std::shared_ptr<Character> &something);

#endif /* Combat_hpp */
