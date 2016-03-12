// Battleships-cli
// invalidInputException.cpp
// Author: Matthew Tinn
// Exception for when the player inputs an invalid character

#include <iostream>
#include "invalidInputException.h"

using namespace std;

const char* InvalidInputException::what() const throw()
{
	return "The character input is not valid.";
}

