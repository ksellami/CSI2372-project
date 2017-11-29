#pragma once
#include "RollOfDice.h"


class Player
{
	bool isActive=false ; 
public:
	void setActive(bool param); 
	bool isOrNotActive(); 
	virtual void inputBeforeRoll(RollOfDice& rod) = 0; 
	virtual void inputAfterRoll(RollOfDice& rod) = 0;	
};

