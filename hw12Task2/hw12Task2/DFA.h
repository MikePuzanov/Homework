#pragma once

#include <stdbool.h>

// ���������� ������� ���������
int** readStateTable(const char* fileName);

// ������ ������� ���������
void deleteTable(int** statesTable);

// ����������������� �������� �������
char* DFA(const char* string, int** statesTable, bool* isInComment);