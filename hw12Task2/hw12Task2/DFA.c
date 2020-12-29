#include "DFA.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SLASH 1
#define STAR 2
#define STATES_NUMBER 5
#define SYMBOLS_NUMBER 3

int** readStateTable(const char* fileName)
{
	FILE* table = fopen(fileName, "r");
	int** statesTable = calloc(STATES_NUMBER, sizeof(int*));
	for (int i = 0; i < STATES_NUMBER; i++)
	{
		statesTable[i] = calloc(SYMBOLS_NUMBER, sizeof(int));
	}
	for (int i = 0; i < STATES_NUMBER; i++)
	{
		for (int j = 0; j < SYMBOLS_NUMBER; j++)
		{
			fscanf(table, "%i", &statesTable[i][j]);
		}
	}
	fclose(table);
	return statesTable;
}

void deleteTable(int** statesTable)
{
	for (int i = 0; i < STATES_NUMBER; i++)
	{
		free(statesTable[i]);
	}
	free(statesTable);
}

int getSymbolIndex(char token)
{
	switch (token)
	{
	case '/':
		return 1;
	case '*':
		return 2;
	default:
		return 0;
	}
}

char* DFA(const char* string)
{
	int** statesTable = readStateTable("StateTable.txt");
	char* answer = calloc(strlen(string) + 2, sizeof(char));
	int state = 0;
	int index = 0;
	while (true)
	{
		char token = string[index];
		++index;
		if (token == '/' && state == 0)
		{
			state = statesTable[state][SLASH];
			continue;
		}
		else if (token == '*' && state == 1)
		{
			state = statesTable[state][STAR];
			strcat(answer, "/*");
			continue;
		}
		else if (state == 3 && token == '/')
		{
			answer[strlen(answer)] = '/';
		}
		else if (state > 1 && state < 4)
		{
			answer[strlen(answer)] = token;
		}
		if (token == '\0' || token == '\n')
		{
			answer[strlen(answer) + 1] = '\0';
			return answer;
		}
		state = statesTable[state][getSymbolIndex(token)];
	}
}