#include "test.h"
#include "Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool compare(int array[], int number, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] != (number & 1))
		{
			return false;
		}
		number = number >> 1;
	}
	return true;
}

bool test()
{
	int number = 0;
	int arrayFirst[32] = { 0 };
	binaryTransfer(arrayFirst, number, 32);
	if (arrayFirst[0] != 0)
	{
		return false;
	}
	number = 15;
	binaryTransfer(arrayFirst, number, 32);
	if (!compare(arrayFirst, number, 32))
	{
		return false;
	}
	number = 12;
	int arraySecond[32] = { 0 };
	binaryTransfer(arraySecond, number, 32);
	if (!compare(arraySecond, number, 32))
	{
		return false;
	}
	int arraySum[32] = { 0 };
	addition(arrayFirst, 32, arraySecond, arraySum);
	if (!compare(arraySum, 27, 32))
	{
		return false;
	}
	number = -12;
	for (int i = 0; i < 32; ++i)
	{
		arraySecond[i] = 0;
	}
	binaryTransfer(arraySecond, number, 32);
	if (!compare(arraySecond, number, 32))
	{
		return false;
	}
	addition(arrayFirst, 32, arraySecond, arraySum);
	if (!compare(arraySum, 3, 32))
	{
		return false;
	}
	number = -15;
	binaryTransfer(arrayFirst, number, 32);
	if (!compare(arrayFirst, number, 32))
	{
		return false;
	}
	addition(arrayFirst, 32, arraySecond, arraySum);
	if (!compare(arraySum, -27, 32))
	{
		return false;
	}
	return true;
}