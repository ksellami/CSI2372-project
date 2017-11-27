#include "Dice.h"

string Dice::colourToStr(const Colour& _col)
{
	switch (_col) {
	case Colour::WHITE: return "white";
	case Colour::RED: return "red";
	case Colour::YELLOW: return "yellow";
	case Colour::GREEN: return "green";
	case Colour::BLUE: return "blue";
	default: return "type not reconized";
	}
}

int Dice::roll()
{
	this->face = 1 + rand() % 6; 
	return this->face; 
}

Dice::Dice(const Colour& _col) :
	colour(_col)
{
}

ostream & Dice::operator<<(ostream & os)
{
	
	os << "the colour is :" << Dice::colourToStr(colour) << ", the number is: " << face << std::endl ;
	return os; 
}