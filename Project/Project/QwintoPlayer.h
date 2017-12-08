#ifndef QWINTOPLAYER_H
#define QWINTOPLAYER_H
#pragma once
#include "Player.h"
#include <string>
#include "QwintoScoreSheet.h"

using namespace std;


class QwintoPlayer :public Player
{

public:
	QwintoScoreSheet sheet; // the player sheet 
	QwintoPlayer(string name); 
	void inputBeforeRoll(RollOfDice& rod) ;
	void inputAfterRoll(RollOfDice& rod);

};

#endif
