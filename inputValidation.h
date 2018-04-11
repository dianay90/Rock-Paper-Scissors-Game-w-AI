/*********************************************************************
** Program name: Lab 6 Double Linked List
** Author: Diana Oh
** Date: 5/11/2017
** Description: This program uses a double linked list to let the user add a node to the head of the list, add a node to the tail of the list,
*print the head value, print the tail value, delete from head, delete from tail, and traverse the list reversely.
*
*The program can be run using the makefile.
**********************************************************************/

/* Input validation function validates user input to ensure it's an integer. It take in arguments integer min and 
integer max to ensure the input the user enters is within that range and returns an int. 
*/



#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
#include <iostream>
using namespace std;
#include <string>
#include <cctype>

	int integerInputValidation(int min, int max);
	string stringInputValidation();
	int negativeIntegerInputValidation(int min, int max);

#endif



