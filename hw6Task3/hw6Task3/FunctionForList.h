#pragma once

//
typedef struct List {
    int value;
    char name[20];
    struct List* next;
} List;

//
void pushList(List** head, char name[20], int element);

//
void printPhonebook(List* head);

//
void scanfFromFile(char file[], List** head);
