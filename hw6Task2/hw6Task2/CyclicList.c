#include "CyclicList.h"
#include "../../hw6Node/hw6Node/List.h"

#include <stdio.h>
#include <stdlib.h>

void init(List* head)
{
    head->next = head;
}

void popFor(List** head)
{
    if (head == NULL)
    {
        exit(-1);
    }
    List* prev = *head;
    List* delete = prev->next;
    int val = delete->value;
    prev->next = delete->next;
    free(delete);
}