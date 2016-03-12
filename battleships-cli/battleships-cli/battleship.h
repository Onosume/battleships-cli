// Battleships-cli
// battleship.h
// Author: Matthew Tinn
// A class to represent a battleship

#pragma once

#include <list>
#include <string>

using namespace std;

class Battleship
{
private:
	bool sunk;
	list<string> position;
	int health;
public:
	Battleship();
	Battleship(list<string> position);
	Battleship(const Battleship& otherBattleship);
	~Battleship();
	void Init(list<string> position);
	bool Sunk();
};
