#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 256

typedef struct Node
{
	Node* next;
	char* word;
} Node;

typedef struct Hash
{
	Node** hashTable;
	int length;
	int notEmpty;
} Hash;

int hashFunction(char* value) 
{
	int result = 0;
	for (int index = 0; value[index] != '\0'; ++index)
	{
		result = (result * 17 + value[index]) % SIZE;
	}
	return abs(result) % SIZE;
}


Hash* insert(char* word, Hash* hashTable)
{
	int index = hashFunction(word);
	Node* mainNode = hashTable->hashTable[index];
	if (mainNode == NULL)
	{
		hashTable->notEmpty++;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->next = mainNode;
	char* newWord = malloc(25 * sizeof(char));
	strcpy(newWord, word);
	newNode->word = newWord;
	hashTable->hashTable[index] = newNode;
	return hashTable;
}

Node* createList()
{
	Node* node = NULL;
	return node;
}

Hash* createHashTable()
{
	Hash* table = malloc(sizeof(Hash));
	if (table == NULL)
	{
		return NULL;	
	}
	table->length = SIZE;
	table->notEmpty = 0;
	table->hashTable = malloc(SIZE * sizeof(Node*));
	if (table->hashTable == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		table->hashTable[i] = createList();
	}
	return table;
}

int frequency(Hash* hash, int index, char word[])
{
	int count = 0;
	Node* node = hash->hashTable[index];
	while (node != NULL)
	{
		if (strcmp(word, node->word) == 0)
		{
			count++;
		}
		node = node->next;
	}
	return count;
}

void printFrequency(Hash* hashTable, char fileName[])
{
	FILE* file = fopen(fileName, "r");
	while (!feof(file))
	{
		char word[25];
		char symbol = fgetc(file);
		if (symbol == ' ' || symbol == '\n')
		{
			continue;
		}
		int i = 0;
		while (!feof(file) && symbol != '.' && symbol != '\n' && symbol != '-' && symbol != ',' && symbol != ':' && symbol != ';' && symbol != ' ')
		{
			word[i] = symbol;
			symbol = fgetc(file);
			++i;
		}
		word[i] = '\0';
		int index = hashFunction(&word);
		printf("%s - %i раз.\n", word, frequency(hashTable, index, word));
	}
	fclose(file);
}

float fillFactor(Hash* hashTable)
{
	return (float)hashTable->notEmpty / hashTable->length;
}

void listLenght(Hash* hashTable, int* max, float* mid)
{
	for (int i = 0; i < SIZE; ++i)
	{
		Node* node = hashTable->hashTable[i];
		int count = 0;
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
		if (count > *max)
		{
			*max = count;
		}
		*mid += count;
	}
	*mid = (float)*mid / hashTable->notEmpty;
}