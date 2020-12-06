#include "CyclicList.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int value;
    struct List* next;
} List;

void init(List* head)
{
    head->next = head;
}

void push(List** head, int element)
{
    List* newNode = (List*)malloc(sizeof(List));
    newNode->value = element;
    newNode->next = (*head);
    (*head) = newNode;
}

void insert(List* head, int n, int val)
{
    int i = 0;
    List* newNode = NULL;
    while (i < n && head->next)
    {
        head = head->next;
        i++;
    }
    newNode = (List*)malloc(sizeof(List));
    newNode->value = val;
    if (head->next)
    {
        newNode->next = head->next;
    }
    else
    {
        newNode->next = NULL;
    }
    head->next = newNode;
}

void popFor(List** head)
{
    if (head == NULL)
    {
        exit(-1);
    }
    List* prev = *head;
    List* delete = prev->next;
    int val = delete->value;
    prev->next = delete->next;
    free(delete);
}