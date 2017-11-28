#include "QwixxScoreSheet.h"

ostream & operator<<(ostream & os, const QwixxScoreSheet & dt)
{   
	os << "Player Name " << dt.playerName << endl; 
	os << "Red "<<dt.redRow << endl;
	os << "Yellow "<<dt.yellowRow << endl;
	os << "Green " <<dt.greenRow << endl;
	os <<"Blue "<< dt.blueRow << endl;
	
}
