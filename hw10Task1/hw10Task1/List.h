#pragma once
#include <stdbool.h>

// струкутра списка
typedef struct List List;

// функция добавление в список
void push(List** head, int element, int roadLength);

// функция удаления из списка
void removeFromHead(List** head);

// перейти к следующему элементу в списке
List* getNextNode(List* head);

// получить растояние
int getRoadLength(List* head);

// получить город
int getCity(List* head);

// удаление списка
void deleteList(List** head);

// проверка на пустоту списка
bool isEmpty(List* head);

// функция для получение последнего элемента в списке
List* getLast(List* head);