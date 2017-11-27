#ifndef SCORESHEET_H
#define scoresheet_H
#pragma once

#include "RollOfDice.h"
#include "GameLo"
#include <string>

using namespace std; 

class ScoreSheet
{ 
	string playerName;
	int failedAttempts;
	int overallScore;

public:	
	
	bool score(RollOfDice roll) ; 
	void setTotal(); 
	friend ostream& operator<<(ostream& os, const RollOfDice dt);


private : 
	virtual void print() = 0;
	virtual void calcTotal() = 0; 
	virtual bool operator ~ () = 0; 


};

#endif