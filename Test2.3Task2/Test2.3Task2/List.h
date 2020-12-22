#pragma once

#include <stdbool.h>

// структура списка
typedef struct List List;

// создание списка
List* createList();

// получение длины
int getLenght(List* list);

// добавление нового узла
void push(List* list, const int value);

// проверка на пустоту
bool isEmpty(List* list);

// удаление списка
void deleteList(List** list);

// чтение с файла
List* readFromFile(List* head, const char* fileName);

// проверка на симметричность
bool checkSymmetry(List* list);

// Prints all list
void printList(List* list);