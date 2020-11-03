#include "UsefullFunctionForList.h"
#include "../../hw6Node/hw6Node/List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findN(List* head, int val)
{
    int index = 0;
    while (head->next != NULL && head->value < val)
    {
        index++;
        head = head->next;
    }
    return index - 1;
}

bool checkValue(List* head, int val)
{
    List* prev = getNth(head, findN(head, val) + 1);
    if (val == prev->value)
    {
        return true;
    }
    return false;
}