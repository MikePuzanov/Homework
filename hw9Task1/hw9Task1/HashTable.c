#include "HashTable.h"
#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 10

typedef struct Hash
{
	List** hashTable;
	int length;
	int element;
	float fillFactor;
} Hash;

Hash* createHashTable()
{
	Hash* table = malloc(sizeof(Hash));
	if (table == NULL)
	{
		return NULL;
	}
	table->length = SIZE;
	table->element = 0;
	table->fillFactor = 0.0f;
	table->hashTable = malloc(SIZE * sizeof(List*));
	if (table->hashTable == NULL)
	{
		free(table);
		return NULL;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		table->hashTable[i] = createList();
	}
	return table;
}

int hashFunction(const char* value, const int hashSize) 
{
	int result = 0;
	int power = 1;
	for (int index = 0; value[index] != '\0'; ++index)
	{
		result = (result * power + (int)value[index]);
		power = power * 2 + 1;
	}
	return abs(result) % hashSize;
}

int getHashSize(Hash* hashTable)
{
	return hashTable == NULL ? 0 : hashTable->length;
}

bool rehash(Hash* hashTable)
{
	List** newHashTable = malloc(hashTable->length * 2 * sizeof(List*));
	if (newHashTable == NULL)
	{
		return false;
	}
	for (int i = 0; i < (hashTable->length * 2); i++)
	{
		newHashTable[i] = createList();
	}
	for (int i = 0; i < hashTable->length; i++)
	{
		while (getLength(hashTable->hashTable[i]) != 0)
		{
			const char* word = getWord(hashTable->hashTable[i], 0);
			int key = hashFunction(word, hashTable->length * 2);
			rePush(newHashTable[key], word, getFrequency(hashTable->hashTable[i], 0));
			deleteNode((hashTable->hashTable[i]), 0);
		}
		free(hashTable->hashTable[i]);
	}
	free(hashTable->hashTable);
	hashTable->length *= 2;
	hashTable->hashTable = newHashTable;
	hashTable->fillFactor = (float)hashTable->element / hashTable->length;
	return true;
}

void add(Hash* hashTable, const char* word)
{
	if (hashTable == NULL)
	{
		return;
	}
	if (hashTable->fillFactor > 0.8f)
	{
		rehash(hashTable);
	}
	int key = hashFunction(word, hashTable->length);
	int oldLength = getLength(hashTable->hashTable[key]);
	append(hashTable->hashTable[key], word);
	if (oldLength != getLength(hashTable->hashTable[key]))
	{
		hashTable->element++;
		hashTable->fillFactor = (float)hashTable->element / hashTable->length;
	}
}

void printFrequency(Hash* hashTable)
{
	for (int i = 0; i < hashTable->length; ++i)
	{
		for (int j = 0; j < getLength(hashTable->hashTable[i]); ++j)
		{
			printf("%s - %i раз.\n", getWord(hashTable->hashTable[i], j), getFrequency(hashTable->hashTable[i],  j));
		}
	}
}

float fillFactor(Hash* hashTable)
{
	return hashTable == NULL ? 0 : hashTable->fillFactor;
}

void listLength(Hash* hashTable, int* max, float* mid)
{
	for (int i = 0; i < hashTable->length; ++i)
	{
		List* list = hashTable->hashTable[i];
		int count = getLength(list);
		if (count > *max)
		{
			*max = count;
		}
		*mid += count;
	}
	*mid = (float)*mid / hashTable->length;
}

void deleteHashTable(Hash** hashTable)
{
	for (int i = 0; i < (*hashTable)->length; ++i)
	{
		deleteList(&(*hashTable)->hashTable[i]);
	}
	free((*hashTable)->hashTable);
	free(*hashTable);
	*hashTable = NULL;
}