#include "RollOfDice.h"



RollOfDice::RollOfDice()
{
}
void RollOfDice::roll()
{
	for (Dice d : theRoll)
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

ostream & RollOfDice::operator<<(ostream & os)
{
	for (Dice d : theRoll)
		d.Dice::operator<<(os); 
} 

RollOfDice::operator int()
{

	int somme = 0;
	for (Dice dc : theRoll) {
		somme += dc.face;
	}
	return somme;
}