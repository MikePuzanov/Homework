#pragma once

#include <stdbool.h>

// структура списка
typedef struct List List;

// создание листа
List* createList();

// получить частоту
int getValue(List* list, int index);

// получить длину списка
int getLength(List* list);

// добавить в список
void append(List* list, const int value);

// удалить узел
bool deleteNode(struct List* list, int index);

// развоврот списка
List* reversalList(List* list);

// удалить список
void deleteList(List** list);

//
void printList(List* list);