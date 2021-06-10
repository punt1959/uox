// 
// Created on:  6/3/21

#ifndef AI_hpp
#define AI_hpp

#include <cstdint>
#include <string>
#include <memory>
class Character ;
void checkAI(std::shared_ptr<Character> &mChar);
void handleHealerAI(std::shared_ptr<Character> &mChar);
void handleEvilHealerAI(std::shared_ptr<Character> &mChar);
void handleEvilAI(std::shared_ptr<Character> &mChar);
void handleGuardAI(std::shared_ptr<Character> &mChar);
void handleFighterAI(std::shared_ptr<Character> &mChar);
void handleAnimalAI(std::shared_ptr<Character> &mChar) ;
void handleChaoticAI(std::shared_ptr<Character> &mChar);
#endif /* AI_hpp */
