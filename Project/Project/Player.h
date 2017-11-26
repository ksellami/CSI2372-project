#pragma once
#include "RollOfDice.h"


class Player
{
	bool isActive = false; 
public:
	virtual void inputBeforeRoll(RollOfDice& rod) = 0; 
	virtual void inputAfterRoll(RollOfDice& rod) = 0;

	Player();
	
};

