#include "FSM.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

enum State
{
	firstSymbol,
	nextSymbols,
};

bool FSM(const char* string)
{
	int index = 0;
	int state = firstSymbol;
	while (true)
	{
		char token = string[index];
		if (token == '\0' || token == '\n')
		{
			return true;
		}
		switch (state)
		{
		case 0:
			if ((token <= 'z' && token >= 'a') || (token <= 'Z' && token >= 'A'))
			{
				state = nextSymbols;
				break;
			}
			return false;
		case 1:
			if (isdigit(token) || (token <= 'z' && token >= 'a') || (token <= 'Z' && token >= 'A') || token == '_')
			{
				break;
			}
			return false;
		}
		++index;
	}
}