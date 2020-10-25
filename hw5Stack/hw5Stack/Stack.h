#pragma once

#include <stdbool.h>

// 
struct StackElement;

// ������� ���������� �������� � ����
struct StackElement* push(struct StackElement* head, int element);

// ������� �������� �������� �����
int pop(struct StackElement** head);

// �������� ����������� �������� �����
bool isEmpty(struct StackElement* head);

// ������� ������� �����
void deleteStack(struct StackElement** head);