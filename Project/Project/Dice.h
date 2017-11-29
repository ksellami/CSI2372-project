
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
	friend ostream& operator<<(ostream& os, const Dice& d);
};

