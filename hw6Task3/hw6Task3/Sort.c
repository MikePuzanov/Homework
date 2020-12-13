#include "Sort.h"
#include "FunctionForList.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(List* firstPart, List* secondPart, List** sort)
{
    List* mergedHead;
    *sort = NULL;
    if (firstPart == NULL)
    {
        *sort = secondPart;
        return;
    }
    if (secondPart == NULL)
    {
        *sort = firstPart;
        return;
    }
    if (firstPart->value < secondPart->value)
    {
        *sort = firstPart;
        firstPart = firstPart->next;
    }
    else
    {
        *sort = secondPart;
        secondPart = secondPart->next;
    }
    mergedHead = *sort;
    while (firstPart && secondPart)
    {
        if (firstPart->value < secondPart->value)
        {
            (*sort)->next = firstPart;
            firstPart = firstPart->next;
        }
        else
        {
            (*sort)->next = secondPart;
            secondPart = secondPart->next;
        }
        (*sort) = (*sort)->next;
    }
    if (firstPart)
    {
        nextToNext(*sort, firstPart);
    }
    if (secondPart)
    {
        nextToNext(*sort, secondPart);
    }
    *sort = mergedHead;
}

void split(List* head, List** low, List** high)
{
    List* fast = NULL;
    List* slow = NULL;
    if (head == NULL || getNext(head) == NULL)
    {
        (*low) = head;
        (*high) = NULL;
        return;
    }
    slow = head;
    fast = getNext(head);
    while (fast != NULL)
    {
        fast = getNext(fast);
        if (fast != NULL)
        {
            fast = getNext(fast);
            slow = getNext(slow);
        }
    }
    (*low) = head;
    (*high) = getNext(slow);
    slow = getNext(slow);
    slow = NULL;
}

void mergeSortPhone(List** head)
{
    List* low = NULL;
    List* high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL))
    {
        return;
    }
    split(*head, &low, &high);
    mergeSortPhone(&low);
    mergeSortPhone(&high);
    merge(low, high, head);
}

void mergeName(List* firstPart, List* secondPart, List** sort)
{
    List* mergedHead;
    *sort = NULL;
    if (firstPart == NULL)
    {
        *sort = secondPart;
        return;
    }
    if (secondPart == NULL)
    {
        *sort = firstPart;
        return;
    }
    if (strcmp(getName(firstPart), getName(secondPart)) <= 0)
    {
        *sort = firstPart;
        firstPart = getNext(firstPart);
    }
    else
    {
        *sort = secondPart;
        secondPart = getNext(secondPart);
    }
    mergedHead = *sort;
    while (firstPart && secondPart)
    {
        if (strcmp(getName(firstPart), getName(secondPart)) <= 0)
        {
            nextToNext(*sort, firstPart);
            firstPart = getNext(firstPart);
        }
        else
        {
            nextToNext(*sort, secondPart);
            secondPart = getNext(secondPart);
        }
        (*sort) = getNext(*sort);
    }
    if (firstPart)
    {
        nextToNext(*sort, firstPart);
    }
    if (secondPart)
    {
        nextToNext(*sort, secondPart);
    }
    *sort = mergedHead;
}

void mergeSortName(List** head)
{
    List* low = NULL;
    List* high = NULL;
    if ((*head == NULL) || (getNext(*head) == NULL))
    {
        return;
    }
    split(*head, &low, &high);
    mergeSortName(&low);
    mergeSortName(&high);
    mergeName(low, high, head);
}