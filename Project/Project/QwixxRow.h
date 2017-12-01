#ifndef QWIXXROW_H
#define QWIXXROW_H
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
	friend QwixxRow<T,col> &operator+=(QwixxRow& ,RollOfDice &); 
	bool validateEntry(int&); 
	int& operator[](int param);
	template <class X,Colour U>
    friend ostream& operator<<(ostream &os, QwixxRow<X,U>& pRow);
	
};
#endif