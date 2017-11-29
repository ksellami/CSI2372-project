#pragma once
#include "RollOfDice.h"
#include <array>
#include<iostream>
using namespace std;

template<class T, Colour col>
class QwixxRow
{
	T Row;
public:
	QwixxRow<T, col>();
	friend QwixxRow<T,col> &operator+=(QwixxRow& ,const RollOfDice &); 
	bool validateEntry(int&); 
	int& operator[](int param);
    friend ostream& operator<<(ostream &os, const QwixxRow<T,col>& pRow);
	
};
