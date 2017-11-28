#include "QwintoScoreSheet.h"



QwintoScoreSheet::QwintoScoreSheet(string NewName) :playerName(NewName)
{
}


void QwintoScoreSheet::print(){


}
int QwintoScoreSheet::calcTotal()
{
	int total;
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

bool QwintoScoreSheet::validate(Colour& color, int& position)
{
	bool colorValidated = false;
	switch (color){
		case(Colour::RED) :
			colorValidated = redRow.validateEntry(position);
		break;
		case(Colour::YELLOW) :
			colorValidated = yellowRow.validateEntry(position);
		break;
		case(Colour::BLUE) :
			colorValidated = blueRow.validateEntry(position);
		break;


	}

	return colorValidated;
}

bool QwintoScoreSheet::operator ! (){

	if (failedAttempts==4){

		return true;
	}

	if (totalRowsCompleted>=2){


		return true;
	}

	return false;
}






