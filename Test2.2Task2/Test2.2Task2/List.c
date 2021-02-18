#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct List {
    char line[100];
    struct List* next;
    int value;
} List;

void push(List** head, const char line[], int value)
{
    List* newNode = (List*)malloc(sizeof(List));
    strcpy(newNode->line, line);
    newNode->value = value;
    newNode->next = (*head);
    (*head) = newNode;
}

void pop(List** head)
{
    List* delete = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    delete = (*head);
    (*head) = (*head)->next;
    free(delete);
}

int getValue(List* head)
{
    return head->value;
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        pop(head);
    }
    free(*head);
}

bool isEmpty(List* head)
{
    return head == NULL;
}

void readFromFile(const char fileName[], List** head)
{
    FILE* file = fopen(fileName, "r");
    char line[100];
    while (!feof(file))
    {
        fgets(line, 100, file);
        push(head, line, 1);
    }
    fclose(file);
}

List* findSame(List* checkList, List* head)
{
    while (head != checkList)
    {
        if (strcmp(head->line, checkList->line) == 0)
        {
            return NULL;
        }
        head = head->next;
    }
    List* node = head;
    int value = 0;
    while (head)
    {
        if (strcmp(head->line, checkList->line) == 0)
        {
            value++;
        }
        head = head->next;
    }
    node->value = value;
    strcpy(node->line, checkList->line);
}

List* getNewList(List* mainHead)
{
    List* checkList = mainHead;
    List* newHead = NULL;
    while (checkList)
    {
        List* newNode;
        newNode = findSame(checkList, mainHead);
        if (newNode == NULL)
        {
            checkList = checkList->next;
            continue;
        }
        push(&newHead, newNode->line, newNode->value);
        checkList = checkList->next;
    }
    return newHead;
}

void printList(List* head)
{
    while (head)
    {
        printf("%s", head->line, head->value);
        head = head->next;
    }
}