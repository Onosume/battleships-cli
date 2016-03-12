#pragma once

#include <iostream>
#include <exception>

using namespace std;

class InvalidInputException : public exception
{
	virtual const char* what() const throw();
};