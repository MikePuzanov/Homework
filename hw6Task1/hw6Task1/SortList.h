#pragma once

#include <stdbool.h>

//
typedef struct List List;

// Функция добавление в список
void push(List** head, int element);

//
int pop(List** head);

//
List* getNth(List* head, int position);

// Функция для получение последнего элемента в списке
List* getLast(List* head);

// Функция добавление элемента в конец списка
void pushBack(List* head, int value);

// функция для получения предпоследнего элемента в списке
List* getLastButOne(List* head);

// Функция для удаления последнего элемента в списке
int popBack(List** head);

// Функция удаление n-ого элемента
int deleteNth(List** head, int n);

// Удаление списка
void deleteList(List** head);

//
void insert(List* head, int position, int value);

// Проверка на пустоту списка
bool isEmpty(List* head);

// Находит номер n-ого элемента в списке
int findN(head, element);

// Проверяет есть ли у кого-то узла в списке такое значение
bool checkValue(List* head, int val);

// Печатает список
void printList(List* head);