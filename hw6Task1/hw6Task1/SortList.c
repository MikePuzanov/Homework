#include "SortList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List {
    int value;
    struct List* next;
} List;

void push(List** head, int element)
{
    List* newNode = (List*)malloc(sizeof(List));
    newNode->value = element;
    newNode->next = (*head);
    (*head) = newNode;
}

int pop(List** head)
{
    List* delete = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    delete = (*head);
    int element = delete->value;
    (*head) = (*head)->next;
    free(delete);
    return element;
}

List* getNth(List* head, int position)
{
    int counter = 0;
    while (counter < position && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

int deleteNth(List** head, int position)
{
    if (position == 0)
    {
        return pop(head);
    }
    else
    {
        List* prev = getNth(*head, position - 1);
        if (prev == NULL)
        {
            exit(-1);
        }
        List* element = prev->next;
        int value = element->value;
        prev->next = element->next;
        free(element);
        return value;
    }
}

bool isEmpty(List* head)
{
    return head == NULL;
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        pop(head);
    }
    free(*head);
    *head = NULL;
}

int findN(List* head, int value)
{
    int index = 0;
    while (head->next != NULL && head->value < value)
    {
        index++;
        head = head->next;
    }
    return index - 1;
}

void pushtoList(List** head,int element)
{
    List* node = *head;
    List* newNode = malloc(sizeof(List));
    if (newNode == NULL)
    {
        return;
    }
    if (node == NULL)
    {
        push(head, element);
        return;
    }
    int index = 0;
    while (node->next != NULL && node->next->value < element)
    {
        node = node->next;
        index++;
    }
    newNode->value = element;
    if (node == *head && element < node->value)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    newNode->next = node->next;
    node->next = newNode;
}

bool checkValue(List* head, int value)
{
    List* prev = getNth(head, findN(head, value) + 1);
    return value == prev->value;
}

List* deleteNode(List* head, int element)
{
    while (checkValue(head, element))
    {
        deleteNth(&head, findN(head, element) + 1);
    }
    return head;
}

void printList(List* head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}