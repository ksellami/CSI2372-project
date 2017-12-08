#ifndef SCORESHEET_H
#define scoresheet_H
#pragma once

#include "RollOfDice.h"
#include "Colour.h"
#include <string>

using namespace std; 

class ScoreSheet
{ 

	

public:	
	string playerName;
	int failedAttempts = 0;
	int overallScore = 0;
	ScoreSheet(string pName);
	virtual bool score(RollOfDice& roll, Colour uColor, int uPostion = -1) =0;
	virtual bool validate(Colour&, int&) = 0;	
	int setTotal();
	void fail();

private : 
	virtual int calcTotal() = 0; 
	virtual bool operator ! () = 0; 

	



};

#endif