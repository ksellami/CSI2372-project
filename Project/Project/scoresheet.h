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
	

public:	
	
	ScoreSheet(string pName);
	virtual bool score(RollOfDice roll, Colour uColor, int uPostion=-1);
	int setTotal(); 
	virtual friend ostream& operator<<(ostream& ,const ScoreSheet& );

private : 
	virtual int calcTotal() = 0; 
	virtual bool operator ! () = 0; 

protected:
	virtual bool validate(Colour&, int&) = 0;
	string playerName;
	int failedAttempts = 0;
	int overallScore = 0;




};

#endif