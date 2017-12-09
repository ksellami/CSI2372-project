#include "QwixxPlayer.h"
#include <sstream>


QwixxPlayer::QwixxPlayer(string name) : sheet(name)
{
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &rod) 
{

	//the white dices are always rolled
	rod.add(Dice(Colour::WHITE));
	rod.add(Dice(Colour::WHITE));

	// checks if the row is unlocked 
	//to roll the corresponding dice's color. 
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
	bool scoringDone = false, fail = false, validSelect = false; 
	while (!scoringDone) {
		string inputColor, inputWhite;
		cout << sheet.playerName << ", in what row do you want to score ? (eg : red)" << endl;
		if (isActive()) {
			cout << "you can type 'fail' to fail the throw" << endl;
		}
		else if (!isActive())
		{
			cout << "you are not the active player, so you are going to score if you want the 2 white dices" << endl; 
			cout << "you can type 'pass' to pass your turn" << endl;
		}
		cout << endl; 
		while (!validSelect) {
			cin >> inputColor;
			if (inputColor == "fail" && isActive()) {
				sheet.fail();
				fail = true;
				scoringDone = true;
				validSelect = true;

			}
			else if (inputColor == "pass" && !isActive()) {
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
				cout << endl;
				cout << "your selection is not valid, please enter a valid colour in the roll" << endl; 
				cout << endl;
			}
		}
		
		
		if (!fail) {
			string scoreType;
			if (isActive()){
				cout << "do you want to score one coloured dice? (you can add a white dice) or score the 2 white dices? type '1' or '2'" << endl;
			while (true) {
				cin >> scoreType;
				if (scoreType == "1" || scoreType == "2") {
					break;
				}
				else {
					cout << "invalid enty, please type 1 or 2" << endl;
					scoreType = "";
				}
			}
		}
			
			RollOfDice lastRod; 
			if (scoreType == "1" && isActive()) {
				cout << endl;
				cout << "chose one white dice you want to add to the coloured dice you choosed" << endl;
				cout << "type 1 for dice " << rod.theRoll[0] << " or type 2 for dice " << rod.theRoll[1] << endl;
				cout << "or just type 0 to not add a white dice" << endl;
				cout << endl;
				while (true) {
					cin >> inputWhite;
					if (inputWhite == "1" || inputWhite == "2" || inputWhite == "0")
						break;
					else {
						cout << endl;
						cout << "invalid selection" << endl;
					}
				}

				lastRod.add(rod.theRoll[index]);

				if (inputWhite == "1" || inputWhite == "2")
					lastRod.add(rod.theRoll[std::stoi(inputWhite) - 1]);
			}
			
			else if (scoreType == "2" || !isActive()) {
				lastRod = rod.pair(rod.theRoll[0], rod.theRoll[1]);
			}

				if (sheet.score(lastRod, theColor))
					scoringDone = true;
				else {
					cout << endl;
					cout << "invalid scoring!" << endl;
					validSelect = false; 
					inputColor = " "; 
					inputWhite = " "; 
					
				}
		}
		
	}
	string LockingInput; 
	if (sheet.redEntriesTotal >= 5 && sheet.redRow[11]=="U") {
		cout << "do you want to lock the red row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.redRow[11] = "L";
			cout << "Red row locked!" << endl;
			rod.theRoll.erase(std::find(rod.begin(), rod.end(),Dice(Colour::RED)));
			cout << "Red Dice removed from the Roll" << endl;
			LockingInput = ""; 
		}
	}
	if (sheet.yellowEntriesTotal >= 5 && sheet.yellowRow[11] == "U") {
		cout << "do you want to lock the yellow row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.yellowRow[11] = "L";
			cout << "Yellow row locked!" << endl;
			rod.theRoll.erase(std::find(rod.begin(), rod.end(),Dice(Colour::YELLOW)));
			cout << "Yellow Dice removed from the Roll" << endl;
			LockingInput = "";

		}
	}
	if (sheet.greenEntriesTotal >= 5 && sheet.greenRow[11] == "U") {
		cout << "do you want to lock the green row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.greenRow[11] = "L";
			cout << "Green row locked!" << endl;
			rod.theRoll.erase(std::find(rod.begin(), rod.end(), Dice(Colour::GREEN)));
			cout << "Green Dice removed from the Roll" << endl;
			LockingInput = "";

		}
	}
	if (sheet.blueEntriesTotal >= 5 && sheet.blueRow[11] == "U" ) {
		cout << "do you want to lock the blue row ? type 'yes' or 'no'" << endl;
		cin >> LockingInput;
		if (LockingInput == "yes") {
			sheet.blueRow[11] = "L";
			cout << "Blue row locked!" << endl; 
			rod.theRoll.erase(std::find(rod.begin(), rod.end(), Dice(Colour::BLUE)));
			cout << "Blue Dice removed from the Roll" << endl; 
			LockingInput = "";
		}
	}
}