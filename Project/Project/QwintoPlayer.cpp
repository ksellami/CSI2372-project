#include "QwintoPlayer.h"
#include "Colour.h"
#include <string>
QwintoPlayer::QwintoPlayer(string name) : sheet(name) {}

void QwintoPlayer::inputBeforeRoll(RollOfDice &_rollOfDice) {
	string tmp = "";
	vector<string> refinedSelection;
	while (tmp != "yes") {
		refinedSelection.clear();
		cout << "Please select the dice you would like to roll, type \"done\" when finished: " << endl;
		cout << "(e.g. red blue yellow done):" << endl;
		vector<string> selection;
		vector<string>::iterator it;
		string input = "";

		while (input != "done" || (input != "pass" && isActive() == false)) {
			cin >> input;
			selection.push_back(input);
		}

		for (it = selection.begin(); it < selection.end(); it++) {
			if (*it == "blue" || *it == "b")
				refinedSelection.push_back("blue");
			else if (*it == "red" || *it == "r")
				refinedSelection.push_back("red");
			else if (*it == "yellow" || *it == "y")
				refinedSelection.push_back("yellow");
		}
		cout << "Rolling: " << endl;
		for (vector<string>::iterator i = refinedSelection.begin(); i != refinedSelection.end(); i++) {
			cout << "[" << *i << "  dice]\n";
		}
		cout << "type \"yes\" to confirm roll:" << endl;

		cin >> tmp;
	}

	if (std::find(refinedSelection.begin(), refinedSelection.end(), "red") != refinedSelection.end()) {
		Dice d1 = Dice(Colour::RED);
		_rollOfDice.theRoll.push_back(d1);
	}

	if (std::find(refinedSelection.begin(), refinedSelection.end(), "yellow") != refinedSelection.end()) {
		Dice d2 = Dice(Colour::YELLOW);
		_rollOfDice.theRoll.push_back(d2);
	}

	if (std::find(refinedSelection.begin(), refinedSelection.end(), "blue") != refinedSelection.end()) {
		Dice d3 = Dice(Colour::BLUE);
		_rollOfDice.theRoll.push_back(d3);
	}

}


void QwintoPlayer::inputAfterRoll(RollOfDice &rod) {

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

