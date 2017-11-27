#pragma once
#include "scoresheet.h"
class QwintoScoreSheet :
	public ScoreSheet
{
public:
	QwintoRow<Colour::RED> red;
	QwintoRow<Colour::YELLOW> yellow;
	QwintoRow<Colour::BLUE> blue;
	
	QwintoScoreSheet(string NewName);
	void print();
	void calcTotal();
	bool operator ~ ();
	string playerName;
	
protected:	
	bool validate(Colour&, int&);
	
	
};

