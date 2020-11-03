#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void pushBack(List* head, int value)
{
    List* last = getLast(head);
    List* newNode = (List*)malloc(sizeof(List));
    newNode->value = value;
    newNode->next = NULL;
    last->next = newNode;
}

List* getLastButOne(List* head)
{
    if (head == NULL)
    {
        exit(-2);
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    while (head->next->next)
    {
        head = head->next;
    }
    return head;
}


void popBack(List** head)
{
    List* lastButOne = NULL;
    if (!head) 
    {
        exit(-1);
    }
    if (!(*head))
    {
        exit(-1);
    }
    lastButOne = getLastButOne(*head);
    if (lastButOne == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        free(lastButOne->next);
        lastButOne->next = NULL;
    }
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

int deleteNth(List** head, int n)
{
    if (n == 0)
    {
        return pop(head);
    }
    else
    {
        List* prev = getNth(*head, n - 1);
        List* element = prev->next;
        int val = element->value;
        prev->next = element->next;
        free(element);
        return val;
    }
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