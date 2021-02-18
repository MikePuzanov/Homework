#pragma once
#include <stdbool.h>

// струкутра списка
typedef struct List List;

// ñîçäàíèå ñïèñêà
List* createList();

// функция добавление в список
void append(List* head, const int element, const int roadLength);

// функция удаления из списка
bool deleteNode(List* list, int index);

// получить растояние
int getRoadLength(List* list, int index);

// получить город
int getCity(List* head);

// удаление списка
void deleteList(List** head);

// проверка на пустоту списка
bool isEmpty(List* head);

// функция для получение последнего элемента в списке
List* getLast(List* head);