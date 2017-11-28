#pragma once

#include "RollOfDice.h"
#include <array>
#include<iostream>
#include "RollOfDice.h"
using namespace std;

template<Colour col>
class QwintoRow
{
public:

	int Size {return Row.size}
	QwintoRow<col>();
	bool validateEntry(int&);
	int& operator[](int&);
	friend ostream& operator<<(ostream &os, QwintoRow<col> pRow);


	array<int, 9> Row;




};



