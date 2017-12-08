#ifndef DICE_H
#define DICE_H
#include "Colour.h"
#include <iostream>
#include <vector> 
#include <string>
#include "RandomDice.h"


using namespace std;

class Dice
{
	RandomDice rand; 
	
public:
	const Colour colour;
	int face;
	string colourToStr(const Colour& _col); 
	int roll();
	Dice(const Colour& _col);
	friend bool operator==(const Dice&,const Dice&); 
	friend ostream& operator<<(ostream& os, Dice& d);
};

#endif