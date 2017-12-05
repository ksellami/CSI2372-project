#include "QwintoScoreSheet.h"




QwintoScoreSheet::QwintoScoreSheet(string NewName) : ScoreSheet(NewName),redEntriesTotal(0),yellowEntriesTotal(0),blueEntriesTotal(0)
{
	
}



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

	for (int i = 2; i < 11; i++) {
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


bool QwintoScoreSheet::operator ! (){

	if (failedAttempts>=4){

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
bool  QwintoScoreSheet::score(QwintoScoreSheet& sheet, RollOfDice roll, Colour uColor, int uPostion)
{

	bool validRoll;
	validRoll = sheet.validate(uColor, uPostion);
	
	bool scored = false; 

	if (validRoll) {
		int result = roll;
		bool initialCondition;
	
		switch (uColor) {

			case(Colour::RED):
				//For the column restrictions
				initialCondition = false;

				if (uPostion < 8 && (result == sheet.yellowRow[uPostion + 1] ||result == sheet.blueRow[uPostion + 2]))
					initialCondition = false;
				else if  (uPostion == 8 && result == sheet.yellowRow[9])
					initialCondition = false;
				else
					initialCondition = true;

				scored = verify(uPostion,result,sheet.redRow.Row) && initialCondition;
				if (scored)
				{
					sheet.redRow[uPostion] = roll;
					sheet.redEntriesTotal++;
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

				if (uPostion < 9 && uPostion>0 && (result == sheet.redRow[uPostion - 1] || result == sheet.blueRow[uPostion + 1]))
					initialCondition = false;
				else
				{
					if (uPostion == 9 && result == sheet.redRow[8])
						initialCondition = false;
					else if (uPostion == 0 && result == sheet.blueRow[1])
						initialCondition = false;
					else
						initialCondition = true;
				}

				scored = verify(uPostion, result, sheet.yellowRow.Row) && initialCondition;

				if (scored)
				{
					sheet.yellowRow.operator[](uPostion) = roll;
					sheet.yellowEntriesTotal++;
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

				if (uPostion>1 && (result == sheet.redRow[uPostion - 2] || result == sheet.yellowRow[uPostion-1]))
					initialCondition = false;
				else
				{
					if (uPostion == 1 && result == sheet.yellowRow[0])
						initialCondition = false;
				
					else
						initialCondition = true;
				}
			
						
				scored = verify(uPostion, result, sheet.blueRow.Row) && initialCondition;

				if (scored)
				{
					sheet.blueRow.operator[](uPostion) = roll;
					sheet.blueEntriesTotal++;

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


