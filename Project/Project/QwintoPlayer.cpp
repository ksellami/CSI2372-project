#include "QwintoPlayer.h"
#include "Colour.h"
#include <string>
QwintoPlayer::QwintoPlayer(string name) : sheet(name) {}

void QwintoPlayer::inputBeforeRoll(RollOfDice &_rollOfDice) {

	string entry = "";
	
	vector<string> Colors;
	
	while (entry != "yes") {

		Colors.clear();

		cout << "Select the color of the dice you want to roll" << endl;

		cout << "Please choose either Red , Blue or Yellow" << endl;

		cout << "enter ok when you are done" << endl;

		vector<string> entries;
		vector<string>::iterator it;
			
		
		
		
		
			


		// to verify player input

		int validColor = 0;
		while (validColor == 0) {

			while (entry != "ok") {
				cin >> entry;
				entries.push_back(entry);

			}

			entries.pop_back();
			for (vector<string>::iterator it = entries.begin(); it != entries.end(); it++) {

				if (*it == "blue" || *it == "red" || *it == "yellow") {

					Colors.push_back(*it);
					validColor++;


				}
				else {


					cout << *it << " is not a valid color" << endl;
				}

			}

			if (validColor == 0) {


				cout << "No valid color was entered \nChoose blue, red or yellow" << endl;
				cout << endl;
				entry = "";
			}

		}
	
	
		cout << "You rolled the " << endl;

		for (vector<string>::iterator i = Colors.begin(); i != Colors.end(); i++) {
			cout << *i <<" dice"<< endl;
		}
		cout << "type \"yes\" to confirm roll:" << endl;
		entry = "";
		cin >> entry;
	}

	if (std::find(Colors.begin(), Colors.end(), "red") != Colors.end()) {
		Dice dice = Dice(Colour::RED);
		_rollOfDice.theRoll.push_back(dice);
	}

	if (std::find(Colors.begin(), Colors.end(), "yellow") != Colors.end()) {
		Dice dice = Dice(Colour::YELLOW);
		_rollOfDice.theRoll.push_back(dice);
	}

	if (std::find(Colors.begin(), Colors.end(), "blue") != Colors.end()) {
		Dice dice = Dice(Colour::BLUE);
		_rollOfDice.theRoll.push_back(dice);
	}

}

<<<<<<< HEAD

void QwintoPlayer::inputAfterRoll(RollOfDice &rod) {
=======
//Not yet changed
void QwintoPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {
>>>>>>> 02f6909973754dea1be84a9866a0e8bb6bbca5e5

	bool rowSelection = false, blue = false, yellow = false, red = false, scoringDone=false;
	string inputFS; 
	Colour theColor = Colour::WHITE; 
	int columnSelection=0; 

	for (auto &d : rod) {
		switch (d.colour) {
		case Colour::RED:
			red = true;
			break;
		case Colour::YELLOW:
			yellow = true;
			break;
		case Colour::BLUE:
			blue = true;
			break;
		}
		}

	while (!scoringDone) {
		cout << "in what row you want to score the roll? (eg yellow)" << endl;

		if (!isActive()) {
			cout << "You can also enter 'pass' to skip with no penalty " << endl;
		}
		if (isActive()) {
			cout << "You can also enter 'fail' to fail the throw " << endl;
		}

		while (!rowSelection) {
			cin >> inputFS;
			if (inputFS == "pass" && !isActive())
				return;
			else if (inputFS == "fail" && isActive()) {
				sheet.fail();
				return;
			}
			else if (inputFS == "red" && red) {
				theColor = Colour::RED;
				rowSelection = true;
			}
			else if (inputFS == "yellow" && yellow) {
				theColor = Colour::YELLOW; 
				rowSelection = true;
			}
			else if (inputFS == "blue" && blue) {
				theColor = Colour::BLUE;
				rowSelection = true;
			}
			else
				cout << "invalid entry, or the color selected is not in the roll" << endl;
			
		}

		rowSelection = false; 
		inputFS = ""; 
		cout << "in what row you column (1-9) you want to score the roll?" << endl;

		while (columnSelection < 1 || columnSelection>9) {
			cin >> columnSelection;
			if (columnSelection < 1 && columnSelection>9) {
				cout << "invalid Selection!" << endl;
				columnSelection = 0;
			}
		}
		if (sheet.score(sheet, rod, theColor, columnSelection - 1))
			scoringDone = true;
		else {
			cout << "invalid selection!" << endl;
			columnSelection = 0;

		}
	}
}

