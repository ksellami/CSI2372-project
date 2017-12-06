#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H
#pragma once
#include "scoresheet.h"
#include "QwintoRow.cpp"
#include <iostream>

class QwintoScoreSheet :
	public ScoreSheet
{
public:
	QwintoRow<Colour::RED> redRow;
	QwintoRow<Colour::YELLOW> yellowRow;
	QwintoRow<Colour::BLUE> blueRow;
	
	QwintoScoreSheet(string NewName);
	bool validate(Colour&, int&);
	bool verify(int position, int result, array<int, 10>& Row);
	bool score(QwintoScoreSheet& sheet,RollOfDice roll, Colour uColor, int uPostion);
	friend ostream& operator<<(ostream& os, QwintoScoreSheet& qwinto);

	bool operator!();
	int totalRowsCompleted = 0;
	int calcTotal();
	
	//Saves the total of entries in the corresponding color row
	int redEntriesTotal = 0;
	int yellowEntriesTotal = 0;
	int blueEntriesTotal = 0;

};

#endif