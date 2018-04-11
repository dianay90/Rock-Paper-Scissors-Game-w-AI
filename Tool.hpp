/********************************************************************
** Authors: Gerik Illo, Jimmy Nguyen, Diana Oh,
** Adam Spivey, and Tiffany Warner
** Date: May 21 2017
** Description: Group Project: Tool class. This class represents
** the base class of three tools used for simulating a Rock, Paper, 
** Scissors Game. It has two member variables to designate the 
** strength of the tool and the type of tool. It contains a pure
** virtual function fight which determines a tool's strength when 
** compared to another tool.  
********************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

class Tool
{
protected:
	int strength;
	char type;
public:
	virtual void setStrength(int);
	virtual int fight(Tool * object) = 0;
	virtual int getStrength();
	virtual char getType();
};
#endif
