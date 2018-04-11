/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Scissors class. A derived class of 
** Tool that represents the Scissors in the game of Rock, Paper,
** Scissors. It contains a fight function that makes it stronger
** than the Paper tool, but weaker than the Rock tool if the user
** chooses to use the default strengths. Otherwise, the outcome
** is dependent on whether the tool it is fighting against has more
** than twice the strength assigned to Scissors. 
********************************************************************/
#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include "Tool.hpp"
class Scissors: public Tool
{
public:
	Scissors();
	Scissors(int str);
	virtual int fight(Tool * toolPtr);
};
#endif
