#include "FunctionForList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct List {
    char phone[20];
    char name[20];
    struct List* next;
} List;

void pushList(List** head, const char* name, const char* phone)
{
    List* newNode = (List*)malloc(sizeof(List));
    if (newNode == NULL)
    {
        return NULL;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
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

void nextToNext(List** head, List* node)
{
    (*head)->next = node;
}

char getPhone(List* head)
{
    return head != NULL ? head->phone : NULL;
}

char getName(List* head)
{
    return head != NULL ? head->name : NULL;
}

List* getNext(List* head)
{
    return head != NULL ? head->next : NULL;
}

void printPhonebook(List* head)
{
    while (head != NULL)
    {
        printf("\n%s - %s", head->name, head->phone);
        head = head->next;
    }
    printf("\n");
}

void scanfFromFile(char file[], List** head)
{
    FILE* phoneBook = fopen(file, "r");
    char name[20];
    char phone[20] = 0;
    while ((fscanf(phoneBook, "%s - %s", &name, &phone)) != EOF)
    {
        pushList(head, name, phone);
    }
    fclose(phoneBook);
}

bool isEmpty(List* head)
{
    return head == NULL;
}

void deleteList(List** head)
{
    while ((*head) != NULL)
    {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}