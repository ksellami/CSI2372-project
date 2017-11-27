#pragma once
#include "Player.h"
#include "RollOfDice.h"
#include "QwintoScoreSheet.h"



class QwintoPlayer :public Player
{

	//QwintoScoreSheet scoreSheet;


public:
	QwintoPlayer();
	void inputBeforeRoll(RollOfDice& rod) ;
	void inputAfterRoll(RollOfDice& rod);
};

