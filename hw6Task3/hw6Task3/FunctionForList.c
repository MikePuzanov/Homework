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
    if (head == NULL)
    {
        exit(-1);
    }
    List* delete = (*head);
    (*head) = (*head)->next;
    free(delete);
}

List* assignNextNull(List* head)
{
    head->next = NULL;
    return head;
}

List* assignToNext(List* head, List* node)
{
    head->next = node;
    return head;
}

void getPhone(List* head, char phone[])
{
    if (head)
    {
        strcpy(phone, head->phone);
    }
}

void getName(List* head, char name[])
{
    if (head)
    {
        strcpy(name, head->name);
    }
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
    char phone[20];
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
    }
}