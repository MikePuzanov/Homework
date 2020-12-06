#pragma once
#include <stdbool.h>

// Струкутра списка
typedef struct List List;

// Функция добавление в список
void push(List** head, int element);

// функция удаления из списка
int pop(List** head);

// получить н-ый узел в списке
List* getNth(List* head, int n);

// получить значение узла
int getValue(List* head);

// Удаление списка
void deleteList(List** head);

// Проверка на пустоту списка
bool isEmpty(List* head);