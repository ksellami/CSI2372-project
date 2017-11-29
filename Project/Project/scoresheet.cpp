#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName)
{}



int ScoreSheet::setTotal()
{
	overallScore = calcTotal();
	//returns the final score 
	return overallScore;	
}


bool ScoreSheet::score(RollOfDice roll, Colour uColor, int uPostion)
{
	return validate(uColor, uPostion);
}

ostream & operator<<(ostream & os, const ScoreSheet & sheet)
{
	os << sheet; 
	return os; 
}
