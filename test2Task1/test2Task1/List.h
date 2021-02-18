#pragma once
#include <stdbool.h>

// Струкутра списка
typedef struct List List;

// создание списка
void makeList(List** head, char fileName[], int* size);

// Функция добавление в список
void push(List** head, int element);

// функция удаления из списка
int pop(List** head);

// Функция удаление n-ого элемента
int deleteNth(List** head, int n);

// переворот списка
List* turnList(List** head, List** newHead);

// Удаление списка
void deleteList(List** head);

// Проверка на пустоту списка
bool isEmpty(List* head);

// печать списка 
void printList(List* head, int size);