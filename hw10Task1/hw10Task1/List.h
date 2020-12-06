#pragma once
#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ������� ���������� � ������
void push(List** head, int element);

// ������� �������� �� ������
int pop(List** head);

// �������� �-�� ���� � ������
List* getNth(List* head, int n);

// �������� �������� ����
int getValue(List* head);

// �������� ������
void deleteList(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);