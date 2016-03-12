// Battleships-cli
// gameProcessor.cpp
// Author: Matthew Tinn
// Implementation of the game processor class

#include "gameProcessor.h"
#include "invalidInputException.h"
#include <ctime>
#include <iostream>

GameProcessor::GameProcessor()
{
	CreateGame();
}

GameProcessor::~GameProcessor()
{
	delete player;
	delete[] battleships;
}

void GameProcessor::CreateGame()
{
	CreatePlayer();
}

void GameProcessor::CreatePlayer()
{
	player = new Player(24);
}

void GameProcessor::CreateBattleships()
{
	battleships = new Battleship[3];

	battleships[0].Init(GeneratePosition(5));
	battleships[1].Init(GeneratePosition(4));
	battleships[2].Init(GeneratePosition(4));
}

list<string> GameProcessor::GeneratePosition(int battleshipSize)
{
	list<string> cells;
	string* usedPositions = new string[battleshipSize];
	bool positionSelected = false;

	for (int i = 0; i < battleshipSize; i++)
	{
		string cell = "";

		while (!positionSelected)
		{
			// Generate a rand 65 - 74
			srand((unsigned)time(0));
			char randChar = (rand() % 74) + 65;

			// Generate a rand 1 - 10
			srand((unsigned)time(0));
			char randNum = (rand() % 39) + 30;

			if (randNum == 30)
			{
				// If we get ASCII 30 (0) convert to 10
				cell = randChar + "10";
			}
			else
			{
				cell = randChar + randNum;
			}

			positionSelected = true;

			// Can't select the same positon more than once per battleship
			for (int j = 0; j < battleshipSize; j++)
			{
				if (cell == usedPositions[j])
				{
					positionSelected = false;
					break;
				}
			}
		}

		cells.push_back(cell);
		usedPositions[i] = cell;
	}

	delete[] usedPositions;

	return cells;
}

void GameProcessor::WriteIntro()
{
	cout << "***  **** *** *** *   *** *** *  * * *** ***" << endl;
	cout << "*  * *  *  *   *  *   *   *   *  * * * * *" << endl;
	cout << "* *  ****  *   *  *   *** *** **** * **  ***" << endl;
	cout << "**   *  *  *   *  *   *     * *  * * *     *" << endl;
	cout << "* *  *  *  *   *  *   *     * *  * * *     *" << endl;
	cout << "*  * *  *  *   *  *   *     * *  * * *     *" << endl;
	cout << "***  *  *  *   *  *** *** *** *  * * *   ***" << endl;

	cout << "Sink all of the enemy ships!" << endl;
	cout << "When prompted enter a coordinate (A-J, 1-10) e.g. A5." << endl;
	cout << "Hit all of the ships before your cannonballs run out!" << endl;
}

void GameProcessor::DisplayCurrentGame()
{
	cout << "Cannonballs remaining: " << player->CannonballCount() << endl;

	cout << "\nCurrent board:" << endl;
	gameBoard.Print();
}

void GameProcessor::TakePlayerInput()
{
	cout << "Enter a coordinate." << endl;
	cin >> coordinateInput;
}

bool GameProcessor::Shoot()
{
	bool validAction = true;

	// Parse the input characters
	int positionIndexX, positionIndexY;

	try
	{
		positionIndexX = ConvertCharacterToIndex(coordinateInput[0]);

		if (coordinateInput[1] == '1' && coordinateInput[2] == '0')
		{
			positionIndexY = 10;
		}
		else
		{
			positionIndexY = ConvertCharacterToIndex(coordinateInput[1]);
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		validAction = false;
	}

	if (!validAction)
	{
		return false;
	}

	// If the characters are valid, check the position markers of the ships

	// If one matches it is a hit

	// Update the game board

	// Update the player's score

	// Update the player's cannonball count

	return true;
}



int GameProcessor::ConvertCharacterToIndex(char character)
{
	if (character == 'A' || character == 'a' || character == '1')
	{
		return 0;
	}
	else if (character == 'B' || character == 'b' || character == '2')
	{
		return 1;
	}
	else if (character == 'C' || character == 'c' || character == '3')
	{
		return 2;
	}
	else if (character == 'D' || character == 'd' || character == '4')
	{
		return 3;
	}
	else if (character == 'E' || character == 'e' || character == '5')
	{
		return 4;
	}
	else if (character == 'F' || character == 'F' || character == '6')
	{
		return 5;
	}
	else if (character == 'G' || character == 'g' || character == '7')
	{
		return 6;
	}
	else if (character == 'H' || character == 'h' || character == '8')
	{
		return 7;
	}
	else if (character == 'I' || character == 'i' || character == '9')
	{
		return 8;
	}
	else if (character == 'J' || character == 'J')
	{
		return 9;
	}
	else
	{
		throw new InvalidInputException;
	}
}