#pragma once
#include "scoresheet.h"
#include "QwintoRow.h"

class QwintoScoreSheet :
	public ScoreSheet
{
public:
	QwintoRow<Colour::RED> redRow;
	QwintoRow<Colour::YELLOW> yellowRow;
	QwintoRow<Colour::BLUE> blueRow;
	
	bool score(RollOfDice roll, Colour uColor, int uPostion);
	QwintoScoreSheet(string NewName);
	void print();
	int calcTotal();
	
	friend ostream& operator<<(ostream& os, const QwintoScoreSheet& qwinto);

	bool operator!();
	string playerName;
	
protected:	
	bool validate(Colour&, int&);
	int totalRowsCompleted = 0;
	
	//Saves the total of entries in the corresponding color row
	int redEntriesTotal=0;
	int yellowEntriesTotal=0;
	int blueEntriesTotal=0;



	
	
	
};

