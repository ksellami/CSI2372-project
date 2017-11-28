#include "QwintoRow.h"

template <Colour col> int& QwintoRow<col>::operator[](int entry)
{
	return Row[entry];
}

template <Colour col> ostream & operator<<(ostream & os, const QwintoRow<col> &pRow)
{

	if (col == Colour::RED)
	{
		os << "-------------------------------------" << endl;
		os << "  " << "| " << pRow.Row[0] << "% " << pRow.Row[1] << "% "<< pRow.Row[2] << "| " << "XX" << "| " << pRow.Row[3] 
			<< "% " << pRow.Row[4] << "% " << pRow.Row[5] << "| "<< pRow.Row[6] << "| " << pRow.Row[7] << "| " << pRow.Row[8] << "| "<<endl;

	}
	else if (col == Colour::YELLOW)
	{
		os << "-------------------------------------" << endl;
		os <<" "<< "| " << pRow.Row[0] << "| " << pRow.Row[1] << "| " << pRow.Row[2] << "| "<< pRow.Row[3]<< "| " << pRow.Row[4] 
			<< "|" << "XX" << "| " << pRow.Row[5] << "% " << pRow.Row[6] << "% " << pRow.Row[7] << "| " << pRow.Row[8] << "| "<<endl;

		
	}
	else if (col==Colour::BLUE)
	{
		os << "-------------------------------------" << endl;
		os << "| " << pRow.Row[0] << "| " << pRow.Row[1] << "% " << pRow.Row[2] << "% " << pRow.Row[3] << "|" << "XX" << "| "pRow.Row[4]
			<< "| " << pRow.Row[5] << "| " << pRow.Row[6] << "| " << pRow.Row[7] << "% " << pRow.Row[8] << "% "<<endl;

	}

	return os;
}
template <Colour col> bool QwintoRow<col>::validateEntry(int& indexEntry)
{

	if (indexEntry >= 0 && indexEntry < Row.max_size())
		return true;


	return false;
}
template <Colour col> QwintoRow<col>::QwintoRow()
{
	
	for (int i = 0, i < Row.max_size(), i++)
	{

		Row[i] = NULL;
	}

}
