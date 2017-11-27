#include "GameLoop.h"
#include <stdio.h>
#include "RollOfDice.h"
#include "Colour.h"

GameLoop::GameLoop()
{
	RollOfDice rd; 
	Dice d1(Colour::RED); 
	Dice d2(Colour::WHITE);
	Dice d3(Colour::BLUE);
	rd.add(d1); 
	rd.add(d2);
	rd.add(d3);
	for (auto d : rd)
		d.operator<<(std::cout); 
}


GameLoop::~GameLoop()
{
}


int main(){

	GameLoop gm;
}