#include <stdio.h>
#include "RollOfDice.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include <string>

void checkRows(std::vector<QwixxPlayer>& players ) {
	for (auto &player : players) {
		if (player.sheet.redRow[11] == "L") {
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.redRow[11] != "L") {
					otherPlayer.sheet.redRow[11] != "X";
				}
			}
		}
		if (player.sheet.yellowRow[11] == "L") {
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.yellowRow[11] != "L") {
					otherPlayer.sheet.yellowRow[11] != "X";
				}
			}
		}
		if (player.sheet.greenRow[11] == "L") {
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.greenRow[11] != "L") {
					otherPlayer.sheet.greenRow[11] != "X";
				}
			}
		}
		if (player.sheet.blueRow[11]=="L"){
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.blueRow[11] != "L") {
					otherPlayer.sheet.blueRow[11] != "X";
				}
			}
		}
	}
}
int main() {
	bool done = false;
	int versionInput = 0;
	int numberOfPlayers = 0;

	cout << "For Qwinto tap 1, for Qwixx tap 2" << endl;

	while (true) {
		cin >> versionInput;
		if (versionInput == 1 || versionInput == 2)
		{
			break; 
		}
		else{
			cout << "invalid selection" << endl;
			versionInput = 0;
		}
	}

	cout << "How many players (1-3) for this game ?" << endl;
	while (true) {
		cin >> numberOfPlayers;
		if (numberOfPlayers >= 1 && numberOfPlayers <= 3) {
			break;
		}
		else {
			cout << "Invalid number of players" << endl;
			numberOfPlayers = 0;
		}
	}

	vector<string> names;
	cout << "Please enter the names of the players one by one" << endl;
	for (int i = 0; i < numberOfPlayers; i++) {
		string input = "";
		while (input == "") {
			cin >> input;
			names.push_back(input);
		}
	}

	cout << endl;
	cout << "-------------------" << endl;
	cout << "LET THE GAME BEGIN!" << endl;
	cout << "-------------------" << endl;

	
	if (versionInput == 1)
	{
		vector<QwintoPlayer> playersQwinto;

		for (int i = 0; i < static_cast<int>(names.size()); i++)
			playersQwinto.push_back(*new QwintoPlayer(names[i]));


		while (!done)
		{
			for (auto & activePlayer : playersQwinto) {
				RollOfDice rod;
				activePlayer.setActive(true);
				activePlayer.inputBeforeRoll(rod);
				rod.roll();
				cout << endl;
				cout << "the roll is:" << endl;
				cout << rod;
				cout << endl;
				activePlayer.sheet.setTotal();
					cout << activePlayer.sheet;
				cout << endl;
				activePlayer.inputAfterRoll(rod);
				if (!activePlayer.sheet) {
					done = true;
					break;
				}
				for (auto& notActivePlayer : playersQwinto) {

					if (!notActivePlayer.isActive()) {

						cout << notActivePlayer.sheet;
						notActivePlayer.inputAfterRoll(rod);
					}
					else if (!notActivePlayer.sheet) {
						done = true;
						break;
					}
				}
				activePlayer.setActive(false);
			}
		}
		for (auto &player : playersQwinto) {
			player.sheet.setTotal();
			cout << player.sheet;
		}
	}


	else if (versionInput == 2)
	{
		vector<QwixxPlayer> playersQwixx;
		for (int i = 0; i < static_cast<int>(names.size()); i++)
			playersQwixx.push_back(*new QwixxPlayer(names[i]));


		while (!done)
		{
			checkRows(playersQwixx); 
			for (auto & activePlayer : playersQwixx) {
				RollOfDice rod;
				activePlayer.setActive(true);
				activePlayer.inputBeforeRoll(rod);
				rod.roll();
				cout << endl;
				cout << "the roll is:" << endl;
				cout << rod;
				cout << endl;
				activePlayer.sheet.setTotal();
					cout << activePlayer.sheet;
				cout << endl;
				activePlayer.inputAfterRoll(rod);

				if (!activePlayer.sheet) {
					done = true;
					break;
				}
				for (auto& notActivePlayer : playersQwixx) {

					if (!notActivePlayer.isActive()) {
						cout << notActivePlayer.sheet;
						notActivePlayer.inputAfterRoll(rod);
					}
					else if (!activePlayer.sheet) {
						done = true;
						break;
					}
				}
				activePlayer.setActive(false);
			}
		}
		for (auto &player : playersQwixx) {
			player.sheet.setTotal();
			cout << player.sheet;
		}
	}

	cout << endl; 
	cout << "end of The game, tap anything to exit the game" << endl; 
	cin >> versionInput; 
}