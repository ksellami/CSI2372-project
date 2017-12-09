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

Dice & Dice::operator=(const Dice & d)
{
	Dice result(d.colour); 
	result.face = d.face; 
	return result ; 
}

bool operator==(const Dice & d1,const Dice & d2)
{
	return d1.colour == d2.colour; 
}

ostream & operator<<(ostream & os, Dice & d)
{

	os << "["<<d.colourToStr(d.colour) << ", " << d.face<<"]";
		return os;

}
