#pragma once

#include <stdbool.h>

// ���������
typedef struct List List; 

// ������� ���������� � ������(� ������)
void push(List** head, int element);

// �������� ����(head)
int pop(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);

// �������� ������
void deleteList(List** head);

// ���������� � ������ �� ��������
void pushtoList(List** head, int element);

// ��������� ���� �� � ����-�� ���� � ������ ����� ��������
bool checkValue(List* head, int value);

// �������� ���� �� value
List* deleteNode(List* head, int element);

// �������� ������
void printList(List* head);