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

// получить следующий
List* getNext(List* head);

// получить значение
int getValue(List* head);

// получить кол-во повторов
int getCount(List* head);

// ѕечатает список
void printList(List* head);