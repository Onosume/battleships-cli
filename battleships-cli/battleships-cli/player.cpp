// Battleships-cli
// player.cpp
// Author: Matthew Tinn
// Implementation of the player class

#include "player.h";

Player::Player(int cannonballs)
{
	Init(cannonballs);
}

void Player::Init(int cannonballs)
{
	score = 0;
	this->cannonballs = cannonballs;
}

int Player::CannonballCount()
{
	return cannonballs;
}

void Player::TakeShot()
{
	cannonballs--;
}

void Player::AddToScore(int points)
{
	score += points;
}

int Player::Score()
{
	return score;
}