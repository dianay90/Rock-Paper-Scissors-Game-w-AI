/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Tool Class implementation file
********************************************************************/
#include "Tool.hpp"
/********************************************************************
** Description:		setStrength
** Accepts an integer and sets it as the strength of the tool
********************************************************************/
void Tool::setStrength(int str)
{
	strength = str;
}
/********************************************************************
** Description:			getStrength
** Returns the strength of the tool as an integer
********************************************************************/
int Tool::getStrength()
{
	return strength;
}
/********************************************************************
** Description:			getType
** Returns the type of the tool as an integer
********************************************************************/
char Tool::getType()
{
	return type;
}