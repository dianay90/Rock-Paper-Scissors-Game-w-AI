/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Scissors Class implementation file
********************************************************************/
#include "Scissors.hpp"
#include "Tool.hpp"

#include<iostream>
using std::cout;
using std::endl;
/********************************************************************
** Description:             Default Constructor
** Initializes strength to 1 and type to s
********************************************************************/
Scissors::Scissors()
{
	strength = 1;
	type = 's';
}
/********************************************************************
** Description:             Constructor
** Initializes strength to user specified amount
********************************************************************/
Scissors::Scissors(int str)
{
	setStrength(str);
	type = 's';
}
/********************************************************************
** Description:     fight
** Accepts a pointer to a tool and determines the type of tool being
** pitted against Scissors. It serves as a multiplier for the 
** strength value based on tool type. If the tool passed is 
** Paper, then Scissor's strength is effectively doubled. 
** If the tool passed is Rock, then Rock's strength is effectively
** doubled. It calculates Scissor's effective strength and returns
** the value as an integer. 
********************************************************************/
int Scissors::fight(Tool* toolPtr)
{
	// Do tool strength comparison here
	int strModifierSelf = 1;
	int strModifierOther = 1;

	// Scissors is strong against Paper
	if(toolPtr->getType() == 'p') {
		strModifierSelf = 2;
		cout << "Scissors is dueling Paper!" << endl;
	}

	// Scissors is weak against Rock
	else if (toolPtr->getType() == 'r') {
		strModifierOther = 2;
		cout << "Scissors is dueling Rock!" << endl;
	}
	else if (toolPtr->getType() == 's')
	{
		cout << "Scissors is dueling Scissors!" << endl;
	}
	cout << endl;
	// Positive = win, negative = lose, zero = tie
	//Scissors' strength *strX - tool's strength * tempdouble

	return (this->getStrength()* strModifierSelf) -
		(toolPtr->getStrength() * strModifierOther);
}

