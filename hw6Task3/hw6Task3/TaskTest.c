#include "FunctionForList.h"
#include "Sort.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool testTask()
{
    List* head = NULL;
    scanfFromFile("PhonebookTest.txt", &head);
    bool key = true;
    mergeSortPhone(&head);
    if (head->value != 1 || head->next->value != 2 || head->next->next->value != 3)
    {
        return false;
    }
    mergeSortName(&head);
    if (compareString(head->name, head->next->name) != 2 || compareString(head->next->name, head->next->next->name) != 2)
    {
        return false;
    }
    return true;
}