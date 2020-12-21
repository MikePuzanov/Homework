#include "IsRealNumber.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isRealNumber(const char* line)
{
	int index = 0;
	int state = 0;
	while (true)
	{
		char token = line[index];
		switch (state)
		{
		case 0:
			if (isdigit(token))
			{
				state = 1;
				break;
			}
			return false;
		case 1:
			if (isdigit(token))
			{
				break;
			}
			else if (token == '.')
			{
				state = 2;
				break;
			}
			else if (token == 'E')
			{
				state = 3;
				break;
			}
			return token == '\0' || token == '\n' ? true : false;
		case 2:
			if (isdigit(token))
			{
				state = 3;
				break;
			}
			return false;
		case 3:
			if (isdigit(token))
			{
				break;
			} 
			else if (token == 'E')
			{
				state = 4;
				break;
			}
			return token == '\0' || token == '\n' ? true : false;
		case 4:
			if (token == '+' || token == '-')
			{
				state = 5;
				break;
			}
			else if (isdigit(token))
			{
				state = 5;
				break;
			}
			return false;
		case 5:
			if (isdigit(token))
			{
				break;
			}
			return token == '\0' || token == '\n' ? true : false;
		default:
			break;
		}
		++index;
	}
}