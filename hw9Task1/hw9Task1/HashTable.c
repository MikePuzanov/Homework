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
}
Node;

int hashFunction(char* value) 
{
	int result = 0;
	for (int index = 0; value[index] != '\0'; ++index)
	{
		result = (result + value[index]) % SIZE; // hashSize == 256;
	}
	result = abs(result);
	if (result > 255)
	{
		return result % 256;
	}
	return abs(result);
}

Node* insert(char* word, Node** hashTable)
{
	Node* mainNode;
	Node* newNode = malloc(sizeof(Node));
	int index = hashFunction(word);
	mainNode = hashTable[index];
	hashTable[index] = newNode;
	newNode->next = mainNode;
	char* newWord = malloc(25 * sizeof(char));
	strcpy(newWord, word);
	newNode->word = newWord;
	return newNode;
}

Node** createHashTable(const char fileName[], Node*** hashTable)
{
	FILE* file = fopen(fileName, "r");
	while (!feof(file))
	{
		char word[15];
		char symbol = fgetc(file);
		if (symbol == " ")
		{
			continue;
		}
		int i = 0;
		while (!feof(file) && symbol != '.' && symbol != '-' && symbol != ',' && symbol != ':' && symbol != ';' && symbol != ' ')
		{
			word[i] = symbol;
			symbol = fgetc(file);
			++i;
		}
		word[i] = '\0';
		//fscanf(file, "%s", &word);
		int index = hashFunction(&word);
		*hashTable[index] = insert(&word, hashTable);
	}
	fclose(file);
}