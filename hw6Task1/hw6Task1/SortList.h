#pragma once

#include <stdbool.h>

// структура
typedef struct List List; 

// ‘ункци€ добавление в список(в начало)
void push(List** head, int element);

// удаление узла(head)
int pop(List** head);

// ѕроверка на пустоту списка
bool isEmpty(List* head);

// ”даление списка
void deleteList(List** head);

// добавление в список по сортиров
void pushtoList(List** head, int element);

// ѕровер€ет есть ли у кого-то узла в списке такое значение
bool checkValue(List* head, int value);

// удаление узла по value
List* deleteNode(List* head, int element);

// ѕечатает список
void printList(List* head);