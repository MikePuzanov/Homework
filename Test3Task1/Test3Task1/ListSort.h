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

// �������� ���������
List* getNext(List* head);

// �������� ��������
int getValue(List* head);

// �������� ���-�� ��������
int getCount(List* head);

// �������� ������
void printList(List* head);