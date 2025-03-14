#include "QwintoScoreSheet.h"




QwintoScoreSheet::QwintoScoreSheet(string NewName) : ScoreSheet(NewName),redEntriesTotal(0),yellowEntriesTotal(0),blueEntriesTotal(0)
{
	
}


// calcultes the total score of one scoresheet

int QwintoScoreSheet::calcTotal()
{
	int total=0;
	if (redEntriesTotal == redRow.Size()-1)
	{
		total += redRow[redRow.Size() - 1];
	}

	else {
		
		for (int i = 0; i < redRow.Size(); i++) {

			if (redRow[i] != 0)
				total++;
		}
	}
	if (yellowEntriesTotal == yellowRow.Size()-1){

		total += yellowRow[yellowRow.Size()-1];
	}
	else {

		for (int i = 0; i < yellowRow.Size(); i++) {

			if (yellowRow[i] != 0)
				total++;
		}
	}
	if (blueEntriesTotal == blueRow.Size()-1){

		total += yellowRow[blueRow.Size() - 1];
	}
	else {

		for (int i = 0; i < blueRow.Size(); i++) {

			if (blueRow[i] != 0)
				total++;
		}
	}

	for (int i = 2; i < 10; i++) {
		if (blueRow[i] != 0 && redRow[i - 2] != 0 && yellowRow[i - 1] != 0)
		{
			switch (i) {

				case 2 :
					total += blueRow[i];
				break;
				
				case 3:
					total += redRow[i-2];
				break;
				
				case 7:
					total += redRow[i-2];
				break;
				
				case 8:
					total += yellowRow[i-1];
				break; 
				
				case 9:
					total += blueRow[i];
				break;
				default :
				break;

			}
				

		}

	}

	total -= failedAttempts * 5;
	
	return total;
}

// this function checks if the position is not and invalid field in the associated color row
//and we call validate entry to see if there is no entry at that position
bool  QwintoScoreSheet::validate(Colour& color, int& position)
{
	bool colorValidated = false;
	switch (color){
		case(Colour::RED) :
			colorValidated = redRow.validateEntry(position);
			if (position == 3)
				colorValidated = false;
		break;
		case(Colour::YELLOW) :
			colorValidated = yellowRow.validateEntry(position);
			if (position == 5)
				colorValidated = false;
		break;
		case(Colour::BLUE) :
			colorValidated = blueRow.validateEntry(position);
			if (position == 4)
				colorValidated = false;
		break;


	}

	return colorValidated;
}

//Checks if the game has ended if there is more or exactly 4 failed throws 
//and if at least two rows has been completed
bool QwintoScoreSheet::operator ! (){

	if (this->failedAttempts>=4){

		return true;
	}

	if (totalRowsCompleted>=2){
		return true;
	}
	
	return false;
}


ostream& operator<<(ostream& os, QwintoScoreSheet& _qwinto){


	os << endl;
	os << "Player name: " << _qwinto.playerName << "\t Points: " << _qwinto.overallScore << std::endl;
	os << "\t\t--------------------------------" << endl;
	os << _qwinto.redRow;
	os << "\t     -----------------------------------" << endl;
	os << _qwinto.yellowRow;
	os << "\t -----------------------------------" << endl;
	os << _qwinto.blueRow;
	os << "\t --------------------------------" << endl;
	os << "Failed throws: ";
	for (int i = 1; i <= _qwinto.failedAttempts; i++) {
		os<< i<<" ";
	}

		
	os <<endl<< endl;
	return os;
}

// this function is to check if all the row entries that are positioned
//after the desired position if they are less and not equal to the roll result

bool QwintoScoreSheet::verify(int position,int result, array<int, 10>& Row) {
	bool valid = false;
	

		for (int i = 0; i < 10; i++) {

			if (i <= position) {

				if (Row[i] < result)
					valid = true;
				else
					return false;
			}
			else {


				if (Row[i] != 0 && Row[i] <= result) {

					return false;
				}
				else
					valid = true;



			}



		}


	
	


	return valid;
}


bool  QwintoScoreSheet::score(RollOfDice& roll, Colour uColor, int uPostion)
{

	bool validRoll;
	//we first see if the player entered a valid position 

	validRoll = validate(uColor, uPostion);
	
	bool scored = false; 

	if (validRoll) {
		int result = roll;
		bool initialCondition;
	
		switch (uColor) {

			case(Colour::RED):
				//the initial condition variable if to see whether there is column restrictions 
				//in an overlapping column can't have the same entries 
				initialCondition = false;

				if (uPostion < 8 && (result == yellowRow[uPostion + 1] ||result == blueRow[uPostion + 2]))
					initialCondition = false;
				else if  (uPostion == 8 && result == yellowRow[9])
					initialCondition = false;
				else
					initialCondition = true;

				// we verify if the entry is valid and we see if the the initial condition is valid
				// to proceed with the scoring procedure
				scored = verify(uPostion,result,redRow.Row) && initialCondition;
				if (scored)
				{
					redRow[uPostion] = roll;
					redEntriesTotal++;
						if (redEntriesTotal == (redRow.Size()-1)){ 

							totalRowsCompleted++;
						}
				}
				else
				{
					cout << "\nNot a valid throw\n" << endl;

				}

			break;

			case(Colour::YELLOW):

				initialCondition = false;

				if (uPostion < 9 && uPostion>0 && (result == redRow[uPostion - 1] || result == blueRow[uPostion + 1]))
					initialCondition = false;
				else
				{
					if (uPostion == 9 && result == redRow[8])
						initialCondition = false;
					else if (uPostion == 0 && result == blueRow[1])
						initialCondition = false;
					else
						initialCondition = true;
				}

				scored = verify(uPostion, result, yellowRow.Row) && initialCondition;

				if (scored)
				{
					yellowRow.operator[](uPostion) = roll;
					yellowEntriesTotal++;
					if (yellowEntriesTotal == (yellowRow.Size()-1)) {

						totalRowsCompleted++;
					}
				}
				else
				{
					cout << "\nNot a valid throw\n" << endl;

				}
			break;

			case(Colour::BLUE):
				initialCondition = false;

				if (uPostion>1 && (result == redRow[uPostion - 2] || result == yellowRow[uPostion-1]))
					initialCondition = false;
				else
				{
					if (uPostion == 1 && result == yellowRow[0])
						initialCondition = false;
				
					else
						initialCondition = true;
				}
			
						
				scored = verify(uPostion, result, blueRow.Row) && initialCondition;

				if (scored)
				{
					blueRow.operator[](uPostion) = roll;
					blueEntriesTotal++;

					if (blueEntriesTotal == (blueRow.Size()-1)) {

						totalRowsCompleted++;
					}
				}
				else
				{
					cout << "\nNot a valid throw\n" << endl;
					
				}

			break;

		}


	}

	

	


	
	return scored;
}


