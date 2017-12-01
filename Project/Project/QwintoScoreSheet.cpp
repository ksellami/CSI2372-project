#include "QwintoScoreSheet.h"




QwintoScoreSheet::QwintoScoreSheet(string NewName) : ScoreSheet(NewName),redEntriesTotal(0),yellowEntriesTotal(0),blueEntriesTotal(0)
{
	
}



int QwintoScoreSheet::calcTotal()
{
	int total=0;
	if (redEntriesTotal == redRow.Row.max_size())
	{
		total += redRow.Row[redRow.Row.max_size() - 1];
	}
	if (yellowEntriesTotal == yellowRow.Row.max_size()){

		total += yellowRow.Row[yellowRow.Row.max_size()-1];
	}
	if (blueEntriesTotal == blueRow.Row.max_size()){

		total += yellowRow.Row[blueRow.Row.max_size() - 1];
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
			if (position = 3)
				colorValidated = false;
		break;
		case(Colour::YELLOW) :
			colorValidated = yellowRow.validateEntry(position);
			if (position = 5)
				colorValidated = false;
		break;
		case(Colour::BLUE) :
			colorValidated = blueRow.validateEntry(position);
			if (position = 4)
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
	os << "Player Name :" << _qwinto.playerName << '\t' << '\t' << "Points: "<<_qwinto.overallScore <<endl ;
	os <<'\t'<<"-------------------------------------" << endl;

	os <<"Red"<<"   "<< _qwinto.redRow;

	os << "Yellow" << "   " << _qwinto.yellowRow;

	os << "Blue" << "   " << _qwinto.blueRow;

	os << "-------------------------------------" << endl;

	os << "Failed Throw";
	//for (int i = 0;)
	return os;
}

bool  QwintoScoreSheet::score(QwintoScoreSheet& sheet, RollOfDice roll, Colour uColor, int uPostion)
{

	bool validRoll;
	validRoll = sheet.validate(uColor, uPostion);
	
	bool scored = false; 

	if (validRoll) {
		int result = (int)roll;
		
		switch (uColor) {

			case(Colour::RED):
				
				for (int i = 0; i < uPostion; i++)
				{
					if (sheet.redRow[i] <= result)
					{
				

						
						if (i < 8 && (result == sheet.yellowRow[i + 1] || result == sheet.blueRow[i + 2]))
							scored = false;
						
						else if (i == 8 && result == sheet.yellowRow[9])
							scored = false;

						else
							scored = true;
						

					}

					
				}

				if (scored)
				{
					sheet.redRow[uPostion] = roll;
					sheet.redEntriesTotal++;
						if (redEntriesTotal == redRow.Size()){ 

							totalRowsCompleted++;
						}
				}
				else
				{
					sheet.fail();
					
				}

			break;

			case(Colour::YELLOW):
				//QwintoRow<Colour::YELLOW> row = sheet.yellowRow;
				for (int i = 0; i < uPostion; i++) 
				{
					if (sheet.yellowRow.operator[](i) <= result)
					{
						if (i < 9 && i>0 && (result == sheet.redRow[i -1] || result == sheet.blueRow[i + 1]))
							scored = false;

						else
						{
							if (i == 9 && result == sheet.redRow[8])
								scored = false;
							else if (i == 0 && result == sheet.blueRow[1])
								scored = false;
							else
								scored = true;
						}
					}
					
				}

				if (scored)
				{
					sheet.yellowRow.operator[](uPostion) = roll;
					//row[uPostion] = roll;
					sheet.yellowEntriesTotal++;
					if (yellowEntriesTotal == yellowRow.Size()) {

						totalRowsCompleted++;
					}
				}
				else
				{
					sheet.fail();
					
				}
			break;

			case(Colour::BLUE):
				//QwintoRow<Colour::BLUE> row = sheet.blueRow;
				for (int i = 0; i < uPostion; i++) 
				{
					if (sheet.blueRow.operator[](i) <= result)
					{
						
						if (i>1 && (result == sheet.redRow[i-2] || result == sheet.yellowRow[i-1]))
							scored = false;

						else
						{
							
							if (i == 1 && result == sheet.yellowRow[0])
								scored = false;
							else
								scored = true;
						}
					}
					
				}

				if (scored)
				{
					sheet.blueRow.operator[](uPostion) = roll;
					//row[uPostion] = roll;
					sheet.blueEntriesTotal++;

					if (blueEntriesTotal == blueRow.Size()) {

						totalRowsCompleted++;
					}
				}
				else
				{
					sheet.fail();
				}

			break;

		}


	}

	else {


		cout << "Not a valid throw" << endl;
	}

	


	
	return scored;
}


