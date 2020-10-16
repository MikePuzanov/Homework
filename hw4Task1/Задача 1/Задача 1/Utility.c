#include "Utility.h"

#include <stdio.h>
#include <stdlib.h>

void arrayPrint(int array[], int size)
{
	int check = 0;
	while (size > 0)
	{
		size--;
		if (array[size] == 1)
		{
			check = 1;
		}
		if (check == 1)
		{
			printf("%i ", array[size]);
		}
	}
}

void binaryTransfer(int array[], int number, int size)
{
	for (int index = 0; index < size; ++index)
	{
		array[index] = number & 1 != 0; 
		number = number >> 1;
	}
}

int addition(int arrayFirst[], int size, int arraySecond[], int arraySum[])
{	
	int sum = 0;
	int add = 0;
	for (int i = 0; i < size; ++i)
	{
		if ((arrayFirst[i] == 1) && (arraySecond[i] == 1))
		{
			arraySum[i] = add & 1 != 0;
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
		if ((arrayFirst[i] == 1) && (arraySecond[i] == 0) || (arrayFirst[i] == 0) && (arraySecond[i] == 1))
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