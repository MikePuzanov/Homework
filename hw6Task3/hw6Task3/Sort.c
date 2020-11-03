#include "Sort.h"
#include "FunctionForList.h"

#include <stdio.h>
#include <stdlib.h>

void merge(List* firstPart, List* secondPart, List** sort)
{
    List tmp;
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
    tmp.next = *sort;
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
        while (firstPart)
        {
            (*sort)->next = firstPart;
            (*sort) = (*sort)->next;
            firstPart = firstPart->next;
        }
    }
    if (secondPart)
    {
        while (secondPart)
        {
            (*sort)->next = secondPart;
            (*sort) = (*sort)->next;
            secondPart = secondPart->next;
        }
    }
    *sort = tmp.next;
}

void split(List* src, List** low, List** high)
{
    List* fast = NULL;
    List* slow = NULL;

    if (src == NULL || src->next == NULL)
    {
        (*low) = src;
        (*high) = NULL;
        return;
    }

    slow = src;
    fast = src->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    (*low) = src;
    (*high) = slow->next;
    slow->next = NULL;
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

int compareString(char name1[], char name2[])
{
    int size = 0;
    if (strlen(name1) >= strlen(name2))
    {
        size = strlen(name1);
    }
    else
    {
        size = strlen(name2);
    }
    for (int i = 0; i < size; ++i)
    {
        if (("%c", name1[i]) == ("%c", name2[i]))
        {
            continue;
        }
        if (("%c", name1[i]) > ("%c", name2[i]))
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if (strlen(name1) >= strlen(name2))
    {
        return 1;
    }
    return 2;
}


void mergeName(List* firstPart, List* secondPart, List** sort)
{
    List tmp;
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
    if (compareString(firstPart->name, secondPart->name) == 2)
    {
        *sort = firstPart;
        firstPart = firstPart->next;
    }
    else
    {
        *sort = secondPart;
        secondPart = secondPart->next;
    }
    tmp.next = *sort;
    while (firstPart && secondPart)
    {
        if (compareString(firstPart->name, secondPart->name) == 2)
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
        while (firstPart)
        {
            (*sort)->next = firstPart;
            (*sort) = (*sort)->next;
            firstPart = firstPart->next;
        }
    }
    if (secondPart)
    {
        while (secondPart)
        {
            (*sort)->next = secondPart;
            (*sort) = (*sort)->next;
            secondPart = secondPart->next;
        }
    }
    *sort = tmp.next;
}

void mergeSortName(List** head)
{
    List* low = NULL;
    List* high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL))
    {
        return;
    }
    split(*head, &low, &high);
    mergeSortName(&low);
    mergeSortName(&high);
    mergeName(low, high, head);
}