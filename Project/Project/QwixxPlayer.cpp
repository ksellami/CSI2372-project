#include "QwixxPlayer.h"
#include <sstream>


QwixxPlayer::QwixxPlayer(string name) : sheet(name)
{
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &rod) {

	rod.add(Dice(Colour::WHITE));
	rod.add(Dice(Colour::WHITE));

	if (sheet.redRow[11]=="U")
	rod.add(Dice(Colour::RED));

	if (sheet.yellowRow[11] == "U")
	rod.add(Dice(Colour::YELLOW));

	if (sheet.greenRow[11] == "U")
    rod.add(Dice(Colour::GREEN));

	if (sheet.blueRow[11] == "U")
	rod.add(Dice(Colour::BLUE));
}


void QwixxPlayer::inputAfterRoll(RollOfDice &rod) {
	int index; 
	Colour theColor; 
	bool scoringDone = false, fail = false, validSelect = false, askedSecondScore=false; 
	string inputColor,inputWhite;
	while (!scoringDone) {
		cout << sheet.playerName << ", in what row do you want to score ? (eg : red)" << endl;
		if (isActive()) {
			cout << "you can type 'fail' to fail the throw" << endl;
		}
		else if (!isActive())
		{
			cout << "you can type 'pass' to pass your turn" << endl;
		}
		cout << endl; 
		while (!validSelect) {
			cin >> inputColor;
			if (inputColor == "fail") {
				sheet.fail();
				fail = true;
				scoringDone = true;
				validSelect = true;
			}
			else if (inputColor == "pass") {
				fail = true;
				scoringDone = true;
				validSelect = true;
			}
			else if (inputColor == "red" && sheet.redRow[11]=="U") {
				validSelect = true;
				theColor = Colour::RED; 
				index = std::find(rod.theRoll.begin(),rod.theRoll.end(),Dice(theColor)) - rod.theRoll.begin() ;
				
			}
			else if (inputColor == "yellow"&& sheet.yellowRow[11] == "U") {
				validSelect = true;
				theColor = Colour::YELLOW;
				index = std::find(rod.theRoll.begin(), rod.theRoll.end(), Dice(theColor)) - rod.theRoll.begin();
			}
			else if (inputColor == "green"&& sheet.greenRow[11] == "U") {
				validSelect = true;
				theColor = Colour::GREEN;
				index = std::find(rod.theRoll.begin(), rod.theRoll.end(), Dice(theColor)) - rod.theRoll.begin();
			}
			else if (inputColor == "blue" && sheet.blueRow[11] == "U") {
				validSelect = true;
				theColor = Colour::BLUE;
				index = std::find(rod.theRoll.begin(), rod.theRoll.end(), Dice(theColor)) - rod.theRoll.begin();
			}
			else {
				cout << "your selection is not valid" << endl; 
				cout << endl;
				inputColor = ""; 
			}
		}
		
		
		if(!fail) {
			
			cout << "chose one white dice you want to add to the roll:" << endl; 
				cout << "type 1 for dice " << rod.theRoll[0] << " or type 2 for dice " << rod.theRoll[1] << endl;
				cout << endl;
				while (inputWhite != "1" && inputWhite != "2") {
					cin >> inputWhite; 
					if (inputWhite != "1" && inputWhite != "2") {
						cout << "invalid selection" << endl;
						cout << endl;
						inputWhite == ""; 
					}
				}
				RollOfDice lastRod = rod.pair(rod.theRoll[index], rod.theRoll[std::stoi(inputWhite) -1]); 
				cout << "this is your selection: " << inputColor << ", " << (int)lastRod << endl; 
				cout << "enter to continue " << endl; 
				cin.ignore(); 
				cout << endl;

				if (sheet.score(lastRod, theColor))
					scoringDone = true;
				else {
					cout << "invalid scoring!" << endl;
					cout << endl;
				}
		}
		if (scoringDone && isActive() && !askedSecondScore) {
			//cout << "do you want to score a second time ?" << endl; 
		}
	}
	string LockingInput; 
	if (sheet.redEntriesTotal >= 5) {
		cout << "do you want to lock the red row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.redRow[11] == "L";
			cout << "Red row locked!" << endl;
			//rod.theRoll.erase(rod.theRoll.begin()); 
			cout << "Yellow Dice removed from the Roll" << endl;
			LockingInput = ""; 
		}
	}
	if (sheet.yellowEntriesTotal >= 5) {
		cout << "do you want to lock the yellow row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.yellowRow[11] == "L";
			cout << "Yellow row locked!" << endl;
			//rod.theRoll.erase(rod.theRoll.begin()+1);
			cout << "Yellow Dice removed from the Roll" << endl;
			LockingInput = "";

		}
	}
	if (sheet.greenEntriesTotal >= 5) {
		cout << "do you want to lock the green row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.greenRow[11] == "L";
			cout << "Green row locked!" << endl;
			//rod.theRoll.erase(rod.theRoll.begin()+2);
			cout << "Green Dice removed from the Roll" << endl;
			LockingInput = "";

		}
	}
	if (sheet.blueEntriesTotal >= 5) {
		cout << "do you want to lock the blue row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.blueRow[11] == "L";
			cout << "Blue row locked!" << endl; 
			//rod.theRoll.erase(rod.theRoll.begin()+3);
			cout << "Blue Dice removed from the Roll" << endl; 
			LockingInput = "";
		}
	}
}