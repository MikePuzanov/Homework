#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List
{
    int value;
    struct List* next;
} List;

void push(List** head, int element)
{
    List* newNode = (List*)malloc(sizeof(List));
    newNode->value = element;
    newNode->next = (*head);
    (*head) = newNode;
}

int pop(List** head)
{
    List* delete = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    delete = (*head);
    int element = delete->value;
    (*head) = (*head)->next;
    free(delete);
    return element;
}

List* getNth(List* head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

int getValue(List* head)
{
    return head->value;
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

bool isEmpty(List* head)
{
    return head == NULL;
}