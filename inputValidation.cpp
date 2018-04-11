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

#include "inputValidation.h"



//This function validates whether the user input is an integer and accounts for negative integers. The arguments are min and max, which is the inclusive 
//range for the user input. The user in prompted to keep providing input until the input is valid.
int negativeIntegerInputValidation(int min, int max)
{
	bool flag = false;
	bool flag2 = false;
	string userString;
	int number=0;

	while (flag == false)
	{
		getline(cin, userString);
		flag2 = true;
		for (int index = 0; index < userString.length() && flag2 == true; index++)

		{
			// if the input is a digit 
			if (isdigit(userString[index]) || userString[index]== '-') //then make flag, is the flag is true outstide return the number 
											//
			{
				flag2 = true;
			}

			else

			{
				flag2 = false;
				cout << "Input is invalid. Please enter a valid number." << endl;
				//flag = false;
			}


		}

		//convert that number to an integer data type
		// there are no digits here
		if (flag2 == true)
		{
			number = stoi(userString);
			if ((number >= min) && (number <= max))
			{
				return number;
			}


			//digt can't be out of dounds 
			else
			{
				cout << "Input is invalid. Please enter a valid number." << endl;
				flag = false;
			}
		}




	}
}






//This function validates whether the user input is an integer. The arguments are min and max, which is the inclusive 
//range for the user input. The user in prompted to keep providing input until the input is valid.

int integerInputValidation(int min, int max)
{
	bool flag = false;
	bool flag2 = false;
	string userString;
	int number;

	while (flag == false)
	{
		getline(cin, userString);
		flag2 = true; 
		for (int index = 0; index < userString.length() && flag2==true; index++)

		{
			// if the input is a digit 
			if (isdigit(userString[index])) //then make flag, is the flag is true outstide return the number 
											//
			{
				flag2 = true;
			}

			else

			{
				flag2 = false; 
				cout << "Input is invalid. Please enter a valid number." << endl;
				//flag = false;
			}

			
		}

				//convert that number to an integer data type
		// there are no digits here
		if (flag2 == true)
			{
				number = stoi(userString);
				if ((number >= min) && (number <= max))
				{
					return number;
				}


				//digt can't be out of dounds 
				else
				{
					cout << "Input is invalid. Please enter a valid number." << endl;
					flag = false;
				}
			}



		
		}
	}





//This function validates whether the user entered alphabet characters. The user in prompted to keep providing input until the input is valid. 

string stringInputValidation()
{
	bool flag = false;
	bool flag2 = false;
	string userString;
	
	while (flag == false)
	{
		getline(cin, userString);
		flag2 = true; 
		for (int index = 0; index < userString.length() && flag2==true; index++)

		{ 
			// if the input is a digit 
			if (isalpha(userString[index])) 
											
			{
				flag2 = true;
				//problem the last number in the string can be OKAY and my code wille xecute
				
			}  

			else

			{
				flag2 = false;
				
				cout << "Input is invalid. Please enter a valid input without any spaces." << endl;
				//flag = false;
			}

			
		}

		if (flag2== true)
		{
			return userString; 
		}
		
	}

}
				
				
