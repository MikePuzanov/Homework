#pragma once

#include <stdbool.h>

// ���������
typedef struct List List;

// ���������� � ������
void pushList(List** head, const char* name, const char* phone);

//
void pop(List** head);

//
void nextToNext(List** head, List* node);

//
char getPhone(List* head);

//
char getName(List* head);

//
List* getNext(List* head);

// ����������� ����������� ������
void printPhonebook(List* head);

// �������� � �����
void scanfFromFile(char file[], List** head);

// �������� �� �������
bool isEmpty(List* head);

// �������� ������
void deleteList(List** head);