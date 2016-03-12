// Battleships-cli
// gameProcessor.h
// Author: Matthew Tinn
// An object that handles the processing of the game. 
// Everything major is done in here.

#pragma once

#include "player.h";

class GameProcessor
{
private:
	Player* player;
public:
	GameProcessor();
	void CreateGame();
	void CreatePlayer();
	void CreateBattleships();
};
