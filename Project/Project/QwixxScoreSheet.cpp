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


bool QwixxScoreSheet::validate(Colour &uColor, int &roll)
{
	switch (uColor) {

		/*case (Colour::RED)
			break;
		case (Colour::YELLOW)
			break;
		case (Colour::GREEN)
			break;
		case (Colour::BLUE)
			break;*/


	}


	return false;
}
bool QwixxScoreSheet::score(QwixxScoreSheet & sheet, RollOfDice roll, Colour uColor, int uPostion)
{
	int result = roll;
	bool scored = false;

	if (uColor == Colour::RED || uColor == Colour::YELLOW) {

		switch (uColor) {

		case(Colour::RED):
			result++;			// next position

			for (std::vector<string>::iterator it = sheet.redRow.itAtPosition(result); it != sheet.redRow.Row.end(); ++it) {

				if (*it == "XX")
				{
					return false;
				}
				else {


					scored= true;
				}
				
			}

			*--sheet.redRow.itAtPosition(result) = "XX";


			break;
		case(Colour::YELLOW):
			result++;			// next position
			
			for (std::vector<string>::iterator it = sheet.yellowRow.itAtPosition(result); it != sheet.yellowRow.Row.end(); ++it) {

				if (*it == "XX")
				{
					return false;
				}
				else {


					scored = true;
				}
			}

			*--sheet.yellowRow.itAtPosition(result) = "XX";

			break;

		}

	}
	else {
		
		switch (uColor) {

		case(Colour::GREEN):
			 
			for (std::list<string>::iterator it = sheet.greenRow.Row.end(); it != sheet.greenRow.itAtPosition(result); --it) {
				
				if (*it == "XX")
				{
					return false;
				}
				else {


					scored = true;
				}
			}

			*--sheet.greenRow.itAtPosition(result) = "XX";

		break;
		case(Colour::BLUE):

			for (std::list<string>::iterator it = sheet.blueRow.Row.end(); it != sheet.blueRow.itAtPosition(result); --it) {

				if (*it == "XX")
				{
					return false;
				}
				else {


					scored = true;
				}
			}

			*--sheet.blueRow.itAtPosition(result) = "XX";

			
		break;

		}

	}
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
