/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Rock Class implementation file
********************************************************************/
#include "Rock.hpp"
#include "Tool.hpp"

#include<iostream>
using std::cout;
using std::endl;
/********************************************************************
** Description:				Default Constructor
** Initializes strength to 1 and type to r
********************************************************************/
Rock::Rock()
{
	strength = 1;
	type = 'r';
}
/********************************************************************
** Description:				Constructor
** Initializes strength to user specified amount
********************************************************************/
Rock::Rock(int str)
{
	setStrength(str);
	type = 'r';
}
/********************************************************************
** Description:     fight
** Accepts a pointer to a tool as the tool being pitted against
** Rock. It serves as a multiplier for the strength value based on
** tool type. If the tool passed is Scissors, then Rock's strength is
** effectively doubled. If the tool passed is Paper, then
** Paper's strength is effectively doubled. It calculates Rock's
** effective strength and returns the value as an integer.
********************************************************************/
int Rock::fight(Tool* toolPtr)
{
	// Do tool strength comparison here
	int strModifierSelf = 1;
	int strModifierOther = 1;
	// Rock is strong against scissors
	if (toolPtr->getType() == 's') {
		strModifierSelf = 2;
		cout << "Rock is dueling Scissors!" << endl;

		// Rock is weak against paper
	}

	else if (toolPtr->getType() == 'p') {
		// Half strength against paper
		strModifierOther = 2;
		cout << "Rock is dueling Paper!" << endl;
	}
	else if (toolPtr->getType() == 'r')
	{
		cout << "Rock is dueling Rock!" << endl;
	}
	cout << endl;
	// Positive = win, negative = lose, zero = tie
	//Rock's strength *strX - tool's strength * tempdouble

	return (this->getStrength()* strModifierSelf) -
		(toolPtr->getStrength() * strModifierOther);
}

