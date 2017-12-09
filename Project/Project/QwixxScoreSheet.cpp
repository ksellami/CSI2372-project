#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(string name) :ScoreSheet(name)
{

	
}

int QwixxScoreSheet::calcScore(int & entriesNum)
{
	int result = 0;

		
	for (int i = 1; i <= entriesNum; i++) {

		result = i + result;

	}
	
		return result;
}
int QwixxScoreSheet::calcTotal()
{
	int total = 0;

	total += this->calcScore(redEntriesTotal);
	total += this->calcScore(yellowEntriesTotal);
	total += this->calcScore(greenEntriesTotal);
	total += this->calcScore(blueEntriesTotal);

	total -= this->failedAttempts * 5;

	return total;
}

bool QwixxScoreSheet::operator!()
{
	
	int lockedRows = 0;
	//if failed throws is 4 or more
	if (this->failedAttempts >= 4)
		return true;
	

	//see if two rows or more are locked if so return true: 
	if (redRow[11] == "L")
		lockedRows++;

	if (greenRow[11] == "L")
		lockedRows++;

	if (yellowRow[11] == "L")
		 lockedRows++;

	if (blueRow[11] == "L")
		lockedRows++;

	if (lockedRows >= 2) {

		return true;;
	}
	
	

	return false;
}


 bool QwixxScoreSheet::validate(Colour &uColor, int &roll)
{

	 if (roll < 2 || roll > 12)
		 return false; 

	 else {
		 switch (uColor) {
		 case (Colour::RED):
			 if (redRow[roll-2] == "XX" || redRow[11] == "L")

				 return false;
			 else
				 return true;
			 break;
		 case (Colour::YELLOW):

			 if (yellowRow[roll-2] == "XX" | yellowRow[11] == "L")

				 return false;
			 else
				 return true;
			 break;
		 case (Colour::GREEN):

			 if (greenRow[12-roll] == "XX" || greenRow[11] == "L")


				 return false;
			 else
				 return true;
			 break;
		 case (Colour::BLUE):


			 if (blueRow[12-roll]== "XX" || blueRow[11] == "L")

				 return false;
			 else
				 return true;
			 break;
			

		 }
	 }
	


	return false;
}
bool QwixxScoreSheet::score(RollOfDice &roll, Colour uColor,int uPosition)
{
	
	int result = roll;
	bool scored = false;
	bool valid = validate(uColor, result);

	if (valid) {
		if (uColor == Colour::RED || uColor == Colour::YELLOW) {
			
			switch (uColor) {
			case(Colour::RED):

				for (int it = roll - 1; it <= 11; ++it) {

					if (redRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}

				redRow[result-2] = "XX";
				redEntriesTotal++;


				break;
			case(Colour::YELLOW):

				for (int it = roll - 1; it <= 11; ++it) {

					if (yellowRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}

				yellowRow[result-2]= "XX";
				yellowEntriesTotal++;

				break;

			}

		}
		else {

			switch (uColor) {

			case(Colour::GREEN):

				for (int it = 13 - roll; it <= 11; ++it) {

					if (greenRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}
				greenRow[12 - result] = "XX";
				greenEntriesTotal++;

				break;
			case(Colour::BLUE):
				for (int it = 13 - roll; it <= 11; ++it) {

					if (blueRow[it] == "XX")
					{
						return false;
					}
					else {
						scored = true;
					}

				}

				blueRow[12-result] = "XX";
				blueEntriesTotal++;


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
	os << "Red      "<<dt.redRow << endl;
	os << "Yellow   "<<dt.yellowRow << endl;
	os << "Green    " <<dt.greenRow << endl;
	os << "Blue     "<< dt.blueRow << endl;
	os << "--------------------------------------" << endl;
	os << "Failed Throw ";
	for (int i = 1; i <= dt.failedAttempts; i++) {
		os << i << " ";
	}

	return os;
	
}
