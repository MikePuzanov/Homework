#pragma once
#include "../../hw6Node/hw6Node/List.h"

#include <stdbool.h>

// Находит номер n-ого элемента в списке
int findN(head, element);

// Проверяет есть ли у кого-то узла в списке такое значение
bool checkValue(List* head, int val);

// Печатает список
void printList(List* head);