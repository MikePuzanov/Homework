#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ������� ���������� � ������
void push(List** head, const char line[], int value);

// ������� �������� �� ������
void pop(List** head);

// �������� ������� �����������
int getValue(List* head);

// �������� ������
void deleteList(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);

// ������ � ����
void readFromFile(const char fileName[], List** head);

// �������� ����� ����
List* getNewList(List* mainHead);

// ������
void printList(List* head);