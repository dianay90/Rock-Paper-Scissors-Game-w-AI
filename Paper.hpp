/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Paper class. A derived class of 
** Tool that represents Paper in the game of Rock, Paper,
** Scissors. It contains a fight function that makes it stronger
** than the Rock tool, but weaker than the Scissors tool when
** using the default strengths. Otherwise, the outcome
** is dependent on whether the tool it is fighting against has more
** than twice the strength assigned to Paper. 
********************************************************************/
#ifndef PAPER_HPP
#define PAPER_HPP
#include "Tool.hpp"
class Paper : public Tool
{
public:
	Paper();
	Paper(int);
	virtual int fight(Tool* toolPtr);
};
#endif

