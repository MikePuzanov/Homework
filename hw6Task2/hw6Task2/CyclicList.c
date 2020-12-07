#include "CyclicList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List {
    int value;
    struct List* next;
} List;

List* init(int value)
{
    List* head = malloc(sizeof(List));
    if (head == NULL) {
        return NULL;
    }
    head->value = value;
    head->next = head;
    return head;
}

List* getNext(List* head)
{
    return head->next;
}

int getValue(List* head)
{
    return head->value;
}

void insert(List* head, int index, int value)
{
    int i = 0;
    List* newNode = NULL;
    while (i < index && head->next)
    {
        head = head->next;
        i++;
    }
    newNode = (List*)malloc(sizeof(List));
    newNode->value = value;
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
    if (prev == delete)
    {
        free(delete);
        *head = NULL;
        return;
    }
    free(delete);
}

bool isEmpty(List* head)
{
    return head == NULL;
}

void deleteList(List** head)
{
    while (!isEmpty(*head))
    {
        popFor(head);
    }
    free(*head);
    *head = NULL;
}