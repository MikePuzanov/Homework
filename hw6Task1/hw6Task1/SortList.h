#pragma once

#include <stdbool.h>

// ��������� �������������� ������
typedef struct List List; 

// �������� ���� (head)
int removeFromHead(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);

// �������� ������
void deleteList(List** head);

// ���������� � ������ �� ����������
void pushToList(List** head, int element);

// ��������� ���� �� � ����-�� ���� � ������ ����� ��������
bool checkValue(List* head, int value);

// �������� ���� �� value
List* deleteNode(List* head, int element);

// �������� ������
void printList(List* head);