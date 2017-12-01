#include "RollOfDice.h"



void RollOfDice::roll()
{
	for (auto d : theRoll)
		d.roll(); 

}
RollOfDice RollOfDice::pair(Dice & first, Dice & Second)
{
	RollOfDice result; 
	result.add(first); 
	result.add(Second);
	return result; 

}
void RollOfDice::add(Dice & d)
{
	theRoll.push_back(d); 
}


std::vector<Dice>::iterator RollOfDice::begin()
{
	return theRoll.begin();
}

std::vector<Dice>::const_iterator RollOfDice::begin() const
{
	return theRoll.begin();;
}

std::vector<Dice>::iterator RollOfDice::end()
{
	return theRoll.end();
}

std::vector<Dice>::const_iterator RollOfDice::end() const
{
	return theRoll.end();
}

RollOfDice::operator int()
{

	int somme = 0;
	for (auto d : theRoll) {
		somme += d.face;
	}
	return somme;
}

ostream & operator<<(ostream & os, RollOfDice & rod)
{
	for (Dice d : rod)
		os << d; 

	return os;

}
