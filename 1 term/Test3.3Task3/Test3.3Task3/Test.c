#include "Test.h"
#include "FSM.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool test()
{
	char number[30] = "asd123";
	if (!FSM(number))
	{
		return false;
	}
	strcpy(number, "Adfa23_23");
	if (!FSM(number))
	{
		return false;
	}
	strcpy(number, "1faf");
	if (FSM(number))
	{
		return false;
	}
	strcpy(number, "_fwe2134");
	if (FSM(number))
	{
		return false;
	}
	strcpy(number, "0");
	if (FSM(number))
	{
		return false;
	}
	strcpy(number, "fs342");
	if (!FSM(number))
	{
		return false;
	}
	strcpy(number, "sdf");
	if (!FSM(number))
	{
		return false;
	}
	return true;
}