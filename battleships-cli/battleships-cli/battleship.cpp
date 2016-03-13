// Battleships-cli
// battleship.cpp
// Author: Matthew Tinn
// Implementation of the battleship class

#include "battleship.h";

// Construct a battleship with no position, but alive to be set later.
Battleship::Battleship()
{
	sunk = false;
	health = 1;
}

Battleship::~Battleship()
{
	delete[] positionsHit;
}

//Construct a battleship with a position
Battleship::Battleship(list<string> position)
{
	Init(position);
}

Battleship::Battleship(const Battleship& otherBattleship)
{
	sunk = otherBattleship.sunk;
	health = otherBattleship.health;
	position = otherBattleship.position;
}

// Initialise the battleship with a position
void Battleship::Init(list<string> position)
{
	sunk = false;
	health = position.size();
	this->position = position;
	positionsHit = new int[position.size()];

	for (int i = 0; i < position.size(); i++)
	{
		positionsHit[i] = 0;
	}

}

list<string> Battleship::Position()
{
	return position;
}

void Battleship::TakeDamageOn(int positionIndex)
{
	if (positionsHit[positionIndex] != 1)
	{
		positionsHit[positionIndex] = 1;
		health--;

		if (health == 0)
		{
			sunk = true;
		}
	}
}

// Accessor method for sunk
bool Battleship::Sunk()
{
	return sunk;
}