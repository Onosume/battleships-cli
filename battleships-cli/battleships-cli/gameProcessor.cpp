// Battleships-cli
// gameProcessor.cpp
// Author: Matthew Tinn
// Implementation of the game processor class

#include "gameProcessor.h";

GameProcessor::GameProcessor()
{
	CreateGame();
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

}