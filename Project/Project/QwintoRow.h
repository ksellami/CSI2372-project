<<<<<<< HEAD
#ifndef QWINTOROW_H
#define QWINTOROW_H
#pragma once
#include "RollOfDice.h"
#include <array>
#include<iostream>


using namespace std;

template<Colour col> class QwintoRow;
template<Colour col>
inline ostream& operator<<(ostream &os, const QwintoRow<col>& pRow);


template<Colour col> class QwintoRow
{

public:
	array<int, 10> Row;
	int Size(); 
	QwintoRow();
	bool validateEntry(int&);
	int& operator[] (int);
	template<Colour col> friend inline ostream& operator<<(ostream &os, QwintoRow<col>& pRow);
	
};

#endif
=======
>>>>>>> 7666de96b052d0213f011d540228c5799dde7a20
