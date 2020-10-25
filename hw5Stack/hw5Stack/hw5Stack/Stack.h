#pragma once

#include <stdbool.h>

struct StackElement
{
    double value;
    struct StackElement* next;
};

// ������� ���������� �������� � ����
struct StackElement* push(struct StackElement* head, double element);

// ������� �������� �������� �����
double pop(struct StackElement** head);

// �������� ����������� �������� �����
bool isEmpty(struct StackElement* head);

// ������� ������� �����
void deleteStack(struct StackElement** head);