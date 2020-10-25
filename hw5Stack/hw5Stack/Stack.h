#pragma once

#include <stdbool.h>

// 
struct Stack;

//
struct Stack* createStack(void);

// ������� ���������� �������� � ����
void push(struct Stack* stack, int value);

// ������� �������� �������� �����
int pop(struct Stack* stack);

// �������� ����������� �������� �����
bool isEmpty(struct Stack* stack);

// ������� ������� �����
void deleteStack(struct Stack** stack);
