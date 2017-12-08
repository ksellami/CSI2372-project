#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "RollOfDice.h"



class Player
{

public:
	 
	bool statut = false; // the statut of the player
	void setActive(bool param);
	bool isActive(); 
	virtual void inputBeforeRoll(RollOfDice& rod) = 0; 
	virtual void inputAfterRoll(RollOfDice& rod) = 0;	
};

#endif

// abstract parent class for the 2 versions' players