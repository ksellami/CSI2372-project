#pragma 
#include "GameLoop.h"
#include <iostream>

using namespace std;

class Dice
{
	const Colour colour; 
	int face; 
public:
	int roll();
	Dice();
	ostream& operator<<(ostream& os);
};

