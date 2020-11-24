#pragma once
#include <stdbool.h>

// ��������� ������
typedef struct List List;

// �������� ������
void makeList(List** head, char fileName[], int* size);

// ������� ���������� � ������
void push(List** head, int element);

// ������� �������� �� ������
int pop(List** head);

// ������� �������� n-��� ��������
int deleteNth(List** head, int n);

// ��������� ������
List* turnList(List** head, List** newHead);

// �������� ������
void deleteList(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);

// ������ ������ 
void printList(List* head, int size);