#include "Dice.h"



int Dice::roll()
{
	this->face = 1 + rand() % 6; 
	return this->face; 
}

ostream & Dice::operator<<(ostream & os)
{
	// TODO: insérer une instruction return ici
}

