#ifndef QWINTOROW_H
#define QWINTOROW_H

#include "RollOfDice.h"
#include <array>
#include<iostream>

using namespace std;

template<Colour col>
class QwintoRow
{

public:
	array<int, 10> Row;
	int Size();
	QwintoRow();
	bool validateEntry(int&);
	int& operator[] (int);
	friend ostream& operator<<(ostream &os, QwintoRow<col>& pRow) {
			if (col == Colour::RED)
			{
				os << "-------------------------------------" << endl;
				os << "  " << "| " << pRow.Row[0] << "% " << pRow.Row[1] << "% " << pRow.Row[2] << "| " << "XX" << "| " << pRow.Row[4]
					<< "% " << pRow.Row[5] << "% " << pRow.Row[6] << "| " << pRow.Row[7] << "| " << pRow.Row[8] << "| " << pRow.Row[9] << "| " << endl;

			}
			else if (col == Colour::YELLOW)
			{
				os << "-------------------------------------" << endl;
				os << " " << "| " << pRow.Row[0] << "| " << pRow.Row[1] << "| " << pRow.Row[2] << "| " << pRow.Row[3] << "| " << pRow.Row[4]
					<< "|" << "XX" << "| " << pRow.Row[6] << "% " << pRow.Row[7] << "% " << pRow.Row[8] << "| " << pRow.Row[9] << "| " << endl;


			}
			else if (col == Colour::BLUE)
			{
				os << "-------------------------------------" << endl;
				os << "| " << pRow.Row[0] << "| " << pRow.Row[1] << "% " << pRow.Row[2] << "% " << pRow.Row[3] << "|" << "XX" << "| " << pRow.Row[5]
					<< "| " << pRow.Row[6] << "| " << pRow.Row[7] << "| " << pRow.Row[8] << "% " << pRow.Row[9] << "% " << endl;

			}
			return os; 
		}
};

#endif


template <Colour col> int& QwintoRow<col>::operator[](int index)
{
	return Row[index];
}

template <Colour col> bool QwintoRow<col>::validateEntry(int& indexEntry)
{

	bool valid = false;

	if (indexEntry > 0 && indexEntry < Row.max_size())
		valid = true;

	if ((int)Row[indexEntry] != 0)
		valid = false;


	return valid;
}

template<Colour col> int QwintoRow<col>::Size()
{
	return Row.size(); 
}

template <Colour col> QwintoRow<col>::QwintoRow()
{

	for (int i = 0; i < Row.max_size(); i++)
		Row[i] = 0;
	

}
