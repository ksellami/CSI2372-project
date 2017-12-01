#ifndef QWINTOROW_H
#define QWINTOROW_H
#pragma once


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
	friend ostream& operator<<(ostream &os, QwintoRow<col>& pRow); 
	
};

#endif
