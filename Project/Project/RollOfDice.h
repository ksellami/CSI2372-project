#ifndef ROLLOFDICE_H
#define ROLLOFDICE_H
#pragma once
#include "Dice.h"


class RollOfDice 
{
	
	

public:
	std::vector<Dice> theRoll;
	void roll(); 
	RollOfDice pair(Dice& first, Dice & Second); 
	void add(Dice & d); 
	operator int(); 
	std::vector<Dice>::iterator begin();
	std::vector<Dice>::const_iterator cbegin() const;
	std::vector<Dice>::iterator end();
	std::vector<Dice>::const_iterator cend() const;
	friend ostream& operator<<(ostream& os, RollOfDice& rod);
};

#endif