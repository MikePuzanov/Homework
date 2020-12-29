#include "IsRealNumber.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

enum States
{
	searchFirstDigit,
	integerPart,
	dot,
	searchNumberEuler,
	numberEuler,
	checkDigit,
	remainingNumber
};

bool isRealNumber(const char* line)
{
	int index = 0;
	int state = 0;
	while (true)
	{
		char token = line[index];
		switch (state)
		{
		case searchFirstDigit:
			if (isdigit(token))
			{
				state = integerPart;
				break;
			}
			return false;
		case integerPart:
			if (isdigit(token))
			{
				break;
			}
			else if (token == '.')
			{
				state = dot;
				break;
			}
			else if (token == 'E')
			{
				state = numberEuler;
				break;
			}
			return token == '\0' || token == '\n';
		case dot:
			if (isdigit(token))
			{
				state = searchNumberEuler;
				break;
			}
			return false;
		case searchNumberEuler:
			if (isdigit(token))
			{
				break;
			} 
			else if (token == 'E')
			{
				state = numberEuler;
				break;
			}
			return token == '\0' || token == '\n';
		case numberEuler:
			if (token == '+' || token == '-')
			{
				state = checkDigit;
				break;
			}
			else if (isdigit(token))
			{
				state = remainingNumber;
				break;
			}
			return false;
		case checkDigit:
			if (isdigit(token))
			{
				state = remainingNumber;
				break;
			}
			return false;
		case remainingNumber:
			if (isdigit(token))
			{
				break;
			}
			return token == '\0' || token == '\n';
		}
		++index;
	}
}