#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 10

typedef struct Node
{
	int frequency;
	Node* next;
	char* word;
} Node;

typedef struct Hash
{
	Node** hashTable;
	int length;
	int element;
	float fillFactor;
} Hash;

Node* createList()
{
	return NULL;
}

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

void push(Node** head, const char* word)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	char* newWord = malloc((strlen(word) + 1) * sizeof(char));
	strcpy(newWord, word);
	newNode->frequency = 1;
	newNode->word = newWord;
	newNode->next = (*head);
	(*head) = newNode;
}

Node* insert(const char* word, Hash* hashTable, const int index)
{
	Node* mainNode = hashTable->hashTable[index];
	Node* checkNode = mainNode;
	while (checkNode != NULL)
	{
		if (strcmp(word, checkNode->word) == 0)
		{
			checkNode->frequency++;
			return mainNode;
		}
		checkNode = checkNode->next;
	}
	push(&mainNode, word);
	hashTable->element++;
	hashTable->fillFactor = (float)hashTable->element / hashTable->length;
	return mainNode;
}

void pop(Node** head)
{
	if (head == NULL)
	{
		return;
	}
	Node* delete = NULL;
	delete = (*head);
	free((*head)->word);
	(*head) = (*head)->next;
	free(delete);
	return;
}

void deleteRowNode(Node** head)
{
	while ((*head))
	{
		pop(head);
	}
	free(*head);
	*head = NULL;
}

void rePush(Node** newHead, Node* oldHead)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	char* newWord = malloc((strlen(oldHead->word) + 1) * sizeof(char));
	strcpy(newWord, oldHead->word);
	newNode->frequency = oldHead->frequency;
	newNode->word = newWord;
	newNode->next = (*newHead);
	(*newHead) = newNode;
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
	for (int i = 0; i < hashTable->length; i++)
	{
		while (hashTable->hashTable[i] != NULL)
		{

			const char* word = hashTable->hashTable[i]->word;
			int key = hashFunction(word, hashTable->length * 2);
			rePush(&newHashTable[key], hashTable->hashTable[i]);
			pop(&(hashTable->hashTable[i]));
		}
		free(hashTable->hashTable[i]);
	}
	free(hashTable->hashTable);
	hashTable->length *= 2;
	hashTable->hashTable = newHashTable;
	hashTable->fillFactor = (float)hashTable->element / hashTable->length;
	return true;
}

Hash* readFromFile(Hash* hashTable, const char* fileName)
{
	FILE* file = fopen(fileName, "r");
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
		if (hashTable->fillFactor > 0.8f )
		{
			if (!rehash(hashTable))
			{
				return NULL;
			}
		}
		int index = hashFunction(word, hashTable->length);
		hashTable->hashTable[index] = insert(word, hashTable, index);
	}
	fclose(file);
	return hashTable;
}

int frequency(Hash* hash, const char* word)
{
	const int index = hashFunction(word, hash->length);
	Node* node = hash->hashTable[index];
	while (node != NULL)
	{
		if (strcmp(node->word, word) == 0)
		{
			return node->frequency;
		}
		node = node->next;
	}
	return 0;
}

bool checkWord(Node* head, const int index, const char* word)
{
	for (int i = 0; i < index; ++i)
	{
		if (strcmp(head->word, word) == 0)
		{
			return false;
		}
		head = head->next;
	}
	return true;
}

void printFrequency(Hash* hashTable)
{
	for (int i = 0; i < hashTable->length; ++i)
	{
		Node* node = hashTable->hashTable[i];
		int countIndex = 0;
		while (node)
		{
			countIndex++;
			char word[50];
			strcpy(word, node->word);
			if (!checkWord(hashTable->hashTable[i], countIndex - 1, word))
			{
				node = node->next;
				continue;
			}
			printf("%s - %i раз.\n", word, frequency(hashTable, word));
			node = node->next;
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
	*mid = (float)*mid / hashTable->length;
}

void deleteHashTable(Hash** hashTable)
{
	for (int i = 0; i < (*hashTable)->length; ++i)
	{
		deleteRowNode(&(*hashTable)->hashTable[i]);
	}
	free((*hashTable)->hashTable);
	free(*hashTable);
	*hashTable = NULL;
}