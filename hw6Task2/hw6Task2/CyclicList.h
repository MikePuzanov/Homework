#pragma once

#include <stdbool.h>

// струкутра списка
typedef struct List List;

// для создание циклического списка
List* init(int value);

// вернуть следующий узел
List* getNext(List* head);

// вернуть значение в узле
int getValue(List* head);

// функция для добавление элемента в список за n-ый элемент 
void insert(List* head, int index, int value);

// функция удаление узла из циклического списка
void popFor(List** head);

// проверка на пустоту
bool isEmpty(List* head);

// удаление списка
void deleteList(List** head);