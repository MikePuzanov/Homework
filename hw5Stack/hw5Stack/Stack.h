#pragma once

#include <stdbool.h>

// ���������� ���������
struct StackElement
{
<<<<<<< HEAD
	int value;
	struct StackElement* next;
=======
    int value;
    struct StackElement* next;
>>>>>>> hw5Stack
};

// ������� ���������� �������� � ����
struct StackElement* push(struct StackElement* head, int element);

// ������� �������� �������� �����
int pop(struct StackElement** head);

// �������� ����������� �������� �����
bool isEmpty(struct StackElement* head);

// ������� ������� �����
void deleteStack(struct StackElement** head);