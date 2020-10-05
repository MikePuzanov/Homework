#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void binaryTransfer( int number, bool array[], int size)
{
	int element = 0;
	for (int index = 0; index < size; ++index)
	{

		if (number % 2 == 1)
		{
			array[index] = true;
		}
		else
		{
			array[index] = false;
		}
		number = number / 2;
	}
}

void addition(bool arrayFirst[], bool arraySecond[], bool arraySum[], int size)
{
	int sum = 0;
	int add = 0;
	for (int index = 0; index < size; ++index)
	{
		if ((arrayFirst[index]) & (arraySecond[index]))
		{
			arraySum[index] = false;
			add = 1;
		}
		else
		{
			if ((arrayFirst[index]) | (arraySecond[index]))
			{
				if (add == 1)
				{
					arraySum[index] = false;
					add = 0;
				}
				else
				{
					arraySum[index] = true;
				}
			}
			else
			{
				arraySum[index] = false;
			}
		}
	}
}

int decimalTransfer(bool arraySum[], int size)
{
	int number = 0;
	int power = 1;
	for (int index = 0; index < size; ++index)
	{
		if (arraySum[index])
		{
			number += 1 * power;
		}
		power *= 2;
	}
	return number;
}

bool test()
{
	
}

int sum(int first, int second)
{
	int sum = 0;
	sum = first + second;
	return sum;
}