#pragma once

#include <stdbool.h>

// Струкутра списка
typedef struct List List;

// Для создание циклического списка
List* init(int value);

// вернуть следующий узел
List* getNext(List* head);

// вернуть значение в узле
int getValue(List* head);

// Функция для добавление элемента в список за n-ый элемент 
void insert(List* head, int index, int value);

// Функция удаление узла из циклического списка
void popFor(List** head);

//
bool isEmpty(List* head);

//
void deleteList(List** head);