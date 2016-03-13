// Battleships-cli
// main.cpp
// Author: Matthew Tinn
// Main Game Loop

#include "gameProcessor.h"
#include <iostream>

using namespace std;

void main()
{
	GameProcessor* gameProcessor = new GameProcessor();

	gameProcessor->WriteIntro();

	// Game Loop
	while (!gameProcessor->GameOver())
	{
		gameProcessor->DisplayCurrentGame();

		bool validInput = false;

		while (!validInput)
		{
			gameProcessor->TakePlayerInput();
			validInput = gameProcessor->Shoot();
		}

		gameProcessor->AllShipsSunk();
	}

	char exitChar;
	cout << "That's the end of the game. Press any key and enter to exit.    ";
	cin >> exitChar;

	delete gameProcessor;
}