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
	string playerName;
	ScoreSheet(string pName);
	virtual friend ostream& operator<<(ostream&, const ScoreSheet&);
	virtual  bool score(ScoreSheet& sheet,RollOfDice roll, Colour uColor, int uPostion = -1) =0;
	int setTotal();

	void fail();


private : 

	virtual int calcTotal() = 0; 
	virtual bool operator ! () = 0; 

protected:

	virtual bool validate(Colour&, int&) = 0;
	
	int failedAttempts = 0;
	int overallScore = 0;




};

#endif