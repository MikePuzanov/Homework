#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binaryTransfer( int number)
{
	int element = 0;
	int power = 1;
	int remainder = 0;
	while (number > 0)
	{
		remainder = number % 2;
		element = element + power * remainder;
		power *= 10;
		number = number / 2;
	}
	return element;
}

int addition(int firstElement, int secondElement)
{
	int sum = 0;
	int power = 1;
	int add = 0;
	while (firstElement > 0 || secondElement > 0)
	{
		sum += (firstElement % 2 + secondElement % 2 + add) % 2 * power;
		power *= 10;
		if ((firstElement % 2 + secondElement % 2) > 1)
		{
			add = 1;
		}
		else
		{
			add = 0;
		}
		secondElement /= 10;
		firstElement /= 10;
	}
	return sum;
}

int decimalTransfer(int element)
{
	int number = 0;
	int power = 1;
	while (element > 0)
	{
		number += element % 2 * power;
		power *= 2;
		element /= 10;
	}
	return number;
}

bool test()
{
	
}