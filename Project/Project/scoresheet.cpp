#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName)
{


}



int ScoreSheet::setTotal()
{
	overallScore = calcTotal();
	//returns the final score 
	return overallScore;

	
}



bool ScoreSheet::score(ScoreSheet& sheet, RollOfDice roll, Colour uColor, int uPostion = -1)
{
	return validate(uColor, uPostion);
}

void ScoreSheet::fail()
{

	failedAttempts--;
}
