#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H
#pragma once
#include <list>
#include "scoresheet.h"
#include "QwixxRow.cpp"
#include "Colour.h"
#include <iostream>


class QwixxScoreSheet : public ScoreSheet
{
	QwixxRow<std::vector<string>, Colour::RED> redRow; 
	QwixxRow<std::vector<string>, Colour::YELLOW> yellowRow;
	QwixxRow<std::list<string>, Colour::BLUE> blueRow;
	QwixxRow<std::list<string>,Colour::GREEN> greenRow; 
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
