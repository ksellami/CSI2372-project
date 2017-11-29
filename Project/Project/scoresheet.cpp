#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName)
{}



int ScoreSheet::setTotal()
{
	overallScore = calcTotal();
	//returns the final score 
	return overallScore;	
}


<<<<<<< HEAD
bool ScoreSheet::score(RollOfDice roll, Colour uColor, int uPostion)
=======

bool ScoreSheet::score(ScoreSheet& sheet, RollOfDice roll, Colour uColor, int uPostion = -1)
>>>>>>> b3cc259c9c99809a13c4c771fdbd08e91c17adf3
{
	return validate(uColor, uPostion);
}

<<<<<<< HEAD
ostream & operator<<(ostream & os, const ScoreSheet & sheet)
{
	os << sheet; 
	return os; 
=======
void ScoreSheet::fail()
{

	failedAttempts--;
>>>>>>> b3cc259c9c99809a13c4c771fdbd08e91c17adf3
}
