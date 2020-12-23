#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ��� �������� ������������ ������
List* init(int value);

// ������� ��������� ����
List* getNext(List* head);

// ������� �������� � ����
int getValue(List* head);

// ������� ��� ���������� �������� � ������ �� n-�� ������� 
void insert(List* head, int index, int value);

// ������� �������� ���� �� ������������ ������
void popFor(List** head);

// �������� �� �������
bool isEmpty(List* head);

// �������� ������
void deleteList(List** head);