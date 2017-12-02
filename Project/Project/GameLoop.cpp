#include <stdio.h>
#include "RollOfDice.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include <string>


int main(){
	bool done = false ; 
	int versionInput=0; 
	int numberOfPlayers =0;

	cout << "for Qwinto tap 1, for Qwixx tap 2" << endl; 

	while (!(versionInput == 1 || versionInput == 2))
		cin >> versionInput; 

	cout << "how many players for this game ?" << endl; 
	while (numberOfPlayers == 0)
		cin >> numberOfPlayers; 

	vector<string> names;
	cout << "please enter the names of the players" << endl; 
	for (int i = 0; i < numberOfPlayers; i++) {
		string input = "";
		while (input == "") {
			cin >> input; 
			names.push_back(input);
		}
	}


	if (versionInput == 1)
	{
		vector<QwintoPlayer> playersQwinto;
		
		for (int i = 0; i < static_cast<int>(names.size()); i++)
		playersQwinto.push_back(* new QwintoPlayer(names[i])); 

		 
		
		while (!done)
		{
			for (auto & activePlayer : playersQwinto) {
				RollOfDice rod;
				activePlayer.setActive(true);
				activePlayer.inputBeforeRoll(rod);
				rod.roll();
				cout << rod;
				cout << activePlayer.sheet;
				activePlayer.inputAfterRoll(rod); 
				if (!activePlayer.sheet) {
					done = true;
					break;
				}
				for (auto& notActivePlayer : playersQwinto){
				
					if (!notActivePlayer.isOrNotActive()) {
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
			playersQwixx[i] = *new QwixxPlayer(names[i]);
		RollOfDice rod;

		while (!done)
		{
			for (auto & activePlayer : playersQwixx) {
				activePlayer.setActive(true);
				activePlayer.inputBeforeRoll(rod);
				rod.roll();
				cout << rod;
				cout << activePlayer.sheet;
				activePlayer.inputAfterRoll(rod);
				
				if (!activePlayer.sheet) {
					done = true;
					break;
				}
				for (auto& notActivePlayer : playersQwixx) {
					
					if (!notActivePlayer.isOrNotActive()) {
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
}