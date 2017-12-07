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

	 if (roll < 2 || roll > 12)
		 return false; 
	 else {
		 switch (uColor) {


		 case (Colour::RED):
			 if (*redRow.itAtPosition(roll) == "XX" || this->redEntriesTotal == 5 )
				 return false;
			 else
				 return true;
			 break;
		 case (Colour::YELLOW):
			 if (*yellowRow.itAtPosition(roll) == "XX" || this->yellowEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
		 case (Colour::GREEN):
			 if (*greenRow.itAtPosition(roll) == "XX" || this->greenEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
		 case (Colour::BLUE):
			 if (*blueRow.itAtPosition(roll) == "XX" || this->blueEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
			

		 }
	 }
	


	return false;
}
bool QwixxScoreSheet::score(QwixxScoreSheet & sheet, RollOfDice roll, Colour uColor, int uPostion)
{
	
	int result = roll;
	bool scored = false;
	bool valid = sheet.validate(uColor, result);

	if (valid) {
		if (uColor == Colour::RED || uColor == Colour::YELLOW) {
			int afterResult = result;

			switch (uColor) {
			case(Colour::RED):
				afterResult++;			// next position

				for (std::vector<string>::iterator it = sheet.redRow.itAtPosition(afterResult); it != sheet.redRow.Row.end(); ++it) {

					if (*it == "XX")
					{
						return false;
					}
					else {


						scored = true;
					}

				}

				*sheet.redRow.itAtPosition(result) = "XX";
				sheet.redEntriesTotal++;


				break;
			case(Colour::YELLOW):
				afterResult++;			// next position

				for (std::vector<string>::iterator it = sheet.yellowRow.itAtPosition(afterResult); it != sheet.yellowRow.Row.end(); ++it) {

					if (*it == "XX")
					{
						return false;
					}
					else {


						scored = true;
					}
				}

				*sheet.yellowRow.itAtPosition(result) = "XX";
				sheet.yellowEntriesTotal++;

				break;

			}

		}
		else {
			int afterResult = result;

			switch (uColor) {

			case(Colour::GREEN):
				afterResult--;
				for (std::list<string>::iterator it = sheet.greenRow.itAtPosition(afterResult); it != sheet.greenRow.Row.end(); ++it) {

					if (*it == "XX")
					{
						return false;
					}
					else {


						scored = true;
					}
				}

				*sheet.greenRow.itAtPosition(result) = "XX";
				sheet.greenEntriesTotal++;

				break;
			case(Colour::BLUE):
				afterResult--;
				for (std::list<string>::iterator it = sheet.blueRow.itAtPosition(afterResult); it != sheet.blueRow.Row.end(); --it) {

					if (*it == "XX")
					{
						return false;
					}
					else {


						scored = true;
					}
				}

				*sheet.blueRow.itAtPosition(result) = "XX";
				sheet.blueEntriesTotal++;


				break;

			}

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
