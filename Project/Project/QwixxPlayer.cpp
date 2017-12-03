#include "QwixxPlayer.h"



QwixxPlayer::QwixxPlayer(string name) : sheet(name)
{
}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rod)
{
	cout << "Let the Game Begin!" << endl;
	Dice red = Dice(Colour::RED); 
	rod.add(red);
	Dice green = Dice(Colour::GREEN);
	rod.add(green);
	Dice yellow = Dice(Colour::YELLOW);
	rod.add(yellow);
	Dice blue = Dice(Colour::BLUE);
	rod.add(blue);
	Dice white1 = Dice(Colour::WHITE);
	rod.add(white1);
	Dice white2 = Dice(Colour::WHITE);
	rod.add(white2);
}

void QwixxPlayer::inputAfterRoll(RollOfDice& rod)
{
	if (isActive()) {
		int numberOfRecord = 0;
		cout << "how many score do you want to record ?" << endl;

		while (!(numberOfRecord == 1 || numberOfRecord == 2)) {
			cin >> numberOfRecord;
			if (!(numberOfRecord == 1 || numberOfRecord == 2)){
				cout << "Invalid entry please select '1' or '2'" << endl; 
			}
		}
	}
	else if (!isActive()) {
		int numberOfRecord = 0;
		cout << "how many score do you want to record ?" << endl;

		while (!(numberOfRecord == 0 || numberOfRecord == 1)) {
			cin >> numberOfRecord;
			if (!(numberOfRecord == 1 || numberOfRecord == 2)) {
				cout << "Invalid entry please select '0' or '1'" << endl;
			}
		}
	}
}