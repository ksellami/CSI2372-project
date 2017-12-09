#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(string name) :ScoreSheet(name)
{

	
}

//this function is to calculate the score with the number of entries of a row 
//as a parameter . This follows the table given in the assignment
//the points for a certain amount of entries is the sum of the numbers from
//1 to the numbersofentries included .
int QwixxScoreSheet::calcScore(int & entriesNum)
{
	int result = 0;

		
	for (int i = 1; i <= entriesNum; i++) {

		result = i + result;

	}
	
		return result;
}

//calculate the total score for a scoresheet
int QwixxScoreSheet::calcTotal()
{
	int total = 0;
	//calls function calcscore for each row
	total += this->calcScore(redEntriesTotal);
	total += this->calcScore(yellowEntriesTotal);
	total += this->calcScore(greenEntriesTotal);
	total += this->calcScore(blueEntriesTotal);

	total -= this->failedAttempts * 5;

	return total;
}

//function returns true if the ending game conditions are met
bool QwixxScoreSheet::operator!()
{
	
	int lockedRows = 0;

	//if failed throws are 4 or more
	if (failedAttempts >= 4)
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

	//if two or more rows are locked return true
	if (lockedRows >= 2) {

		return true;
	}
	
	
	
	return false;
}

//this function is to validate a roll result before scoring it.
//it checks if the roll is already recorded on the scoresheet
//in that or if that row is locked . If so the player cannot record 
//the roll .
 bool QwixxScoreSheet::validate(Colour &uColor, int &roll)
{
	 //if the roll is not within the row's boundaries
	 //the roll is not valid
	 if (roll < 2 || roll > 12)
		 return false; 
	 //check if the row is locked or if the roll is 
	 //already recorded in that row
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

//This is the main function that verifies if a roll is valid
 //and records if it is on the scoresheet.
bool QwixxScoreSheet::score(RollOfDice &roll, Colour uColor,int uPosition)
{
	
	int result = roll;
	bool scored = false;
	bool valid = validate(uColor, result);

	if (valid) {
		
		if (uColor == Colour::RED || uColor == Colour::YELLOW) {
			//for the red and the yellow row the entries 
			//are in the same order . Here we check if the entries 
			//that are positioned after the roll position are recorded
			//if so we cannot record the roll since we cannot go back in a row from right to left.

			switch (uColor) {
			case(Colour::RED):

				for (int it = roll - 1; it <= 10; ++it) {

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

				for (int it = roll - 1; it <= 10; ++it) {

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
				//for the green and the blue row the entries 
				//are in the same order . Here we check if the entries 
				//that are positioned after the roll position are recorded
				//if so we cannot record the roll since we cannot go back in a row from right to left.
				// the only difference is that the entries are backwards . 
				for (int it = 13 - roll; it <= 10; ++it) {

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
				for (int it = 13 - roll; it <= 10; ++it) {

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

//Prints ou the scoresheet
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
	//print out the failed attempts each time
	//there is a failed throw
	for (int i = 1; i <= dt.failedAttempts; i++) {
		os << i << " ";
	}

	return os;
	
}
