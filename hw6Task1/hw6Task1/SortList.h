#pragma once

#include <stdbool.h>

// структура сортированного списка
typedef struct List List; 

// удаление узла (head)
int removeFromHead(List** head);

// проверка на пустоту списка
bool isEmpty(List* head);

// удаление списка
void deleteList(List** head);

// добавление в список по сортировке
void pushToList(List** head, int element);

// проверяет есть ли у кого-то узла в списке такое значение
bool checkValue(List* head, int value);

// удаление узла по value
List* deleteNode(List* head, int element);

// печатает список
void printList(List* head);