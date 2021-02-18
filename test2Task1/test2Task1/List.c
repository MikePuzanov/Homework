#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List {
    int value;
    struct List* next;
} List;

void makeList(List** head, char fileName[], int* size)
{
    FILE* file = fopen(fileName, "r");
    while (!feof(file))
    {
        int number = 0;
        (*size)++;
        fscanf(file, "%i", &number);
        push(head, number);
    }
    fclose(file);
}

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

List* getNth(List* head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

List* getLast(List* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

int deleteNth(List** head, int n)
{
    if (isEmpty(head))
    {
        return NULL;
    }
    if (n == 0)
    {
        return pop(head);
    }
    else
    {
        List* prev = getNth(*head, n - 1);
        List* element = prev->next;
        int val = element->value;
        prev->next = element->next;
        free(element);
        return val;
    }
}

List* turnList(List** head, List** newHead)
{
    while (*head != NULL)
    {
        push(newHead, pop(head));
    }
    return newHead;
}

void deleteList(List** head)
{
    while ((*head)->next)
    {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

bool isEmpty(List* head)
{
    return head == NULL;
}

void printList(List* head, int size)
{
    while (size > 0)
    {
        size--;
        List* node = getNth(head, size);
        printf("%i ", node->value);
    }
}