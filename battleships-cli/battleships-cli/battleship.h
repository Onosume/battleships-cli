// Battleships-cli
// battleship.h
// Author: Matthew Tinn
// A class to represent a battleship

#pragma once

#include <list>
#include <string>

using namespace std;

const int MAX_BATTLESHIP_LENGTH = 5;

class Battleship
{
private:
	bool sunk;
	list<string> position;
	int health;
	int positionsHit[MAX_BATTLESHIP_LENGTH];
public:
	Battleship();
	Battleship(list<string> position);
	Battleship(const Battleship& otherBattleship);
	~Battleship();
	void Init(list<string> position);
	list<string> Position();
	void TakeDamageOn(int positionIndex);
	bool Sunk();
};
