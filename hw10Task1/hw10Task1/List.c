#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement
{
    int city;
    int roadLenght;
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

int getLength(List* list)
{
	return list->head ? list->length : NULL;
}

void append(List* list, const int element, const int roadLength)
{
    ListElement* checkNode = list->head;
    ListElement* newNode = (ListElement*)malloc(sizeof(ListElement));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->city = element;
    newNode->roadLenght = roadLength;
    list->length++;
    newNode->next = list->head;
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

int getRoadLength(List* list, int index)
{
	if (index >= getLength(list) || index < 0)
	{
		return -1;
	}
	ListElement* node = list->head;
	for (int i = 0; i < index; ++i)
	{
		node = node->next;
	}
    return node->roadLenght;
}

int getCity(List* head)
{
    return head->city;
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        removeFromHead(head);
    }
    free(*head);
    *head = NULL;
}

bool isEmpty(List* head)
{
    return head == NULL;
}

List* getLast(List* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (head->next)
    {
        head = head->next;
    }
    return head;
}