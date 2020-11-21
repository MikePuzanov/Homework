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

List* getNth(List* head, int position)
{
    int counter = 0;
    while (counter < position && head)
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


int popBack(List** head)
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
        return NULL;
    }
    int number = lastButOne->next->value;
    free(lastButOne->next);
    lastButOne->next = NULL;
    return number;
}

void insert(List* head, int position, int value)
{
    int i = 0;
    List* newNode = NULL;
    head = getNth(head, position);
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

int deleteNth(List** head, int position)
{
    if (position == 0)
    {
        return pop(head);
    }
    else
    {
        List* prev = getNth(*head, position - 1);
        List* element = prev->next;
        int value = element->value;
        prev->next = element->next;
        free(element);
        return value;
    }
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        pop(head);
    }
    free(*head);
}

bool isEmpty(List* head)
{
    return head == NULL;
}