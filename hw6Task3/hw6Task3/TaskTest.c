#include "FunctionForList.h"
#include "Sort.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool testTask()
{
    List* head = NULL;
    scanfFromFile("PhonebookTest.txt", &head);
    bool key = true;
    mergeSort(&head, 1);
    List* node1 = getNext(head);
    List* node2 = getNext(node1);
    char string1[20];
    char string2[20];
    char string3[20];
    getPhone(head, string1);
    getPhone(node1, string2);
    getPhone(node2, string3);
    if (strcmp(string1, "1") != 0 || strcmp(string2, "2") != 0 || strcmp(string3, "3") != 0)
    {
       return false;
    }
    mergeSort(&head, 2);
    node1 = getNext(head);
    node2 = getNext(node1);
    getName(head, string1);
    getName(node1, string2);
    getName(node2, string3);
    if (strcmp(string1, "a") != 0 || strcmp(string2, "b") != 0 || strcmp(string3, "c") != 0)
    {
        return false;
    }
    return true;
}