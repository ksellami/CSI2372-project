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
			 if (redRow[roll] == "XX" || this->redEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
		 case (Colour::YELLOW):
			 if (yellowRow[roll] == "XX" || this->yellowEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
		 case (Colour::GREEN):
			 if (greenRow[roll] == "XX" || this->greenEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
		 case (Colour::BLUE):
			 if (blueRow[roll]== "XX" || this->blueEntriesTotal == 5)
				 return false;
			 else
				 return true;
			 break;
			

		 }
	 }
	


	return false;
}
bool QwixxScoreSheet::score(QwixxScoreSheet & sheet, RollOfDice &roll, Colour uColor)
{
	
	int result = roll;
	bool scored = false;
	bool valid = sheet.validate(uColor, result);

	if (valid) {
		if (uColor == Colour::RED || uColor == Colour::YELLOW) {
			
			switch (uColor) {
			case(Colour::RED):

				for (int it = roll.operator int() - 1; it <= 10; ++it) {

					if (redRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}

				sheet.redRow[result-2] = "XX";
				sheet.redEntriesTotal++;


				break;
			case(Colour::YELLOW):

				for (int it = roll - 1; it <= 10; ++it) {

					if (yellowRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}

				sheet.yellowRow[result-2]= "XX";
				sheet.yellowEntriesTotal++;

				break;

			}

		}
		else {
			int afterResult = result;

			switch (uColor) {

			case(Colour::GREEN):

				for (int it = 13 - roll; it <= 10; ++it) {

					if (greenRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}
				sheet.greenRow[12 - result] = "XX";
				sheet.greenEntriesTotal++;

				break;
			case(Colour::BLUE):
				afterResult--;
				for (int it = 13 - roll; it <= 10; ++it) {

					if (blueRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}

				sheet.blueRow[result] = "XX";
				sheet.blueEntriesTotal++;


				break;

			}

		}
	}
	return scored;
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
