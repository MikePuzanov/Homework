#pragma once

#include <stdbool.h>

// Струкутра списка
typedef struct List List;

// Функция добавление в список
void push(List** head, const char line[], int value);

// функция удаления из списка
void pop(List** head);

// получить сколько повторяется
int getValue(List* head);

// Удаление списка
void deleteList(List** head);

// Проверка на пустоту списка
bool isEmpty(List* head);

// читает с файа
void readFromFile(const char fileName[], List** head);

// получает новый лист
List* getNewList(List* mainHead);

// печать
void printList(List* head);