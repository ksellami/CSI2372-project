#pragma once
#ifndef QWIXXROW_H
#define QWIXXROW_H

#include "RollOfDice.h"
#include <array>
#include <typeinfo> 
#include<iostream>
#include <list>
using namespace std;

template<class T, Colour col>
class QwixxRow
{

public:
	T Row;
	QwixxRow<T, col>();
	friend QwixxRow<T, col> &operator+=(QwixxRow&, RollOfDice &);
	string& operator[](int param);
	friend ostream& operator<<(ostream &os, QwixxRow<T, col>& pRow) 
	{
			os << "  ";
			for (auto & r : pRow.Row)
				os << "| " << r;

			return os;
	}

};
#endif

template<class T, Colour col>
QwixxRow<T,col>& operator+=(QwixxRow<T,col>& rw,const RollOfDice & rod)
{
	Row += rod; 
	return this; 
}



template<class T, Colour col>
string & QwixxRow<T, col>::operator[](int param){

		
		T::iterator iter = Row.begin();
		std::advance(iter, param); 
		return *iter;
	
}


template<class T, Colour col>
QwixxRow<T, col>::QwixxRow()
{
	//in the constructor we fill the rows
	//depending on which type of container we have 
	//for the row . This is simply because the entries
	// for the green and blue rows are from 12 to 2 from 
	//left to right and backwards for the red and yellow row
	if (typeid(T) == typeid(std::vector<string>)) {
		
		for (int i = 2 ; i< 13 ;i++)
		{
			Row.push_back(std::to_string(i));
			
		}

		//Set the row as unlocked for each row
		Row.push_back("U");
	}
	else if (typeid(T) == typeid(std::list<string>)) {

		for (int i = 12; i> 1; i--)
		{
			Row.push_back(std::to_string(i));

		}
		//Set the row as unlocked for each row
		Row.push_back("U");


	}


}