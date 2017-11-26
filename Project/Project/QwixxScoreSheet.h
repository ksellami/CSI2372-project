#pragma once
#include "scoresheet.h"
class QwixxScoreSheet :
	public ScoreSheet
{
public:
	QwixxScoreSheet();
	void print() = 0;
	void calcTotal() = 0;
	bool operator ~ () = 0;


};

