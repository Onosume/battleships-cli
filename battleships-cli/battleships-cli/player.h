// Battleships-cli
// player.h
// Author: Matthew Tinn
// A class to represent the player

#pragma once

class Player
{
private:
	int score;
	int cannonballs;
public:
	Player(int cannonballs);
	void Init(int cannonballs);
};