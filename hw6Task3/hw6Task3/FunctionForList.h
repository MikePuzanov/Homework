#pragma once

#include <stdbool.h>

// ���������
typedef struct List {
    long value;
    char name[20];
    struct List* next;
} List;

// ���������� � ������
void pushList(List** head, char name[20], long element);

// ����������� ����������� ������
void printPhonebook(List* head);

// �������� � �����
void scanfFromFile(char file[], List** head);

// �������� �� �������
bool isEmpty(List* head);

// �������� ������
void deleteList(List** head)