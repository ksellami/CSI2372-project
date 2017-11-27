#ifndef SCORESHEET_H
#define scoresheet_H
#pragma once

#include "RollOfDice.h"
#include "Colour.h"
#include "QwintoRow.h"
#include <string>

using namespace std; 

class ScoreSheet
{ 
	string playerName;
	int failedAttempts=0;
	int overallScore=0;

public:	
	
	ScoreSheet();
	ScoreSheet(string pName);
	bool score(RollOfDice roll, Colour uColor, int uPostion=-1);
	void setTotal(); 
	friend ostream& operator<<(ostream& os, const RollOfDice dt);


private : 
	virtual void print() = 0;
	virtual void calcTotal() = 0; 
	virtual bool operator ~ () = 0; 

protected:
	virtual bool validate(Colour&, int&) = 0;




};

#endif