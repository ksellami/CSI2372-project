#pragma once
#ifndef QWIXXROW_H
#define QWIXXROW_H

#include "RollOfDice.h"
#include <array>
#include<iostream>
using namespace std;

template<class T, Colour col>
class QwixxRow
{

public:
	T Row;
	QwixxRow<T, col>();
	typename T::iterator& itAtPosition(int&);
	friend QwixxRow<T, col> &operator+=(QwixxRow&, RollOfDice &);
	bool validateEntry(int&);
	int& operator[](int param);
	friend ostream& operator<<(ostream &os, QwixxRow<T, col>& pRow) 
	{
			os << "  ";
			for (auto & r : pRow.Row)
				os << "| " << r;

			return os;
	}
#endif
};

template<class T, Colour col>
QwixxRow<T,col>& operator+=(QwixxRow<T,col>& rw,const RollOfDice & rod)
{
	Row += rod; 
	return this; 
}

template<class T, Colour col>
bool QwixxRow<T, col>::validateEntry(int &)
{
	return false;
}

template<class T, Colour col>
int & QwixxRow<T, col>::operator[](int param)
{
	return Row[param];
}


template<class T, Colour col>
QwixxRow<T, col>::QwixxRow()
{
	if (T==std::vector<string>)
		int i = 2;
		for (auto & r : Row)
	{
		r = std::string.to_string(i);
		i++; 
	}
	else if (T == std::list<string>)
			int j = 12;
		for (auto & r : Row)
		{
			r = string.to_string(j);
			j--;
		}
}

template <class T , Colour col>
typename T::iterator& QwixxRow<T, col>::itAtPosition(int &pos)
{
	typename T::iterator iPos ;
	iPos = QwixxRow.Row.begin()+(pos-2);
	



	return iPos;
}


