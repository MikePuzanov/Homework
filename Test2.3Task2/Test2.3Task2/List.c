#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement {
	int value;
	struct ListElement* next;
} ListElement;

typedef struct List {
	int lenght;
	ListElement* head;
} List;

List* createList()
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->lenght = 0;
	newList->head = NULL;
	return newList;
}

int getLenght(List* list)
{
	return list->lenght;
}


void push(List* list, const int value)
{
	ListElement* newElement = malloc(sizeof(ListElement));
	if (newElement == NULL)
	{
		return;
	}
	list->lenght++;
	newElement->value = value;
	if (list->head == NULL)
	{
		newElement->next = list->head;
		list->head = newElement;
		return;
	}
	newElement->next = list->head;
	list->head = newElement;
	return;
}

int pop(List** list)
{
	if ((*list)->head == NULL)
	{
		exit(-1);
	}
	ListElement* delete = (*list)->head;
	(*list)->lenght--;
	int element = delete->value;
	(*list)->head = (*list)->head->next;
	free(delete);
	return element;
}

bool isEmpty(List* list)
{
	return list->head == NULL;
}

void deleteList(List** list)
{
	while (!isEmpty(*list))
	{
		pop(list);
	}
	free(*list);
	*list = NULL;
}

List* readFromFile(List* list, const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	int value = 0;
	while (fscanf(file, "%i", &value) != EOF)
	{
		push(list, value);
	}
	fclose(file);
	return list;
}

ListElement* getNth(ListElement* head, int n)
{
	int counter = 0;
	while (counter < n && head)
	{
		head = head->next;
		counter++;
	}
	return head;
}

bool checkSymmetry(List* list)
{
	ListElement* checkList = list->head;
	int index = list->lenght;
	for (int i = 0; i < (list->lenght / 2); ++i)
	{
		ListElement* node = getNth(list->head, index - 1 - i);
		if (checkList->value != node->value)
		{
			return false;
		}
		checkList = checkList->next;
	}
	return true;
}

void printList(List* list)
{
	List listCopy = *list;
	if (isEmpty(&listCopy))
	{
		printf("List is empty\n");
		return;
	}
	while (!isEmpty(&listCopy))
	{
		printf("%i ", listCopy.head->value);
		listCopy.head = listCopy.head->next;
	}
}