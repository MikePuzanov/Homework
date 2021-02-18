#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct ListElement
{
	int value;
	struct ListElement* next;
	struct ListElement* previous;
} ListElement;

typedef struct List
{
	int length;
	ListElement* head;
	ListElement* tail;
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

int getValue(List* list, int index)
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
	return currentElement->value;
}

int getLength(List* list)
{
	return list->head ? list->length : NULL;
}

void append(List* list, const int value)
{
	ListElement* checkNode = list->head;
	ListElement* newNode = (ListElement*)malloc(sizeof(ListElement));
	if (newNode == NULL)
	{
		return;
	}
	list->length++;
	newNode->value = value;
	newNode->next = list->head;
	if (list->head == NULL)
	{
		list->tail = newNode;
	}
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
			free(oldNode);
			return true;
		}
		list->head = list->head->next;
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
			free(oldNode);
			return true;
		}
		currentIndex++;
		currentNode = currentNode->next;
	}
}

List* reversalList(List* list)
{
	ListElement* oldListElement = list->head;
	List* newList = createList();
	while (oldListElement)
	{
		append(newList, oldListElement->value);
		oldListElement = oldListElement->next;
	}
	deleteList(&list);
	return newList;
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

void printList(List* list)
{
	ListElement* node = list->head;
	while (node)
	{
		printf("%i ", node->value);
		node = node->next;
	}
}