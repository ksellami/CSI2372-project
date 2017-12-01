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
	face = rand.DrawNumber(1, 6); 
	return face; 
}

Dice::Dice(const Colour& _col) :
	colour(_col)
{
}

ostream & operator<<(ostream & os, Dice & d)
{

		os << "the colour is :" << d.colourToStr(d.colour) << ", the number is: " << d.face << std::endl;
		return os;

}
