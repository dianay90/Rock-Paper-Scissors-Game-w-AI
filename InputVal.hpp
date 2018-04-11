/********************************************************************
** Author: Tiffany Warner
** Date: April 30 2017
** Description: Input Validation class. This class takes the input
** from a user as a string. It has member functions which
** evaluates the string to determine what data type was input and for
** checking ranges and converting to the appropriate data type.
********************************************************************/
#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <string>
using std::string;

class InputVal
{
private:
	string input;
	int sizeOfString;
	int maxRangeVal;
	int minRangeVal;
	int intValue;
	double dblVal;

public:
	//Default Constructor
	InputVal();
	//Constructor that accepts a string
	InputVal(string userInput);
	//Constructor that accepts an integer
	InputVal(int userInput);

	//Validation functions for Integers
	void resetInput(std::string userInput);
	void setRange(int min, int max);

	//Validation functions
	bool checkInt();
	bool checkString(int size);
	bool checkChar();

	//Conversion functions for string input
	int  convertToInt();
	double convertToDouble();

	//Range functions
	bool checkRange(int num);
	bool checkRange(double num);

	//Combination functions
	int checkIntRangeConvert();
};

#endif