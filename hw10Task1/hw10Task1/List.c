#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List
{
    int city;
    int road;
    struct List* next;
} List;

void push(List** head, int element, int road)
{
    List* newNode = (List*)malloc(sizeof(List));
    newNode->city = element;
    newNode->road = road;
    newNode->next = (*head);
    (*head) = newNode;
}

void pop(List** head)
{
    List* delete = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    delete = (*head);
    int element = delete->city;
    (*head) = (*head)->next;
    free(delete);
}

List* getNextNode(List* head)
{
    return head ? head->next : head;
}

int getRoad(List* head)
{
    return head->road;
}

int getCity(List* head)
{
    return head->city;
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        pop(head);
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