/********************************************************************
** Author: Tiffany Warner
** Date: April 30 2017
** Description: Input Validation class implementation file
********************************************************************/

#include "InputVal.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
/********************************************************************
** Description:           Constructor
** Assigns string to the input member variable and assigns the
** the length of the string to the sizeOfString variable.
********************************************************************/
InputVal::InputVal(string userInput)
{
	input = userInput;
	sizeOfString = userInput.length();
}
/********************************************************************
** Description:          Overloaded Constructor
** Accepts an integer value
********************************************************************/
InputVal::InputVal(int userInput)
{
	intValue = userInput;
}
/********************************************************************
** Description:           resetInput
** Resets the value of the input variable and the size of
** the string variable.
********************************************************************/
void InputVal::resetInput(string userInput)
{
	input = userInput;
	sizeOfString = userInput.length();
}
/********************************************************************
** Description:           setRange
** This function sets the max and minimum range variables that can
** be used with the checkRange function.
********************************************************************/
void InputVal::setRange(int min, int max)
{
	minRangeVal = min;
	maxRangeVal = max;
}
/********************************************************************
** Description:           checkInt
** This function checks if the input is an integer
********************************************************************/
bool InputVal::checkInt()
{
	//Flag to signal if a non digit is found in the string
	bool invalidInputFlag = false;
	bool checkElement1 = true;
	//Checks each element in the string to make sure it's a digit
	for (int count = 0; count < sizeOfString; count++)
	{
		//Skip first element if the element is a negative sign
		if (input[0] == '-' && checkElement1)
		{
			count++;
			checkElement1 = false;
		}
		//Skip first element if the element is a positive sign
		if (input[0] == '+' && checkElement1)
		{
			count++;
			checkElement1 = false;
		}
		bool isInt = true;
		isInt = isdigit(input[count]);
		if (isInt == false)
		{
			invalidInputFlag = true;
		}
	}
	//Check if input is empty
	if (sizeOfString == 0)
	{
		invalidInputFlag = true;
	}
	if (invalidInputFlag)
	{
		return false;
	}

	return true;

}
/********************************************************************
** Description:           checkString
** This function checks if the input is a string. Strings can
** contain characters, digits, and spaces. It will check that the 
** string is not empty and that it is no larger than the specified 
** size provided by the function argument. It returns true if it
** meets all requires and false if it fails. 
********************************************************************/
bool InputVal::checkString(int size)
{
	//Flag variables
	bool allSpaces = false;
	bool printChar = true;
	bool canNotPrint = false;
	//Counter for counting spaces
	int spaceCount = 0;

	//If the string is bigger than the specified size
	if (sizeOfString > size)
	{
		return false;
	}
	//Checks each element in the string
	for (int count = 0; count < sizeOfString; count++)
	{
		printChar = isprint(input[count]);
		allSpaces = isspace(input[count]);
		//Check if a character is not printable
		//Potential issues. Hit enter might create \n which is not printable
		if (printChar == false)
		{
			canNotPrint = true;
		}
		if (allSpaces == true)
		{
			spaceCount++;
		}
	}
	//Check if the input is empty
	if (sizeOfString == 0)
	{
		return false;
	}
	//Check if the entire string is spaces
	if ((spaceCount == sizeOfString) || (canNotPrint == true))
	{
		return false;
	}
	return true;
}
/********************************************************************
** Description:           convertToInt
** This function converts the string to an actual integer data type
********************************************************************/
int InputVal::convertToInt()
{
	return intValue = std::stoi(input);
}
/********************************************************************
** Description		checkRange
** This function will check to see if an integer is within a range
********************************************************************/
bool InputVal::checkRange(int num)
{
	//If it's in range, return true
	if (num >= minRangeVal && num <= maxRangeVal)
	{
		return true;
	}
	//Otherwise, it's out of range, return false
	return false;
}
/********************************************************************
** Description		checkRange
** Overloaded function will check to see if a double is within a range
********************************************************************/
bool InputVal::checkRange(double num)
{
	//If it's in range, return true
	if (num >= minRangeVal && num <= maxRangeVal)
	{
		return true;
	}
	//Otherwise, it's out of range, return false
	return false;
}
/********************************************************************
**                      CheckIntRangeConvert
** This function checks that the input is an integer data type,
** that it is within a specified range and then converts the string
** to an integer. It utilizes the checkInt, withinRange
** and convertToInt member functions
*********************************************************************/
int InputVal::checkIntRangeConvert()
{
	bool checkingInput = true; //Outer loop flag variable
	bool validInput;
	bool withinRange = false;
	string newInput;


	while (checkingInput == true)
	{	//Checking if input is an integer
		validInput = checkInt();
		while (validInput == false || withinRange == false)
		{
			//Reset validInput
			validInput = checkInt();

			//Check if input is not an int or there was no input
			if ((validInput == false || sizeOfString == 0))
			{
				cout << "Invalid entry. Please enter an integer: ";

				getline(cin, newInput);
				resetInput(newInput);
				//Check the new value
				validInput = checkInt();
			}
			//Converting the string to an integer
			if (validInput)
			{
				intValue = convertToInt();

				//Check range of the integer
				withinRange = checkRange(intValue);

				//If the range is not correct, then the input is not valid.
				if (withinRange == false)
				{
					//Input is not valid 
					cout << "Out of range. Please enter a number from "
						<< minRangeVal << " to " << maxRangeVal << ": ";

					getline(cin, newInput);
					resetInput(newInput);
					//Check the new value
					validInput = checkInt();
				}
			}
		}
		//If the input is both an integer and in range, stop checking
		if (validInput && withinRange)
		{
			checkingInput = false;
		}
	}
	return intValue;
}

