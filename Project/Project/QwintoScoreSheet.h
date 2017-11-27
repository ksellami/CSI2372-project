#pragma once
#include "scoresheet.h"
class QwintoScoreSheet :
	public ScoreSheet
{
public:
	QwintoScoreSheet();
	void print();
	void calcTotal();
	bool operator ~ ();
	
};

