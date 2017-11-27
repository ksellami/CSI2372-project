#pragma once
#include "scoresheet.h"
class QwintoScoreSheet :
	public ScoreSheet
{
public:
	QwintoRow<Colour::RED> red;
	QwintoRow<Colour::YELLOW> yellow;
	QwintoRow<Colour::BLUE> blue;
	
	QwintoScoreSheet(string playerName);
	void print();
	void calcTotal();
	bool operator ~ ();
	
protected:	
	bool validate(Colour&, int&);
	
};

