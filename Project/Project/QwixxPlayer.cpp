#include "QwixxPlayer.h"
#include <sstream>


QwixxPlayer::QwixxPlayer(string name) : sheet(name)
{
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &rod) {


	rod.add(Dice(Colour::RED));
	rod.add(Dice(Colour::YELLOW));
    rod.add(Dice(Colour::GREEN));
	rod.add(Dice(Colour::BLUE));
	rod.add(Dice(Colour::WHITE));
	rod.add(Dice(Colour::WHITE));

}


void QwixxPlayer::inputAfterRoll(RollOfDice &rod) {
	int index; 
	Colour theColor; 
	bool scoringDone = false, fail = false, validSelect = false; 
	string inputColor,inputWhite,inputConfirmation;
	while (!scoringDone) {
		cout << sheet.playerName << ", in what row do you want to score ? (eg : red)" << endl;
		cout << "you can type 'fail' to fail the throw" << endl;
		cout << endl; 
		while (!validSelect) {
			cin >> inputColor;
			if (inputColor == "fail") {
				sheet.fail();
				fail = true;
				scoringDone = true;
				validSelect = true;
			}
			else if (inputColor == "red" ) {
				validSelect = true;
				theColor = Colour::RED; 
				index = 0; 
			}
			else if (inputColor == "yellow") {
				validSelect = true;
				theColor = Colour::YELLOW;
				index = 1; 
			}
			else if (inputColor == "green") {
				validSelect = true;
				theColor = Colour::GREEN;
				index = 2; 
			}
			else if (inputColor == "blue") {
				validSelect = true;
				theColor = Colour::BLUE;
				index = 3;
			}
			else {
				cout << "your selection is not valid" << endl; 
				cout << endl;
				inputColor = ""; 
			}
		}
		
		
		if(!fail) {
			
			cout << "chose one white dice you want to add to the roll:" << endl; 
				cout << "type 1 for dice " << rod.theRoll[4] << " or type 2 for dice " << rod.theRoll[5] << endl;
				cout << endl;
				while (inputWhite != "1" && inputWhite != "2") {
					cin >> inputWhite; 
					if (inputWhite != "1" && inputWhite != "2") {
						cout << "invalid selection" << endl;
						cout << endl;
						inputWhite == ""; 
					}
				}
				RollOfDice lastRod = rod.pair(rod.theRoll[index], rod.theRoll[std::stoi(inputWhite) + 4]); 
				cout << "this is your selection: " << inputColor << ", " << (int)lastRod << endl; 
				cout << "enter to continue " << endl; 
				cout << endl;

				while (inputConfirmation != "") {
					cin >> inputConfirmation;
					if (inputConfirmation != "") {
						cout << "just confirm please!" << endl;
						cout << endl;
						inputConfirmation == "";
					}
				}

				if (sheet.score(sheet, lastRod, theColor))
					scoringDone = true;
				else {
					cout << "invalid scoring!" << endl;
					cout << endl;
				}
		}
	}
	string decision; 
	if (sheet.redEntriesTotal >= 5) {
		cout << "do you want to lock the red row ? type 'yes' or enter to ignore" << endl;
		cin >> decision;
		if (decision == "yes")
			sheet.redRow[11] == "L";
	}
	else if (sheet.yellowEntriesTotal >= 5) {
		cout << "do you want to lock the yellow row ? type 'yes' or enter to ignore" << endl;
		cin >> decision;
		if (decision == "yes")
			sheet.yellowRow[11] == "L";
	}
	else if (sheet.greenEntriesTotal >= 5) {
		cout << "do you want to lock the green row ? type 'yes' or enter to ignore" << endl;
		cin >> decision;
		if (decision == "yes")
			sheet.greenRow[11] == "L";
	}
	else if (sheet.blueEntriesTotal >= 5) {
		cout << "do you want to lock the blue row ? type 'yes' or enter to ignore" << endl;
		cin >> decision;
		if (decision == "yes")
			sheet.blueRow[11] == "L";
	}
}