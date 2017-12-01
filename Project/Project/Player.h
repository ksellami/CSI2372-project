#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "RollOfDice.h"


class Player
{

public:
	bool isActive = false;
	void setActive(bool param); 
	bool isOrNotActive(); 
	virtual void inputBeforeRoll(RollOfDice& rod) = 0; 
	virtual void inputAfterRoll(RollOfDice& rod) = 0;	
};

#endif