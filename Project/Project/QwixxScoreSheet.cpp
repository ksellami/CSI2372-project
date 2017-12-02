#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(string name) :ScoreSheet(name)
{
}

int QwixxScoreSheet::calcTotal()
{
	return 0;
}

bool QwixxScoreSheet::operator!()
{
	return false;
}

bool QwixxScoreSheet::score(QwixxScoreSheet & sheet, RollOfDice roll, Colour uColor, int uPostion)
{
	return false;
}

bool QwixxScoreSheet::validate(Colour &, int &)
{
	return false;
}

ostream & operator<<(ostream & os, QwixxScoreSheet & dt)
{   
	os << "Player Name :" << dt.playerName << '\t' << '\t' << "Points: " << dt.overallScore << endl;
	os << '\t' << "-------------------------------------" << endl;
	os << "Red   "<<dt.redRow << endl;
	os << "Yellow   "<<dt.yellowRow << endl;
	os << "Green   " <<dt.greenRow << endl;
	os <<"Blue   "<< dt.blueRow << endl;
	os << "-------------------------------------" << endl;
	os << "Failed Throw" << endl;

	return os;
	
}
