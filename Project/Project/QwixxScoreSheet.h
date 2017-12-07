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
	
public:

	QwixxRow<std::vector<string>, Colour::RED> redRow;
	QwixxRow<std::vector<string>, Colour::YELLOW> yellowRow;
	QwixxRow<std::list<string>, Colour::BLUE> blueRow;
	QwixxRow<std::list<string>, Colour::GREEN> greenRow;

	QwixxScoreSheet(string name); 
	int calcScore(int &);
	int calcTotal();
	bool operator !();
	friend ostream& operator<<(ostream& os,QwixxScoreSheet& dt);
	bool score(QwixxScoreSheet& sheet, RollOfDice& roll, Colour uColor); 


	//Saves the total of entries in the corresponding color row
	int redEntriesTotal = 0;
	int yellowEntriesTotal = 0;
	int blueEntriesTotal = 0;
	int greenEntriesTotal = 0;
	
	int failedAttempts = 0;


protected :
	bool validate(Colour&, int&);



};
#endif
