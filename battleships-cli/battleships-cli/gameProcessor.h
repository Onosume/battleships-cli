// Battleships-cli
// gameProcessor.h
// Author: Matthew Tinn
// An object that handles the processing of the game. 
// Everything major is done in here.

#pragma once

#include "player.h"
#include "gameBoard.h"
#include "battleship.h"
#include <list>
#include <string>

using namespace std;

class GameProcessor
{
private:
	Player* player;
	GameBoard gameBoard;
	Battleship* battleships;
	char coordinateInput[3];
	bool gameOver;
public:
	GameProcessor();
	~GameProcessor();
	
	// Object Creation
	void CreateGame();
	void CreatePlayer();
	void CreateBattleships();
	list<string> GeneratePosition(int battleshipSize);
	
	// // Game Flow
	void WriteIntro(); // Writes the intro at the beginning of the game
	void DisplayCurrentGame(); // Displays game board, player score, num canonballs
	void TakePlayerInput(); // Prompts the player for input and sticks it in a char array
	bool Shoot(); // Takes a shot, updates game board, player etc
	int ConvertCharacterToIndex(char character);
	bool AllShipsSunk();
	bool GameOver();
};
