/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Paper Class implementation file
********************************************************************/
#include "Paper.hpp"
#include "Tool.hpp"

#include<iostream>
using std::cout;
using std::endl;
/********************************************************************
** Description:				Default Constructor
** Initializes strength to 1 and type to p
********************************************************************/
Paper::Paper()
{
	strength = 1;
	type = 'p';
}
/********************************************************************
** Description:				Constructor
** Initializes strength to user specified amount
********************************************************************/
Paper::Paper(int str)
{
	setStrength(str);
	type = 'p';
}
/********************************************************************
** Description:     fight
** Accepts a pointer to a tool as the tool being pitted against 
** Paper. It serves as a multiplier for the strength value based on
** tool type. If the tool passed is Rock, then Paper's strength is 
** effectively doubled. If the tool passed is Scissors, then 
** Scissors's strength is effectively doubled. It calculates Paper's
** effective strength and returns the value as an integer.
********************************************************************/
int Paper::fight(Tool* toolPtr)
{
	// Do tool strength comparison here
	int strModifierSelf = 1;
	int strModifierOther = 1;

	// Paper is strong against rock. 
	if (toolPtr->getType() == 'r') {
		strModifierSelf = 2;
		cout << "Paper is dueling Rock!" << endl;
	}
	//Paper is weak against scissors
	else if (toolPtr->getType() == 's') {
		strModifierOther = 2;
		cout << "Paper is dueling Scissors!" << endl;
	}
	else if (toolPtr->getType() == 'p')
	{
		cout << "Paper is dueling Paper!" << endl;
	}
	cout << endl;

	// Positive = win, negative = lose, zero = tie
	//Paper's strength *strX - tool's strength * tempdouble

	return (this->getStrength()* strModifierSelf) -
		(toolPtr->getStrength() * strModifierOther);
}
