#pragma once
#include "Dice.h"
#include <stdio.h>

class RollOfDice 
{
	std::vector<Dice> theRoll;
	

public:
	Colour SelectedColor;
	int selectedPosition; 
	void roll(); 
	RollOfDice pair(Dice& first, Dice & Second); 
	void add(Dice & d); 
	operator int(); 
	std::vector<Dice>::iterator begin();
	std::vector<Dice>::const_iterator begin() const;
	std::vector<Dice>::iterator end();
	std::vector<Dice>::const_iterator end() const;
	friend ostream& operator<<(ostream& os, const RollOfDice& rod);
};

