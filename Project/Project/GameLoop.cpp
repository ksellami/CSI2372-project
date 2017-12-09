#include "RollOfDice.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include <string>
#include <iostream>
// this method check if a player locked a row, so it mark the row as unavailable (X) to the other players
void checkRows(std::vector<QwixxPlayer>& players ) {
	for (auto &player : players) {
		if (player.sheet.redRow[11] == "L") {
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.redRow[11] != "L") {
					otherPlayer.sheet.redRow[11] = "X";
				}
			}
		}
		if (player.sheet.yellowRow[11] == "L") {
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.yellowRow[11] != "L") {
					otherPlayer.sheet.yellowRow[11] = "X";
				}
			}
		}
		if (player.sheet.greenRow[11] == "L") {
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.greenRow[11] != "L") {
					otherPlayer.sheet.greenRow[11] = "X";
				}
			}
		}
		if (player.sheet.blueRow[11]=="L"){
			for (auto &otherPlayer : players) {
				if (otherPlayer.sheet.blueRow[11] != "L") {
					otherPlayer.sheet.blueRow[11] = "X";
				}
			}
		}
	}
}
int main() {
	bool done = false;
	string versionInput, numberOfPlayers ;
	

	cout << "For Qwinto tap 1, for Qwixx tap 2" << endl;

	while (true) {
		cin >> versionInput;                               // qwinto or qwixx ???
		if (versionInput == "1" || versionInput == "2")
		{
			break; 
		}
		else{
			cout << "invalid selection" << endl;
			versionInput = "";
		}
	}

	cout << "How many players (1-3) for this game ?" << endl;
	while (true) {														// the number of the players
		cin >> numberOfPlayers;
		if (numberOfPlayers == "1" || numberOfPlayers == "3" || numberOfPlayers == "2") {
			break;
		}
		else {
			cout << "Invalid number of players" << endl;
			numberOfPlayers = "";
		}
	}

	vector<string> names;
	cout << "Please enter the names of the players one by one" << endl;		// the name of the players in a vector
	for (int i = 0; i < std::stoi(numberOfPlayers); i++) {
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

	
	if (versionInput == "1") // play qwinto
	{
		vector<QwintoPlayer> playersQwinto;

		for (int i = 0; i < static_cast<int>(names.size()); i++)
			playersQwinto.push_back(*new QwintoPlayer(names[i])); // create the players depending of the number of the players


		while (!done)
		{
			for (auto & activePlayer : playersQwinto) {  // loop over all players
				RollOfDice rod; // create the roll
				activePlayer.setActive(true); // first player to roll
				activePlayer.inputBeforeRoll(rod);
				rod.roll(); 
				cout << endl;
				cout << "the roll is:" << endl;
				cout << rod << endl ;
				cout << endl;
				activePlayer.sheet.setTotal(); // calculate the points before to print the sheet
					cout << activePlayer.sheet;
				cout << endl;
				activePlayer.inputAfterRoll(rod); 
				if (!activePlayer.sheet) { // if the not operator retrun true, the game is over
					done = true;
					break;
				}
				for (auto& notActivePlayer : playersQwinto) {
					// loop over inactive player
					if (!notActivePlayer.isActive()) {
						cout << rod << endl; 
						cout << notActivePlayer.sheet;
						notActivePlayer.inputAfterRoll(rod);
					}
					else if (!notActivePlayer.sheet) {
						// if the not operator retrun true, the game is over
						done = true;
						break;
					}
				}
				activePlayer.setActive(false); // the active player becomes inactive
			}
		}
		for (auto &player : playersQwinto) { // print the all players sheet after the end of the game
			player.sheet.setTotal();
			cout << player.sheet;
		}
	}


	else if (versionInput == "2")  // play qwixx
	{
		vector<QwixxPlayer> playersQwixx;
		for (int i = 0; i < static_cast<int>(names.size()); i++)
			playersQwixx.push_back(*new QwixxPlayer(names[i]));


		while (!done)
		{
			checkRows(playersQwixx); // no difference with qwinto except of the method checkRows
			for (auto & activePlayer : playersQwixx) {
				RollOfDice rod;
				activePlayer.setActive(true);
				activePlayer.inputBeforeRoll(rod);
				rod.roll();
				cout << endl;
				cout << "the roll is:" << endl;
				cout << rod << endl ;
				cout << endl;
				activePlayer.sheet.setTotal();
					cout << activePlayer.sheet;
				cout << endl;
				activePlayer.inputAfterRoll(rod);
				checkRows(playersQwixx);
				if (!activePlayer.sheet) {
					done = true;
					break;
				}
				for (auto& notActivePlayer : playersQwixx) {
					if (!notActivePlayer.isActive()) {
						cout << rod << endl; 
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