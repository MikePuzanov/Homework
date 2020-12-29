#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// �������� �����
List* createList();

// �������� �������
int getValue(List* list, int index);

// �������� ����� ������
int getLength(List* list);

// �������� � ������
void append(List* list, const int value);

// ������� ����
bool deleteNode(struct List* list, int index);

// ��������� ������
List* reversalList(List* list);

// ������� ������
void deleteList(List** list);

//
void printList(List* list);