#pragma once

#include <stdbool.h>

// ��������� ������� ������������
int calculator(char element, int first, int second);

// ��������� �����(char) � �����(int)
int translateToInt(char element[], int low, int high);

// �������� �������� ������
int reversePolish(char element[], struct StackElement* head, bool* isCorrect);