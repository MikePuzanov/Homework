#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// �������� ������
List* createList();

// ��������� �����
int getLenght(List* list);

// ���������� ������ ����
void push(List* list, const int value);

// �������� �� �������
bool isEmpty(List* list);

// �������� ������
void deleteList(List** list);

// ������ � �����
List* readFromFile(List* head, const char* fileName);

// �������� �� ��������������
bool checkSymmetry(List* list);

// ������ ������
void printList(List* list);