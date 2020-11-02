#pragma once
#include <stdbool.h>

// Струкутра списка
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Функция добавление в список
void push(Node** head, int element);

// функция удаления из списка
int pop(Node** head);

// Функция для получение n-ого элемента в списке
Node* getNth(Node* head, int n);

// Функция для получение последнего элемента в списке
Node* getLast(Node* head);

// Функция добавление элемента в конец списка
void pushBack(Node* head, int value);

// функция для получения предпоследнего элемента в списке
Node* getLastButOne(Node* head);

// Функция для удаления последнего элемента в списке
void popBack(Node** head);

// Функция для добавление элемента в список за n-ый элемент 
void insert(Node* head, int n, int val);

// Функция удаление n-ого элемента
int deleteNth(Node** head, int n);

// Удаление списка
void deleteList(Node** head);

// Проверка на пустоту списка
bool isEmpty();