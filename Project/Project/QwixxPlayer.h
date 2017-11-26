#pragma once
#include "Player.h"
#include "RollOfDice.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer :public Player
{
public:
	void inputBeforeRoll(RollOfDice& rod);
	void inputAfterRoll(RollOfDice& rod);
	QwixxPlayer();


	QwixxScoreSheet scoreSheet;
	
};

