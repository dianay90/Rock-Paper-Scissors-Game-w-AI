/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Rock class. A derived class of
** Tool that represents Rock in the game of Rock, Paper,
** Scissors. It contains a fight function that makes it stronger
** than the Scissors tool, but weaker than the Paper tool when
** using the default strengths. Otherwise, the outcome
** is dependent on whether the tool it is fighting against has more
** than twice the strength assigned to Rock. 
********************************************************************/
#ifndef ROCK_HPP
#define ROCK_HPP
#include "Tool.hpp"
class Rock : public Tool
{
public:
	Rock();
	Rock(int);
	virtual int fight(Tool * toolPtr);
};
#endif
