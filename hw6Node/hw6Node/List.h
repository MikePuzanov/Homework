#pragma once
#include <stdbool.h>

// Струкутра списка
typedef struct List {
    int value;
    struct List* next;
} List;

// Функция добавление в список
void push(List** head, int element);

// функция удаления из списка
int pop(List** head);

// Функция для получение n-ого элемента в списке
List* getNth(List* head, int n);

// Функция для получение последнего элемента в списке
List* getLast(List* head);

// Функция добавление элемента в конец списка
void pushBack(List* head, int value);

// функция для получения предпоследнего элемента в списке
List* getLastButOne(List* head);

// Функция для удаления последнего элемента в списке
void popBack(List** head);

// Функция для добавление элемента в список за n-ый элемент 
void insert(List* head, int n, int val);

// Функция удаление n-ого элемента
int deleteNth(List** head, int n);

// Удаление списка
void deleteList(List** head);

// Проверка на пустоту списка
bool isEmpty(List* head);