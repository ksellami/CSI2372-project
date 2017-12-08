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

//Not yet changed
void QwintoPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {

	bool hasRed = false, hasBlue = false, hasYellow = false;

	for (std::vector<Dice>::iterator i = _rollOfDice.theRoll.begin(); i != _rollOfDice.theRoll.end(); ++i) { // a changer avec for auto d 
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

	QwintoPlayer *qp = dynamic_cast<QwintoPlayer*>(this);

	cout << sheet.playerName << ", please select the row color and the column number (between 1 and 9) where you would like to place [" << _rollOfDice << "] in.\nType \"done\" when finished\n";
	cout << "(e.g. red 3 done)" << endl;
	if (!isActive()) {
		cout << "NOTE: You can type \"pass\" to skip with no penalty ";
		cout << "(e.g. pass done):" << endl;
	}
	if (isActive()) {
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
			if (input == "pass" && isActive() == false) {
				return;
			}
			if (input == "fail" && isActive() == true) {
				qp->sheet.fail();
				//	qp->sheet.score(sheet,_rollOfDice, Colour::RED, -5); // failed throw
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
				if (qp->sheet.score(sheet, _rollOfDice, Colour::BLUE, x - 1))
					enteredValid = true;
			}
			else if (selection.end()[-3] == "yellow" && hasYellow) {
				if (qp->sheet.score(sheet, _rollOfDice, Colour::YELLOW, x - 1))
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
				cout << endl << sheet.playerName << ", Now please select the row color and the column number (between 1 and 9) where you would like to place [" << _rollOfDice << "] in.\nType \"done\" when finished\n";
				cout << "(e.g. red 3 done)" << endl;
				if (!isActive()) {
					cout << "NOTE: You can type \"pass\" to skip with no penalty ";
					cout << "(e.g. pass done):" << endl;
				}
				if (isActive()) {
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