#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct ListElement
{
	char* word;
	int frequency;
	struct ListElement* next;
} ListElement;

typedef struct List
{
	int length;
	ListElement* head;
} List;

List* createList()
{
	List* newList = malloc(sizeof(List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->length = 0;
	newList->head = NULL;
	return newList;
}

char* getWord(List* list, int index)
{
	if (index < 0 || index >= getLength(list))
	{
		return 0;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (currentIndex != index)
	{
		currentElement = currentElement->next;
		currentIndex++;
	}
	return currentElement->word;
}

int getFrequency(List* list, int index)
{
	ListElement* node = list->head;
	while (node != NULL)
	{
		if (strcmp(node->word, getWord(list, index)) == 0)
		{
			return node->frequency;
		}
		node = node->next;
	}
	return 0;
}

int getLength(List* list)
{
	return list->head ? list->length : NULL;
}

void append(List* list, const char* word)
{
	ListElement* checkNode = list->head;
	while (checkNode)
	{
		if (strcmp(checkNode->word, word) == 0)
		{
			checkNode->frequency++;
			return true;
		}
		checkNode = checkNode->next;
	}
	ListElement* newNode = (ListElement*)malloc(sizeof(ListElement));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->word = malloc((strlen(word) + 1) * sizeof(char));
	strcpy(newNode->word, word);
	newNode->frequency = 1;
	list->length++;
	newNode->next = list->head;
	list->head = newNode;
}

void rePush(List* list, const char* word, const int frequency)
{
	ListElement* newNode = (ListElement*)malloc(sizeof(ListElement));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->word = malloc((strlen(word) + 1) * sizeof(char));
	strcpy(newNode->word, word);
	newNode->frequency = frequency;
	newNode->next = list->head;
	list->length++;
	list->head = newNode;
}

bool deleteNode(List* list, int index)
{
	if (index < 0 || index >= getLength(list))
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (index == 0)
	{
		ListElement* oldNode = list->head;
		if (getLength(list) == 1)
		{
			list->head = NULL;
			list->length--;
			free(oldNode->word);
			free(oldNode);
			return true;
		}
		list->head = list->head->next;
		free(oldNode->word);
		free(oldNode);
		list->length--;
		return true;
	}
	int currentIndex = 0;
	ListElement* currentNode = list->head;
	while (true)
	{
		if (index - currentIndex == 1)
		{
			ListElement* oldNode = currentNode->next;
			currentNode->next = currentNode->next->next;
			list->length--;
			free(oldNode->word);
			free(oldNode);
			return true;
		}
		currentIndex++;
		currentNode = currentNode->next;
	}
}

void deleteList(List** list)
{
	while (getLength(*list) > 0)
	{
		deleteNode(*list, 0);
	}
	free(*list);
	*list = NULL;
}