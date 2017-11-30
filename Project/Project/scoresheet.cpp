#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName),overallScore(0),failedAttempts(0)
{}



int ScoreSheet::setTotal()
{
	overallScore = calcTotal();
	//returns the final score 
	return overallScore;	
}

ostream & operator<<(ostream & os, const ScoreSheet & sheet)
{
	os << sheet;
	return os;
}
void ScoreSheet::fail()
{
	failedAttempts--;
}
