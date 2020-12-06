#pragma once

// Струкутра списка
typedef struct List List;

// Для создание циклического списка
void init(List* head);

// Функция добавление в список
void push(List** head, int element);

// Функция для добавление элемента в список за n-ый элемент 
void insert(List* head, int n, int val);

// Функция удаление узла из циклического списка
void popFor(List** head);