#pragma once
#include "Player.h"
#include "RollOfDice.h"
#include "QwintoScoreSheet.h"



class QwintoPlayer :public Player
{
	

public:
	void inputBeforeRoll(RollOfDice& rod) ;
	void inputAfterRoll(RollOfDice& rod);
	QwintoPlayer();
	QwintoScoreSheet scoreSheet;
	
	
};

