#include "scoresheet.h"


ScoreSheet::ScoreSheet(string pName) :playerName(pName)
{


}


bool ScoreSheet::score(RollOfDice roll, Colour uColor, int uPostion)
{


	return validate(uColor,uPostion);
}
void ScoreSheet::setTotal()
{


	calcTotal();
}

