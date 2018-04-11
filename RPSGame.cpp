/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: RPSGame Class Implementation file
********************************************************************/
#include "RPSGame.hpp"
#include "Tool.hpp"

#include <iostream>
/********************************************************************
** Description:		Constructor
** Takes 3 tool pointers and parameters and initializes the rock,
** paper, and scissor pointer member variables.
********************************************************************/
RPSGame::RPSGame(Tool* rockPtr, Tool* paperPtr, Tool* scissorsPtr, bool AIon)
{
	this->rockPtr = rockPtr;
	this->paperPtr = paperPtr;
	this->scissorsPtr = scissorsPtr;
	this->AIon = AIon;
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	rounds = 0;
}
/********************************************************************
** Description:			setUserTool
** This function has a character parameter that designates which 
** tool pointer will be assigned to the human's tool pointer.
********************************************************************/
void RPSGame::setUserTool(char humanTool)
{
	switch (humanTool) {
	case 'r':
		this->humanTool = rockPtr;
		break;
	case 'p':
		this->humanTool = paperPtr;
		break;
	case 's':
		this->humanTool = scissorsPtr;
		break;
	default:
		std::cout << "this shouldn't happen." << std::endl;
	}
}
/********************************************************************
** Description:			setCompTool
** This function has a character parameter that designates which 
** tool pointer will be assigned to the computer's tool pointer. 
********************************************************************/
void RPSGame::setCompTool(char compTool)
{
	switch (compTool) {
	case 'r':
		this->compTool = rockPtr;
		std::cout << "The Computer chose Rock." << std::endl;
		break;
	case 'p':
		this->compTool = paperPtr;
		std::cout << "The Computer chose Paper." << std::endl;
		break;
	case 's':
		this->compTool = scissorsPtr;
		std::cout << "The Computer chose Scissors." << std::endl;
		break;
	default:
		std::cout << "this shouldn't happen." << std::endl;
	}
}
/********************************************************************
** Description:			setAIEqual
** Sets the computer's tool to the same strength value
** as the human's tool. 
********************************************************************/
void RPSGame::setAIEqual()
{
	compTool->setStrength(humanTool->getStrength());
}

/********************************************************************
** Description:			play
** This function is responsible for gameplay. It initializes the
** computer with a tool based on the AI selected by calling the
** pickTool function. It then determines who won based on the value
** returned by the human's tool calling it's fight function. There
** are 3 possible outcomes, human wins, computer wins, or a tie.
********************************************************************/
void RPSGame::play()
{


	//So far the only bugs I've dealt with are syntax errors except for
	//one where in the play function of RPSGame.
	//compTool = pickTool((humanWon, humanPriorChoice, AIon)
	//This is returns a char and assigning it to a pointer.. 
	//so I used just the setCompTool function. That should accomplish
	//the intended task, I think... setCompTool(pickTool(humanWon, humanPriorChoice, AIon))
	
	setCompTool(pickTool(humanWon, AIon));

	
	/*
	 *It initializes the
** computer with a tool based on the AI selected by calling the
** pickTool function.
	 *
	 *
	 */


	double result = humanTool->fight(compTool);

	if (result > 0) {

		// Human wins
		human_wins++;
		rounds++;
		std::cout << "You win!" << std::endl;

		humanWon = true;
		humanPriorChoice = humanTool->getType();
	} else if (result < 0)
	{
		// Computer wins
		computer_wins++;
		rounds++;
		std::cout << "Sorry, you lose!" << std::endl;

		humanWon = false;

	} else {
		// It was a tie
		ties++;
		rounds++;
		std::cout << "It was a tie!" << std::endl;

		humanWon = false;
	}

	std::cout << "Round:" << rounds << std::endl;
	std::cout << "Human wins:" << human_wins << std::endl;
	std::cout << "Computer wins:" << computer_wins << std::endl;
	std::cout << "Ties:" << ties << std::endl;
	std::cout << std::endl;
}
/********************************************************************
**						pickTool
** Description: Game AI  
** Based on: 
** https://arstechnica.com/science/2014/05/win-at-rock-paper-scissors-by-knowing-thy-opponent/
** AI will take in prior human choice and will pick the proper tool
** based on PRIOR knowledge
** if AI won last game then tool is randomly picked
** AI off will pick a random tool each rounda character associated with the tool
** that the computer will use. 
********************************************************************/
char RPSGame::pickTool(bool humanWin, bool ai)
{
	int randomNumber;
	// AI is on
	//std::cout << "humanPriorChoice: " << humanPriorChoice << std::endl;
	//std::cout << "The AI is on, prepare to meet your doom." << std::endl;
	if (ai == true)
	{
		// did human win?
		if (humanWin == true && rounds > 0)
		{
			//std::cout << "Human won last time. Not this time" << std::endl;
			switch (humanPriorChoice)
			{
			case 'r':
				
				return 'p';
			case 's':
				
				return 'r';
			case 'p':
				
				return 's';
			default:
				break;
			}
		}
		else   // randomly pick a tool, computer won
		{
			//std::cout << "Human did not win last time. choosing randomly" << std::endl;
			randomNumber = rand() % 3;
			switch (randomNumber)
			{
			case 0:
				return 'r';
			case 1:
				return 'p';
			case 2:
				return 's';
			}
		}
	}
	else // AI is off
	{
		randomNumber = rand() % 3;
		switch (randomNumber)
		{
		case 0:
			return 'r';
		case 1:
			return 'p';
		case 2:
			return 's';
		}
	}
	return 'q';
}
