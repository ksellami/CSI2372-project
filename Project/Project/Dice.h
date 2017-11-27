#pragma 
#include "Colour.h"
#include <iostream>

using namespace std;

class Dice
{
	const Colour colour; 
	int face; 
public:
	string colourToStr(const Colour& _col); 
	int roll();
	Dice(const Colour& _col);
	ostream& operator<<(ostream& os);
};

