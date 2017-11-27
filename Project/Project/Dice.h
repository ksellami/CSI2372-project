#pragma 
#include "Colour.h"
#include <iostream>
#include <vector> 
#include <string>


using namespace std;

class Dice
{
	const Colour colour; 
	 
public:
	int face;
	string colourToStr(const Colour& _col); 
	int roll();
	Dice(const Colour& _col);
	ostream& operator<<(ostream& os);
};

