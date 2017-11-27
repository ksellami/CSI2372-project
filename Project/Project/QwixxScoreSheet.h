#pragma once
#include "scoresheet.h"
class QwixxScoreSheet :
	public ScoreSheet
{
public:
	QwixxScoreSheet();
	void print() ;
	void calcTotal();
	bool operator ~ ();


};

