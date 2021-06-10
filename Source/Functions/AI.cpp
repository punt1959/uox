// 
// Created on:  6/3/21

#include "AI.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include "Character.hpp"
#include "Combat.hpp"
#include "MiscFunction.hpp"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for AI
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//============================================================================
void checkAI( std::shared_ptr<Character>& mChar )
{
	switch(mChar->ai() )
	{
		case AIType::banker:
		case AIType::playerVendor:
		case AIType::none:
		case AIType::passive:
			break;   // No AI for these special NPC's.
		case AIType::goodHealer:
			handleHealerAI(mChar);
			break;
		case AIType::evil:
			handleEvilAI(mChar);
			break;
		case AIType::guard:
			handleGuardAI(mChar);
			break;
		case AIType::fighter:
			handleFighterAI(mChar); // Fighter - same as guard, without teleporting & yelling "HALT!"
			break;
		case AIType::animal:
			handleAnimalAI(mChar);
			break;
		case AIType::chaotic:
			handleChaoticAI(mChar);
			break;
		case AIType::evilHealer:
			handleEvilHealerAI(mChar);
			break;
		case AIType::guardPet:
		{
			auto realChar = mChar->owner;
			if (realChar == nullptr) {
				mChar->ai(AIType::none);
			}
			if( realChar->target != nullptr ){
				attackTarget(mChar,realChar->target) ;
			}
		}
			break;
		default:
#pragma message("Add console message")
			break;
			
	}
	return ;
}

//============================================================================
void handleHealerAI(std::shared_ptr<Character> &mChar){
	
}
//============================================================================
void handleEvilHealerAI(std::shared_ptr<Character> &mChar){
	
}
//============================================================================
void handleEvilAI(std::shared_ptr<Character> &mChar){
	
}
//============================================================================
void handleGuardAI(std::shared_ptr<Character> &mChar){
	
}
//============================================================================
void handleFighterAI(std::shared_ptr<Character> &mChar){
	
}
//============================================================================
void handleAnimalAI(std::shared_ptr<Character> &mChar) {
	
}
//============================================================================
void handleChaoticAI(std::shared_ptr<Character> &mChar){
	
}
