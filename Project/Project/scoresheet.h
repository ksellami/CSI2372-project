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
<<<<<<< HEAD
<<<<<<< HEAD
	virtual  bool score(RollOfDice roll, Colour uColor, int uPostion = -1) =0;
=======
	virtual bool score(RollOfDice roll, Colour uColor, int uPostion = -1) =0;
>>>>>>> 9ba2be270fdcab921992109970a9a3963264e755
=======
	virtual bool score(RollOfDice& roll, Colour uColor, int uPostion = -1) =0;
>>>>>>> 92fc452a3c33ac5e48b7dab9bb251a2c543fa8c4
	virtual bool validate(Colour&, int&) = 0;
	
	int setTotal();
	void fail();

private : 
	virtual int calcTotal() = 0; 
	virtual bool operator ! () = 0; 

	



};

#endif