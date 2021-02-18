#include "IsRealNumber.h"
#include "Test.h"

#include <stdbool.h>
#include <string.h>

bool test()
{
	char number[30] = "123";
	if (!isRealNumber(number))
	{
		return false;
	}
	strcpy(number, "123.32");
	if (!isRealNumber(number))
	{
		return false;
	}
	strcpy(number, "123.32E232");
	if (!isRealNumber(number))
	{
		return false;
	}
	strcpy(number, "123.32E+232");
	if (!isRealNumber(number))
	{
		return false;
	}
	strcpy(number, "0");
	if (!isRealNumber(number))
	{
		return false;
	}
	strcpy(number, "4fs342");
	if (isRealNumber(number))
	{
		return false;
	}
	strcpy(number, "sdf");
	if (isRealNumber(number))
	{
		return false;
	}
	return true;
}