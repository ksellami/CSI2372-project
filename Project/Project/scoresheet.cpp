#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName)
{


}



int ScoreSheet::setTotal()
{

	//returns the final score 
	return calcTotal();

	
}



bool ScoreSheet::score(RollOfDice roll, Colour uColor, int uPostion)
{
	return validate(uColor, uPostion);
}