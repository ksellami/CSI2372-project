#include "QwintoPlayer.h"
#include "Colour.h"
#include <string>
QwintoPlayer::QwintoPlayer(string name) : sheet(name) {}

void QwintoPlayer::inputBeforeRoll(RollOfDice &rod) {

	string entry = "";
	
	vector<string> Colors;
	
	int validColor = 0;

	//if at least one color was entered 
	//the player can proceed
	while (validColor == 0) {
		Colors.clear();
		cout << endl;

		cout << sheet.playerName<< ", Select the color of the dice you want to roll" << endl;

		cout << "Please choose either Red , Blue or Yellow" << endl;

		cout << "enter ok when you are done" << endl;
		
		vector<string> playerInput;
		vector<string>::iterator it;


		// to verify player input and record it if ends with "ok" 

		while (entry != "ok") {
			cin >> entry;
			playerInput.push_back(entry);
		}

		playerInput.pop_back();
		for (vector<string>::iterator it = playerInput.begin(); it != playerInput.end(); it++) {

			if (*it == "blue" || *it == "red" || *it == "yellow") {

				//Check if the color is not already entered 
				//if not push it in the colors vector
				if (std::find(Colors.begin(), Colors.end(), *it) == Colors.end()) {
				
					Colors.push_back(*it);
					validColor++;
				}
				


			}
			else {
				cout << *it << " is not a valid color" << endl;
			}

		}

		//if no valid colors entered by the player print out 
		//a message to the user.
		if (validColor == 0) {
			cout << endl;
			cout << "No valid color was entered \nChoose blue, red or yellow" << endl;
			cout << endl;
			entry = "";
		}

	}


	//display the rolled dices to the user
	cout << "You rolled the " << endl;
	for (vector<string>::iterator i = Colors.begin(); i != Colors.end(); i++) {
		cout << *i << " dice" << endl;
	}

	
	// a loop that gows throught the entered colors
	// and roll a dice with the corresponding color 
	//for each entered color
	for (vector<string>::iterator i = Colors.begin(); i != Colors.end(); i++) {

		if (*i == "red") {
			Dice dice = Dice(Colour::RED);
			rod.theRoll.push_back(dice);

		}

		if (*i == "yellow") {
			Dice dice = Dice(Colour::YELLOW);
			rod.theRoll.push_back(dice);

		}

		if (*i == "blue") {
			Dice dice = Dice(Colour::BLUE);
			rod.theRoll.push_back(dice);
		}

	}
	

}


void QwintoPlayer::inputAfterRoll(RollOfDice &rod) {

	bool rowSelection = false, blue = false, yellow = false, red = false, scoringDone=false;
	string inputFS; 
	Colour theColor = Colour::WHITE; 
	int columnSelection=0; 

	// boolean initialisation to check if the dice is added in the roll
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

		// take the input of the player, the color of the row or pass or fail
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
		cout << "in what row you column (1-10) you want to score the roll?" << endl;

		// take the column where to score the roll
		while (true) {
			cin >> columnSelection;
			if (columnSelection >= 1 && columnSelection <= 10) {
				break;
			}
			else {
				cout << "invalid Selection!" << endl;
				columnSelection = 0;
			}
		}
		if (sheet.score(rod, theColor, columnSelection - 1))
			scoringDone = true;
		else {
			cout << "invalid selection!" << endl;
			columnSelection = 0;

		}
	}
}

