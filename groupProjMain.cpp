/********************************************************************
** Authors:
**		Gerik Illo
**		Jimmy Nguyen
**		Diana Oh		932921211
**		Adam Spivey		933194607
**		Tiffany Warner	933229972
** Date: May 21 2017
** Description: Group Project: Rock, Paper, Scissors
** This program simulates a game of Rock, Paper, Scissors. It 
** contains an AI feature which it allows the user to turn on and 
** off. It also allows the user to set the strengths of each tool
** or use the default strengths. If the user decides to set custom
** strengths for each tool, then the normal games rules are broken.
** In such a case, the outcome is dependent upon the strengths 
** assigned to each tool. 
********************************************************************/
#include "Tool.hpp"
#include "Rock.hpp"
#include "Scissors.hpp"
#include "Paper.hpp"
#include "RPSGame.hpp" 
#include "InputVal.hpp"
#include "inputValidation.h"
#include <iostream>
#include <string>
#include <limits> //For cin limits

int main()
{
	//char answer = '?';          // Set to junk response character
	char userChoice;
	//char choiceCharAI = ' ';
	bool choiceAI = false;      // Default AI is off
	string validate = "";
	bool runProgram = true;
	int size=0, strengthChoice=0, intChoiceAI=0, playAgain=0;
	InputVal check(validate);
	

	std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl << std::endl;



	std::cout << "Do you want to choose different strengths for the tools ? Enter 1 for yes or 2 for no." << std::endl;
	strengthChoice = integerInputValidation(1, 2);


	// Variables to hold the Tool strengths (if needed)
	int rStr, pStr, sStr;

	// Initiate three tools
	Tool *RockPtr = 0, *PaperPtr = 0, *ScissorPtr = 0;

	// Initiating Tool objects with user defined strenghts
	if (strengthChoice == 1)
	{
		std::cout << "Enter an integer for the Rock's strength value: ";
		//cin >> rStr;
		std::cin.ignore();
		getline(std::cin, validate);
		check.resetInput(validate);
		//check(validate);
		check.setRange(0, 10000000);
		rStr = check.checkIntRangeConvert();


		//rStr = integerInputValidation(0, 10000000);
		std::cout << "Enter an integer for the Paper's strength value: ";
		//cin >> pStr;
		getline(std::cin, validate);
		check.resetInput(validate);
		check.setRange(0, 10000000);
		pStr = check.checkIntRangeConvert();
		//pStr = integerInputValidation(0, 10000000);

		std::cout << "Enter an integer for the Scissor's strength value: ";
		//cin >> sStr;
		//sStr = integerInputValidation(0, 10000000);
		getline(std::cin, validate);
		check.resetInput(validate);
		check.setRange(0, 10000000);
		sStr = check.checkIntRangeConvert();

		// Now create Tool objects using user entered strenghts
		RockPtr = new Rock(rStr);
		PaperPtr = new Paper(pStr);
		ScissorPtr = new Scissors(sStr);

	// Initiate with default strength of 1 in constructor
	} 
	
	if (strengthChoice == 2)

	{
		RockPtr = new Rock();
		PaperPtr = new Paper();
		ScissorPtr = new Scissors();
	}



//Ask for random or AI controlled game
	
		std::cout << "Do you want the AI to be on? Enter 1 for yes or 2 for no." << std::endl;
		intChoiceAI = integerInputValidation(1, 2);

	if (intChoiceAI ==1)
	{
		choiceAI = true;
	}
	

	if (intChoiceAI == 2)
	{
		choiceAI = false;
	}

	

	// Create game object with three tools
	RPSGame game(RockPtr, PaperPtr, ScissorPtr, choiceAI);

	// Main program loop
	while (runProgram)
	{
		// RPS Menu
		std::cout << "Enter r for Rock" << std::endl;
		std::cout << "Enter p for Paper" << std::endl;
		std::cout << "Enter s for Scissors" << std::endl;
		std::cout << "Enter e to Exit" << std::endl;

		/*std::cin.clear();
		//http://stackoverflow.com/questions/18036619/my-cin-is-being-ignored-inside-a-while-loop
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/

		// Get and validate input 
		do
		{
			std::cin >> validate;
			size = validate.length();
			userChoice = validate[0]; //Grab first element of string
			if (!((userChoice == 'r') || (userChoice == 'p') || (userChoice == 's') || (userChoice == 'e')) || (size != 1))
			{
				std::cout << "Please enter a valid response." << std::endl;
			}
		} while (!((userChoice == 'r') || (userChoice == 'p') || (userChoice == 's') || (userChoice == 'e')) || (size != 1));



		if (userChoice == 'r')
		{
			game.setUserTool('r');
			game.play();

		}


		if (userChoice == 'p')
		{
			game.setUserTool('p');
			game.play();

		}


		if (userChoice == 's')
		{
			game.setUserTool('s');
			game.play();

		}


		if (userChoice == 'e')
		{
			runProgram = false;
			std::cout << "You have exited!";
			delete RockPtr;
			delete PaperPtr;
			delete ScissorPtr;
			RockPtr = 0; // Could use Nullprt
			PaperPtr = 0; // Could use Nullprt
			ScissorPtr = 0; // Could use Nullprt
			return 0;

		}




		// Run game with user selected tool vs. computer selected tool
	//	game.play();

	//std::cin.ignore()


		std::cin.clear();
		//http://stackoverflow.com/questions/18036619/my-cin-is-being-ignored-inside-a-while-loop
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Would you like to play again? Enter 1 for yes or 2 for no." << std::endl;
		
			playAgain = integerInputValidation(1, 2);
		

			//std::cin.ignore();


			if (playAgain == 1)
			{
				runProgram = true;

			}
			

			if (playAgain == 2)
			{
				std::cout << "Thanks for playing!" << std::endl;
				runProgram = false;

			}
			



			}




	 

	// Deallocate tools
	delete RockPtr;
	delete PaperPtr;
	delete ScissorPtr;
	RockPtr = 0; // Could use Nullprt
	PaperPtr = 0; // Could use Nullprt
	ScissorPtr = 0; // Could use Nullprt

	return 0;
}
