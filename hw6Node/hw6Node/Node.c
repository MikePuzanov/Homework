#include "Node.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(Node** head, int element)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = element;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node** head)
{
    Node* delete = NULL;
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

Node* getNth(Node* head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

Node* getLast(Node* head)
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

void pushBack(Node* head, int value)
{
    Node* last = getLast(head);
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}

Node* getLastButOne(Node* head)
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


void popBack(Node** head)
{
    Node* lastbn = NULL;
    if (!head) 
    {
        exit(-1);
    }
    if (!(*head))
    {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    if (lastbn == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}

void insert(Node* head, int n, int val)
{
    int i = 0;
    Node* tmp = NULL;
    while (i < n && head->next)
    {
        head = head->next;
        i++;
    }
    tmp = (Node*)malloc(sizeof(Node));
    tmp->value = val;
    if (head->next)
    {
        tmp->next = head->next;
    }
    else
    {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(Node** head, int n)
{
    if (n == 0)
    {
        return pop(head);
    }
    else
    {
        Node* prev = getNth(*head, n - 1);
        Node* elm = prev->next;
        int val = elm->value;
        prev->next = elm->next;
        free(elm);
        return val;
    }
}

void deleteList(Node** head)
{
    while ((*head)->next)
    {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

bool isEmpty(Node* head)
{
    return head == NULL;
}