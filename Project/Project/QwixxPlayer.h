#pragma once
#include "Player.h"
#include "RollOfDice.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer :public Player
{
public:
	QwixxScoreSheet sheet;
	QwixxPlayer(string name);
	void inputBeforeRoll(RollOfDice& rod);
	void inputAfterRoll(RollOfDice& rod);
};

