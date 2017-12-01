#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H
#pragma once
#include "scoresheet.h"
#include "QwixxRow.h"
#include "QwixxRow.cpp"
#include "Colour.h"
#include <iostream>
#include <list>

class QwixxScoreSheet : public ScoreSheet
{
	QwixxRow<std::vector<int>, Colour::RED> redRow; 
	QwixxRow<std::vector<int>, Colour::YELLOW> yellowRow;
	QwixxRow<std::vector<int>,Colour::GREEN> greenRow;
	QwixxRow<std::vector<int>, Colour::BLUE> blueRow;

public:

	QwixxScoreSheet(string name); 
	int calcTotal();
	bool operator !();
	friend ostream& operator<<(ostream& os,QwixxScoreSheet& dt);
	bool score(QwixxScoreSheet& sheet, RollOfDice roll, Colour uColor, int uPostion = -1); 

protected:
	bool validate(Colour&, int&);


};
#endif
