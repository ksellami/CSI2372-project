#include "QwixxPlayer.h"
#include <sstream>


QwixxPlayer::QwixxPlayer(string name) : sheet(name)
{
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &_rollOfDice) {

	Dice red = Dice(Colour::RED);
	_rollOfDice.add(red);
	Dice green = Dice(Colour::GREEN);
	_rollOfDice.add(green);
	Dice yellow = Dice(Colour::YELLOW);
	_rollOfDice.add(yellow);
	Dice blue = Dice(Colour::BLUE);
	_rollOfDice.add(blue);
	Dice white1 = Dice(Colour::WHITE);
	_rollOfDice.add(white1);
	Dice white2 = Dice(Colour::WHITE);
	_rollOfDice.add(white2);

	/*bool validSelection = false;

	while (!validSelection) {
		cout << sheet.playerName << ", Please enter the color you would like to enter the white dice [" << int(_rollOfDice) << "] in.";

		cout << "(Or you can pass)" << endl;

		string input = "";
		cin >> input;

		if (input == "pass") {
			validSelection = true;
		}

		if (input == "red") {
			if (sheet.score(sheet,_rollOfDice, Colour::RED)) {
				validSelection = true;
			}
		}
		else if (input == "yellow") {
			if (sheet.score(sheet,_rollOfDice, Colour::YELLOW)) {
				validSelection = true;
			}
		}
		else if (input == "green") {
			if (sheet.score(sheet,_rollOfDice, Colour::GREEN)) {
				validSelection = true;
			}
		}
		else if (input == "blue") {
			if (sheet.score(sheet,_rollOfDice, Colour::BLUE)) {
				validSelection = true;
			}
		}
		if (!validSelection)
			cout << sheet.playerName << ", THAT WAS IN INVALID SELECTION!" << endl << endl;
	}*/

}


void QwixxPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {
	bool validSelection = false, scored = false, failed = false;
	Colour c; 
	string input, color;
	int selectedColorDice;
	while (!scored) {
		cout << sheet.playerName << ", Please enter the name of the colored dice you would like to score (or type fail): " << endl;

		validSelection = false;
		while (!validSelection) {
			input = "";
			cin >> input;
			if (input == "fail") {
				sheet.fail();
				validSelection = true;
				failed = true;
				scored = true;
			}
			if (input == "red") {
				c = Colour::RED;
				selectedColorDice = 0;
				validSelection = true;
				color = input;
			}
			else if (input == "green") {
				c = Colour::GREEN;
				selectedColorDice = 1;
				validSelection = true;
				color = input;
			}
			else if (input == "yellow") {
				c = Colour::YELLOW;
				selectedColorDice = 2;
				validSelection = true;
				color = input;
			}
			else if (input == "blue") {
				c = Colour::BLUE;
				selectedColorDice = 3;
				validSelection = true;
				color = input;
			}
			if (!validSelection) {
				cout << "INVALID SELECTION! (please type one of: red yellow green blue)";
			}

		}
		validSelection = false;
		if (!failed) {
			int selection = 0;
			while (!validSelection) {
				input = "";
				cout << "Please enter 5 for white dice [" << _rollOfDice.theRoll[4].face << "] or enter 6 for white dice [" << _rollOfDice.theRoll[5].face << "]" << endl;
				cin >> input;
				stringstream asdf(input);
				if (asdf >> selection && (selection == 5 || selection == 6))
					validSelection = true;
			}

			validSelection = false;

			RollOfDice pair = _rollOfDice.pair(_rollOfDice.theRoll[selection - 1], _rollOfDice.theRoll[selectedColorDice]);

			input = "";
			cout << "Type \"yes\" to confirm your move of " << color << ", " << int(pair) << endl;
			cin >> input;
			if (input == "yes") {
				if (sheet.score(sheet,pair, c)) {
					scored = true;
				}
				else {
					cout << "That is an invalid move" << endl;
				}
			}
		}
	}

}