#pragma once
#ifndef QWIXXROW_H
#define QWIXXROW_H

#include "RollOfDice.h"
#include <array>
#include <typeinfo> 
#include<iostream>
using namespace std;

template<class T, Colour col>
class QwixxRow
{

public:
	T Row;
	QwixxRow<T, col>();
	typename T::iterator itAtPosition(int&);
	friend QwixxRow<T, col> &operator+=(QwixxRow&, RollOfDice &);
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
int & QwixxRow<T, col>::operator[](int param)
{
	return Row[param];
}


template<class T, Colour col>
QwixxRow<T, col>::QwixxRow()
{
	if (typeid(T) == typeid(std::vector<string>)) {
		
		for (int i = 2 ; i< 13 ;i++)
		{
			Row.push_back(std::to_string(i));
			
		}

		Row.push_back("U");
	}
	else if (typeid(T) == typeid(std::list<string>)) {

		for (int i = 12; i> 1; i--)
		{
			Row.push_back(std::to_string(i));

		}

		Row.push_back("U");


	}


}

template <class T , Colour col>
typename T::iterator QwixxRow<T, col>::itAtPosition(int &pos)
{
	typename T::iterator iPos ;
	for (iPos; iPos != this->Row.end(); iPos++) {

		if (*iPos == std::to_string(pos))
			return iPos;

	}




	return iPos;
}


