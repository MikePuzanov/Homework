#pragma once
#include <stdbool.h>

// Струкутра списка
typedef struct List List;

// Функция добавление в список
void push(List** head, int element, int road);

// функция удаления из списка
void pop(List** head);

// перейти к следующему элементу в списке
List* getNextNode(List* head);

// получить растояние
int getRoad(List* head);

// получить город
int getCity(List* head);

// Удаление списка
void deleteList(List** head);

// Проверка на пустоту списка
bool isEmpty(List* head);