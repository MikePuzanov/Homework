#pragma once

#include <stdbool.h>

// считывание таблицы состояний
int** readStateTable(const char* fileName);

// чистка таблицы состояний
void deleteTable(int** statesTable);

// детерминированный конечный автомат
char* DFA(const char* string, int** statesTable, bool* isInComment);