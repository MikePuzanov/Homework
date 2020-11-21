#pragma once

#include <stdbool.h>

//
typedef struct List List;

// ������� ���������� � ������
void push(List** head, int element);

//
int pop(List** head);

//
List* getNth(List* head, int position);

// ������� ��� ��������� ���������� �������� � ������
List* getLast(List* head);

// ������� ���������� �������� � ����� ������
void pushBack(List* head, int value);

// ������� ��� ��������� �������������� �������� � ������
List* getLastButOne(List* head);

// ������� ��� �������� ���������� �������� � ������
int popBack(List** head);

// ������� �������� n-��� ��������
int deleteNth(List** head, int n);

// �������� ������
void deleteList(List** head);

//
void insert(List* head, int position, int value);

// �������� �� ������� ������
bool isEmpty(List* head);

// ������� ����� n-��� �������� � ������
int findN(head, element);

// ��������� ���� �� � ����-�� ���� � ������ ����� ��������
bool checkValue(List* head, int val);

// �������� ������
void printList(List* head);