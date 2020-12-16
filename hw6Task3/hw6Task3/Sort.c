#include "Sort.h"
#include "FunctionForList.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool compareString(const char* string1, const char* string2, int key)
{
    if (key == 1)
    {
        if (strlen(string1) == strlen(string2))
        {
            return strcmp(string1, string2) < 0 ? true : false;
        }
        else if (strlen(string1) < strlen(string2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return strcmp(string1, string2) < 0 ? true : false;
    }
}

void merge(List* firstPart, List* secondPart, List** sort, int key)
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
    char string1[20];
    char string2[20];
    if (key == 1)
    {
        getPhone(firstPart, string1);
        getPhone(secondPart, string2);
    }
    else
    {
        getName(firstPart, string1);
        getName(secondPart, string2);
    }
    if (compareString(string1, string2, key))
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
        if (key == 1)
        {
            getPhone(firstPart, string1);
            getPhone(secondPart, string2);
        }
        else
        {
            getName(firstPart, string1);
            getName(secondPart, string2);
        }
        if (compareString(string1, string2, key))
        {
            *sort = assignToNext(*sort, firstPart);
            firstPart = getNext(firstPart);
        }
        else
        {
            *sort = assignToNext(*sort, secondPart);
            secondPart = getNext(secondPart);
        }
        (*sort) = getNext(*sort);
    }
    if (firstPart)
    {
        *sort = assignToNext(*sort, firstPart);
    }
    if (secondPart)
    {
        *sort = assignToNext(*sort, secondPart);
    }
    *sort = mergedHead;
}

void split(List* head, List** low, List** high)
{
    List* fast = NULL;
    List* slow = NULL;
    List* node = getNext(head);
    if (head == NULL || node == NULL)
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
    slow = assignNextNull(slow);
}

void mergeSort(List** head, int key)
{
    List* low = NULL;
    List* high = NULL;
    List* node = getNext(*head);
    if ((*head == NULL) || (node == NULL))
    {
        return;
    }
    split(*head, &low, &high);
    mergeSort(&low, key);
    mergeSort(&high, key);
    merge(low, high, head, key);
}