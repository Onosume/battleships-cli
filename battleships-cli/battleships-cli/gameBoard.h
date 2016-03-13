// Battleships-cli
// gameBoard.h
// Author: Matthew Tinn
// The game board

#pragma once

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;
const char HIT_MARKER = 'H';
const char MISS_MARKER = 'M';

class GameBoard
{
private:
	char board[BOARD_WIDTH][BOARD_HEIGHT];
public:
	GameBoard();
	void Init();
	void SetCell(int posX, int posY, char status);
	void Print();
};
