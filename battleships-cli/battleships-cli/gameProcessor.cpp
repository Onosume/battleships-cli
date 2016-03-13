// Battleships-cli
// gameProcessor.cpp
// Author: Matthew Tinn
// Implementation of the game processor class

#include "gameProcessor.h"
#include "invalidInputException.h"
#include <ctime>
#include <iostream>
#include <string>
#include <list>

using namespace std;

const int NUM_BATTLESHIPS = 3;

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
	CreateBattleships();
}

void GameProcessor::CreatePlayer()
{
	player = new Player(24);
}

void GameProcessor::CreateBattleships()
{
	battleships = new Battleship[NUM_BATTLESHIPS];

	battleships[0].Init(GeneratePosition(5));
	battleships[1].Init(GeneratePosition(4));
	battleships[2].Init(GeneratePosition(4));
}

list<string> GameProcessor::GeneratePosition(int battleshipSize)
{
	list<string> cells;
	string* usedPositions = new string[battleshipSize];
	
	string cell = "";
	int min, max;
	bool positionSelected = false;

	// Generate a random starting point
	// Generate a rand 65 - 74
	min = 65;
	max = 74;
	srand((unsigned)time(0));
	char randChar = min + (rand() % (int)(max - min + 1));

	string startColumn;

	// Generate a rand number 1 - 10 as an ASCII character
	min = 48;
	max = 57;
	srand((unsigned)time(0));
	char randNum = min + (rand() % (int)(max - min + 1));

	if (randNum == '0')
	{
		// If we get 0 convert to 10
		cell += randChar;
		cell += "10";

		startColumn += "10";
	}
	else
	{
		cell += randChar;
		cell += randNum;

		startColumn += randNum;
	}

	cells.push_back(cell);
	usedPositions[0] = cell;

	//Choose whether to go down, left, right or up

	char direction;

	char downCell = randChar + battleshipSize;
	char upCell = randChar - battleshipSize;
	char leftCell;
	char rightCell;

	if (randNum == '0')
	{
		leftCell = ('9' + 1) - battleshipSize;
		rightCell = ('9' + 1) + battleshipSize;
	}
	else
	{
		leftCell = randNum - battleshipSize;
		rightCell = randNum + battleshipSize;
	}

	if (downCell <= 'J')
	{
		direction = 'd';
	}
	else if (leftCell >= '1')
	{
		direction = 'l';
	}
	else if (rightCell <= ('9' + 1))
	{
		direction = 'r';
	}
	else if (upCell >= 'A')
	{
		direction = 'u';
	}

	for (int cellCount = 1; cellCount < battleshipSize; cellCount++)
	{
		string nextCell = "";

		if (direction == 'd')
		{
			char nextRow = randChar + cellCount;
			nextCell += nextRow;
			nextCell += startColumn;
		}
		else if (direction == 'l')
		{
			char nextColumn;

			if (randNum == '0')
			{
				nextColumn = ('9' + 1) - cellCount;
			}
			else
			{
				nextColumn = randNum - cellCount;
			}
				
			nextCell += randChar;
			nextCell += nextColumn;
		}
		else if (direction == 'r')
		{
			char nextColumn = randNum + cellCount;
			nextCell += randChar;
			if (nextColumn == ('9' + 1))
			{
				nextCell += "10";
			}
			else
			{
				nextCell += nextColumn;
			}
		}
		else if (direction == 'u')
		{
			char nextRow = randChar - cellCount;
			nextCell += nextRow;
			nextCell += startColumn;
		}

		cells.push_back(nextCell);
		usedPositions[cellCount] = nextCell;
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

	// Update the player's cannonball count
	player->TakeShot();

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
	string hitPosition(coordinateInput);
	bool hit = false;

	// For each battleship
	for (int i = 0; i < NUM_BATTLESHIPS; i++)
	{
		string checkPosition;
		
		list<string> positionList = battleships[i].Position();

		// Iterate over the positions
		list<string>::iterator it;
		it = positionList.begin();
		int index = 0;

		while (it != positionList.end())
		{
			// If a position matches it's a hit
			if (*it == hitPosition)
			{
				// If one matches it is a hit
				hit = true;

				// Update the player's score
				player->AddToScore(10);

				if (!battleships[i].Sunk())
				{
					battleships[i].TakeDamageOn(index);
				}
			}

			it++;
			index++;
		}
	}

	// Update the game board
	if (hit)
	{
		gameBoard.SetCell(positionIndexX, positionIndexY, HIT_MARKER);
		cout << "\nIt's a hit!\n";
	}
	else
	{
		gameBoard.SetCell(positionIndexX, positionIndexY, MISS_MARKER);
		cout << "\nIt's a miss!\n";
	}

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

bool GameProcessor::AllShipsSunk()
{
	if (battleships[0].Sunk() && battleships[1].Sunk() && battleships[2].Sunk())
	{
		return true;
	}
		
	return false;
}