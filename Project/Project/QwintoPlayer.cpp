#include "QwintoPlayer.h"
#include "Colour.h"
#include <string>
QwintoPlayer::QwintoPlayer(string name) : sheet(name){}

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

		while (input != "done" || (input != "pass" && isActive == false)) {
			cin >> input;
			selection.push_back(input);
		}

		for (it = selection.begin(); it<selection.end(); it++) {
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


void QwintoPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {

	bool hasRed = false, hasBlue = false, hasYellow = false;

	for (std::vector<Dice>::iterator i = _rollOfDice.theRoll.begin(); i != _rollOfDice.theRoll.end(); ++i) {
		Dice d = *i;
		switch (d.colour) {
		case Colour::RED:
			hasRed = true;
			break;
		case Colour::BLUE:
			hasBlue = true;
			break;
		case Colour::YELLOW:
			hasYellow = true;
			break;
		}
	}

	QwintoPlayer *qp = dynamic_cast<QwintoPlayer*>(this); // can be used like this : qp->scoreSheet.score(~~~)

	cout << sheet.playerName<< ", please select the row color and the column number (between 1 and 9) where you would like to place [" << _rollOfDice << "] in.\nType \"done\" when finished\n";
	cout << "(e.g. red 3 done)" << endl;
	if (!isActive) {
		cout << "NOTE: You can type \"pass\" to skip with no penalty ";
		cout << "(e.g. pass done):" << endl;
	}
	if (isActive) {
		cout << "NOTE: You can type \"fail\" to mark a failed throw ";
		cout << "(e.g. fail done):" << endl;
	}
	cout << endl;
	vector<string> selection;
	vector<string>::iterator it;
	string input = "";

	bool enteredValid = false;

	cin.ignore();
	while (!enteredValid) {
		input = "";
		while (input != "done") {
			cin >> input;
			if (input == "pass" && isActive == false) {
				return;
			}
			if (input == "fail" && isActive == true) {
				qp->sheet.score(sheet,_rollOfDice, Colour::RED, -5); // failed throw
				return;
			}
			selection.push_back(input);
		}

		if (selection.size() >= 3) {
			//stringstream asdf(selection.end()[-2]);
			int x = 0;
			//asdf >> x;
			x = std::stoi(selection.end()[-2]); 

			//cout<<"end-2: "<<selection.end()[-2]<<" end-1: "<<selection.end()[-1];
			if (selection.end()[-3] == "red" && hasRed) {
				if (qp->sheet.score(sheet, _rollOfDice, Colour::RED, x - 1))
					enteredValid = true;
			}
			else if (selection.end()[-3] == "blue" && hasBlue) {
				if (qp->sheet.score(sheet,_rollOfDice, Colour::BLUE, x - 1))
					enteredValid = true;
			}
			else if (selection.end()[-3] == "yellow" && hasYellow) {
				if (qp->sheet.score(sheet,_rollOfDice, Colour::YELLOW, x - 1))
					enteredValid = true;
				else {
					cout << "invalid entry" << endl;
					input = "";
					selection.clear();
				}
			}

			if (!enteredValid) {
				input = "";
				cout << endl << sheet.playerName << ", THAT WAS AN INVALID SELECTION.\n" << qp->sheet << endl;
				cout << endl << sheet.playerName << "Now please select the row color and the column number (between 1 and 9) where you would like to place [" << _rollOfDice << "] in.\nType \"done\" when finished\n";
				cout << "(e.g. red 3 done)" << endl;
				if (!isActive) {
					cout << "NOTE: You can type \"pass\" to skip with no penalty ";
					cout << "(e.g. pass done):" << endl;
				}
				if (isActive) {
					cout << "NOTE: You can type \"fail\" to mark a failed throw ";
					cout << "(e.g. fail done):" << endl;
				}
				cout << endl;
				selection.clear();
			}

		}
		else {
			cout << "invalid entry" << endl;
			input = "";
			selection.clear();
		}
	}

}

