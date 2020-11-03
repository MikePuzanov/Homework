#include "FunctionForList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void pushList(List** head, char name[20], long element)
{
    List* newNode = (List*)malloc(sizeof(List));
    strcpy(newNode->name, name);
    newNode->value = element;
    newNode->next = (*head);
    (*head) = newNode;
}

void printPhonebook(List* head)
{
    while (head != NULL)
    {
        printf("\n%s - %i", head->name, head->value);
        head = head->next;
    }
    printf("\n");
}

void scanfFromFile(char file[], List** head)
{
    FILE* phoneBook = fopen(file, "r");
    char hyphen = "-";
    char name[20];
    long phone = 0;
    while ((fscanf(phoneBook, "%s - %i", &name, &phone)) != EOF)
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