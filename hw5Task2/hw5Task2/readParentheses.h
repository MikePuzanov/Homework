#pragma once

#include <stdbool.h>

// ����������� id ������
int idParentheses(char symbol);

// ��������� ��������� ����������� ������
bool checkParentheses(struct StackElement* head, char line[]);