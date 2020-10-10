#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binaryTransfer(int array[], int number)
{
	int index = 0;
	while (number > 0)
	{
		if ((number) & 1)
		{
			array[index] = 1;
		}
		else
		{
			array[index] = 0;
		}
		index++;
		number = number >> 1;
	}
	return index;
}

void printfarray(int array[], int size)
{
	while (size > 0)
	{ 
		printf("%i", array[size - 1]);
		size--;
	}
}

int addition(int arrayFirst[], int sizeFirst, int arraySecond[], int sizeSecond, int arraySum[])
{	
	int sum = 0;
	int add = 0;
	int size = 0;
	if (sizeFirst >= sizeSecond)
	{
		 size = sizeFirst;
	}
	else
	{
		size = sizeSecond;
	}
	for (int i = 0; i < size; ++i)
	{
		if ((arrayFirst[i] == 1) && (arraySecond[i] == 1))
		{
			if (add == 1)
			{
				arraySum[i] = 1;
			}
			else
			{
				arraySum[i] = 0;
			}
			add = 1;
		}
		if ((arrayFirst[i] == 0) && (arraySecond[i] == 0))
		{
			if (add == 1)
			{
				arraySum[i] = 1;
				add = 0;
			}
			else
			{
				arraySum[i] = 0;
			}
		}
		if ((arrayFirst[i] == 1) && (arraySecond[i] == 0))
		{
			if (add == 1)
			{
				arraySum[i] = 0;
			}
			else
			{
				arraySum[i] = 1;
			}
		}
		if ((arrayFirst[i] == 0) && (arraySecond[i] == 1))
		{
			if (add == 1)
			{
				arraySum[i] = 0;
			}
			else
			{
				arraySum[i] = 1;
			}
		}
	}
	if (add == 1)
	{
		arraySum[size] = 1;
		size++;
	}
	return size;
}

int decimalTransfer(int array[], int size)
{
	int number = 0;
	int power = 1;
	for (int i = 0; i < size; ++i)
	{
		number += array[i] * power;
		power *= 2;
	}
	return number;
}