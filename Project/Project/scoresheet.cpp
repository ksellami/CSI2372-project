#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName),overallScore(0),failedAttempts(0)
{}



int ScoreSheet::setTotal()
{
	overallScore = calcTotal();
	//returns the final score 
	return overallScore;	
}


void ScoreSheet::fail()
{
	failedAttempts--;
}
