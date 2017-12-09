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
				os << "Red" << "\t\t";
				for (int i = 0; i < 11; i++) {

					switch (i) {

						case 0:
							os << "|";
						break;
						case 1:
							os << "%";
						break;
						case 2:
							os << "%";
						break;
						case 3:
							os << "|XX";
						break;
						case 5:
							os << "%";
						break;
						case 6:
							os << "%";
						break;
						default:
							os << "|";
						break;
					}
					if (i != 3 && i != 10) {
						if (pRow[i] > 9) {
							os << pRow[i];
						}
						else if (pRow[i] < 10 && pRow[i] != 0) {
							os << " " << pRow[i];
						}
						else { 
							os << "  ";
						}

					}

				}

				os << endl;

			}
			else if (col == Colour::YELLOW)
			{

				os << "Yellow" << "\t     ";
				for (int i = 0; i < 11; i++) {
					switch (i) {
					case 5:
						os << "|XX";
						break;
					case 7:
						os << "%";
						break;
					case 8:
						os << "%";
						break;
					default:
						os << "|";
						break;
					}
					if (i != 5 && i != 10) {
						if (pRow[i] > 9) { 

							os << pRow[i]; 
						}
						else if (pRow[i] < 10 && pRow[i] != 0) {
							os << " " << pRow[i]; 
						}
						else { 
							os << "  "; 
						}
					}
				}

				os << endl;


			}
			else if (col == Colour::BLUE)
			{
				os << "Blue" << "      ";
				for (int i = 0; i < 11; i++) {
					switch (i) {
					case 4:
						os << "|XX";
						break;
					case 2:
						os << "%";
						break;
					case 3:
						os << "%";
						break;
					case 9:
						os << "%";
						break;
					case 10:
						os << "%";
						break;
					default:
						os << "|";
						break;
					}
					if (i != 4 && i != 10) {
						if (pRow[i] > 9) { 
							os << pRow[i]; 
						}
						else if (pRow[i] < 10 && pRow[i] != 0) { 
							os << " " << pRow[i]; 
						}
						else { 
							os << "  "; 
						}
					}
				}
				os << endl;
			}
			return os; 
		}
};

#endif


template <Colour col> int& QwintoRow<col>::operator[](int index)
{
	return Row[index];
}

// we check if the position entered by the player is 
// within the row boundaries and if the element at that position
// is not taken
template <Colour col> bool QwintoRow<col>::validateEntry(int& indexEntry)
{

	bool valid = false;

	if (indexEntry >= 0 && indexEntry < static_cast<int>(Row.max_size()))
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

	for (int i = 0; i < static_cast<int>(Row.max_size()); i++) {

		Row[i] = 0;
	}
		
	

}
