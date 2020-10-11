#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool compare(int array[], int number, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if ((array[i]) != (number % 2))
		{
			return false;
		}
		number /= 2;
	}
	return true;
}

bool test()
{
	int number = 0;
	int arrayFirst[32] = { 0 };
	binaryTransfer(arrayFirst, number);
	if (arrayFirst[0] != 0)
	{
		return false;
	}
	number = 15;
	binaryTransfer(arrayFirst, number);
	if (!compare(arrayFirst, number, 4))
	{
		return false;
	}
	number = 12;
	int arraySecond[32] = { 0 };
	binaryTransfer(arraySecond, number);
	if (!compare(arraySecond, number, 4))
	{
		return false;
	}
	int arraySum[32] = { 0 };
	addition(arrayFirst, 4, arraySecond, 4, arraySum);
	if (!compare(arraySum, 27, 5))
	{
		return false;
	}
	return true;
}