#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ���������� � ������
void pushList(List** head, const char* name, const char* phone);

// ��������
void pop(List** head);

// ������� ��������� ���� NULL
List* assignNextNull(List* head);

// ��������� head->next = node
List* assignToNext(List* head, List* node);

// �������� �����
void getPhone(List* head, char phone[]);

// �������� ���
void getName(List* head, char name[]);

// �������� ��������� ����
List* getNext(List* head);

// ����������� ����������� ������
void printPhonebook(List* head);

// ���������� � �����
void scanfFromFile(char file[], List** head);

// �������� �� �������
bool isEmpty(List* head);

// �������� ������
void deleteList(List** head);