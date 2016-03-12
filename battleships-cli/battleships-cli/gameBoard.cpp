// Battleships-cli
// gameBoard.cpp
// Author: Matthew Tinn
// Implementation of the game board class

#include "gameBoard.h";
#include <iostream>;

using namespace std;

GameBoard::GameBoard()
{
	Init();
}

void GameBoard::Init()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			board[i][j] = 'O';
		}
	}
}

void GameBoard::SetCell(int posX, int posY, char status)
{
	board[posX][posY] = status;
}

void GameBoard::Print()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			cout << board[i][j];
		}

		cout << "\n";
	}
}