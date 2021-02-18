#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct PriorityQueue
{
    int value;
    int priority;
    struct PriorityQueue* next;
} PriorityQueue;

void enqueue(PriorityQueue** head, int value, int priority)
{
    PriorityQueue* newNode = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    newNode->value = value;
    newNode->priority = priority;
    newNode->next = (*head);
    (*head) = newNode;
}

int pop(PriorityQueue** head)
{
    PriorityQueue* delete = (*head);
    int element = delete->value;
    (*head) = (*head)->next;
    free(delete);
    return element;
}

int dequeue(PriorityQueue** head, int priority)
{
    if (*head == NULL)
    {
        return -1;
    }
    if ((*head)->priority == priority)
    {
        return pop(head);
    }
    PriorityQueue* node = *head;
    while ((node)->next->priority != priority)
    {
        node = (node)->next;
    }
    PriorityQueue* prev = node;
    PriorityQueue* delete = prev->next;
    int value = delete->value;
    prev->next = delete->next;
    free(delete);
    return value;
}

bool isEmpty(PriorityQueue* head)
{
    return head == NULL;
}

void deletePriorityQueue(PriorityQueue** head)
{
    while ((*head)->next)
    {
        pop(head);
    }
    free(*head);
    *head = NULL;
}


int findMaxPriority(PriorityQueue* head)
{
    int priority = INT_MIN;
    while (head != NULL)
    {
        if (head->priority > priority)
        {
            priority = head->priority;
        }
        head = head->next;
    }
    return priority;
}