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

	QwintoRow<col>();
	bool validateEntry(int&);
	int& operator[](int&);
	friend ostream& operator<<(ostream &os, QwintoRow<col> pRow);

private:
	array<int, 9> Row;




};



