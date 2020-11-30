#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 25

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

int hashFunction(char* value, int hashSize) 
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

Hash* insert(char* word, Hash* hashTable)
{
	int index = hashFunction(word, hashTable->length);
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

void push(Node** head, char* word)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	char* newWord = malloc(25 * sizeof(char));
	strcpy(newWord, word);
	newNode->word = newWord;
	newNode->next = (*head);
	(*head) = newNode;
}

void pop(Node** head)
{
	Node* delete = NULL;
	if (head == NULL)
	{
		return;
	}
	delete = (*head);
	free((*head)->word);
	(*head) = (*head)->next;
	free(delete);
	return;
}

void deleteRowNode(Node** head)
{
	while ((*head)->next)
	{
		pop(head);
		*head = (*head)->next;
	}
	free(*head);
}

bool rehash(Hash* hashTable)
{
	Node** newHashTable = malloc(hashTable->length * 2 * sizeof(Node*));
	if (newHashTable == NULL)
	{
		return false;
	}
	for (int i = 0; i < (hashTable->length * 2); i++)
	{
		newHashTable[i] = createList();
	}
	hashTable->notEmpty = 0;
	for (int i = 0; i < hashTable->length; i++)
	{
		while (hashTable->hashTable[i] != NULL)
		{
			char* word = hashTable->hashTable[i]->word;
			int key = hashFunction(word, hashTable->length * 2);
			if (newHashTable[key] == NULL)
			{
				hashTable->notEmpty++;
			}
			push(&newHashTable[key], word);
			pop(&(hashTable->hashTable[i]));
		}
		free(hashTable->hashTable[i]);
	}
	hashTable->length *= 2;
	free(hashTable->hashTable);
	hashTable->hashTable = newHashTable;
	return true;
}


Hash* readFromFile(Hash* hashTable, char fileName[])
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
		if ((hashTable->length - hashTable->notEmpty) < 10 )
		{
			rehash(hashTable);
		}
		int index = hashFunction(&word, hashTable->length);
		hashTable = insert(word, hashTable);
	}
	fclose(file);
	return hashTable;
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
		int index = hashFunction(&word, hashTable->length);
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