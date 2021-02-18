#include "Sort.h"
#include "FunctionForList.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum SortType
{
    byPhone,
    byName
};

bool compareStruct(List* firstPart, List* secondPart, enum SortType key)
{
    char string1[20];
    char string2[20];
    if (key == byPhone)
    {
        getPhone(firstPart, string1);
        getPhone(secondPart, string2);
        if (strlen(string1) == strlen(string2))
        {
            return strcmp(string1, string2) < 0;
        }
        else
        {
            return strlen(string1) < strlen(string2);
        }
    }
    else
    {
        getName(firstPart, string1);
        getName(secondPart, string2);
        return strcmp(string1, string2) < 0;
    }
}

void merge(List* firstPart, List* secondPart, List** sort, enum SortType key)
{
    enum SortType sortType = key;
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
    if (compareStruct(firstPart, secondPart, sortType))
    {
        *sort = firstPart;
        firstPart = getNext(firstPart);
    }
    else
    {
        *sort = secondPart;
        secondPart = getNext(secondPart);
    }
    List* mergedHead = *sort;
    while (firstPart && secondPart)
    {
        if (compareStruct(firstPart, secondPart, sortType))
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