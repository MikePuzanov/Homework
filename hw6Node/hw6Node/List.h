#pragma once
#include <stdbool.h>

// ��������� ������
typedef struct List {
    int value;
    struct List* next;
} List;

// ������� ���������� � ������
void push(List** head, int element);

// ������� �������� �� ������
int pop(List** head);

// ������� ��� ��������� n-��� �������� � ������
List* getNth(List* head, int n);

// ������� ��� ��������� ���������� �������� � ������
List* getLast(List* head);

// ������� ���������� �������� � ����� ������
void pushBack(List* head, int value);

// ������� ��� ��������� �������������� �������� � ������
List* getLastButOne(List* head);

// ������� ��� �������� ���������� �������� � ������
void popBack(List** head);

// ������� ��� ���������� �������� � ������ �� n-�� ������� 
void insert(List* head, int n, int val);

// ������� �������� n-��� ��������
int deleteNth(List** head, int n);

// �������� ������
void deleteList(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);