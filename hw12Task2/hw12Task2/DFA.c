#include "DFA.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ANY 0
#define SLASH 1
#define STAR 2
#define STATESNUMBER 5
#define SYMBOLSNUMBER 3

enum STATE
{
	notInComment,
	forwardSlashStart,
	starStart,
	starEnd,
	forwardSlashEnd
};

int** readStateTable(const char* fileName)
{
	FILE* table = fopen(fileName, "r");
	int** statesTable = calloc(STATESNUMBER, sizeof(int*));
	for (int i = 0; i < STATESNUMBER; i++)
	{
		statesTable[i] = calloc(SYMBOLSNUMBER, sizeof(int));
	}
	for (int i = 0; i < STATESNUMBER; i++)
	{
		for (int j = 0; j < SYMBOLSNUMBER; j++)
		{
			fscanf(table, "%i", &statesTable[i][j]);
		}
	}
	fclose(table);
	return statesTable;
}

void deleteTable(int** statesTable)
{
	for (int i = 0; i < STATESNUMBER; i++)
	{
		free(statesTable[i]);
	}
	free(statesTable);
}

char* DFA(const char* string, int** statesTable, bool* isInComment)
{
	char* answer = calloc(strlen(string) + 1, sizeof(char));
	int state = *isInComment ? starStart : 0;
	int index = 0;
	while (true)
	{
		char token = string[index];
		if (token == '\0' || token == '\n')
		{
			answer[strlen(answer) + 1] = '\0';
			return answer;
		}
		switch (state)
		{
		case notInComment:
			if (token == '/')
			{
				state = statesTable[state][SLASH];
				break;
			}
			break;
		case forwardSlashStart:
			if (token == '*')
			{
				state = statesTable[state][STAR];
				strcat(answer, "/*");
				*isInComment = true;
				break;
			}
			else if (token != '/')
			{
				state = statesTable[state][ANY];
			}
			break;
		case starStart:
			answer[strlen(answer)] = token;
			if (token == '*')
			{
				state = statesTable[state][STAR];
			}
			else if (token == '/')
			{
				state = statesTable[state][SLASH];
			}
			else
			{
				state = statesTable[state][ANY];
			}
			break;
		case starEnd:
			answer[strlen(answer)] = token;
			if (token == '*')
			{
				state = statesTable[state][STAR];
			}
			else if (token == '/')
			{
				state = statesTable[state][SLASH];
				*isInComment = false;
			}
			else
			{
				state = statesTable[state][ANY];
			}
			break;
		case forwardSlashEnd:
			if (token == '*')
			{
				state = statesTable[state][STAR];
			}
			else if (token == '/')
			{
				state = statesTable[state][SLASH];
			}
			else
			{
				state = statesTable[state][ANY];
			}
			break;
		}
		index++;
	}
}