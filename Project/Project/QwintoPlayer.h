#pragma once
#include "Player.h"
#include <string>
#include "QwintoScoreSheet.h"



class QwintoPlayer :public Player
{

public:
	QwintoScoreSheet sheet;
	QwintoPlayer(string name); 
	void inputBeforeRoll(RollOfDice& rod) ;
	void inputAfterRoll(RollOfDice& rod);
};

