#include "Stack.h"
#include "testStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackElement* push(struct StackElement* head, int element)
{
    struct StackElement* newElement = malloc(sizeof(struct StackElement));
    if (newElement == NULL)
    {
        return NULL;
    }
    newElement->value = element;
    newElement->next = head;
    head = newElement;
    return head;
}

int pop(struct StackElement** head)
{
    if (*head == NULL)
    {
        return 0;
    }
    int element = (*head)->value;
    struct StackElement* oldElement = *head;
    *head = (*head)->next;
    free(oldElement);
    return element;
}

bool isEmpty(struct StackElement* head)
{
    return head == NULL;
}

void deleteStack(struct StackElement** head)
{
    while (*head != NULL)
    {
        pop(head);
    }
}