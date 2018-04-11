/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: RPSGame Class
** The RPSGame class is the class that maintains the necessary 
** variables and functions for playing a round of Rock, Paper, 
** Scissors. It controls the game AI and all of the aspects of the
** actual gameplay. 
********************************************************************/
#ifndef RPSGAME_HPP
#define RPSGAME_HPP
#include "Tool.hpp"

class RPSGame
{
private:
	Tool* humanTool;
	Tool* compTool;
	Tool* rockPtr;
	Tool* paperPtr;
	Tool* scissorsPtr;
	int human_wins;
	int computer_wins;
	int ties;
	int rounds;
	bool humanWon;
	bool AIon;
	char humanPriorChoice;

public:
	RPSGame(Tool*, Tool*, Tool*, bool);
	void setUserTool(char);
	void setCompTool(char);
	void setAIEqual();
	void play();
	char pickTool(bool, bool);

};
#endif


