#include "HashTable.h"
#include "List.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test()
{
	Hash* hashTable = createHashTable();
	FILE* file = fopen("Test.txt", "r");
	while (!feof(file))
	{
		char word[50];
		char symbol = fgetc(file);
		if (symbol == ' ' || symbol == '\n')
		{
			continue;
		}
		int i = 0;
		while (!feof(file) && symbol != '.' && i < 50 && symbol != '\n' && symbol != '-' && symbol != ',' && symbol != ':' && symbol != ';' && symbol != ' ')
		{
			word[i] = symbol;
			symbol = fgetc(file);
			++i;
		}
		word[i] = '\0';
		add(hashTable, word);
	}
	if (getHashSize(hashTable) != 10)
	{
		deleteHashTable(&hashTable);
		return false;
	}
	if (fillFactor(hashTable) - 0.5 > 0.001)
	{
		deleteHashTable(&hashTable);
		return false;
	}
	float mid = 0;
	int max = 0;
	listLength(hashTable, &max, &mid);
	if (max != 2)
	{
		deleteHashTable(&hashTable);
		return false;
	}
	if (mid - 0.5 > 0.1)
	{
		deleteHashTable(&hashTable);
		return false;
	}
	return true;
}