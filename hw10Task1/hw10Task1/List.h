#pragma once
#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ������� ���������� � ������
void push(List** head, int element, int road);

// ������� �������� �� ������
void pop(List** head);

// ������� � ���������� �������� � ������
List* getNextNode(List* head);

// �������� ���������
int getRoad(List* head);

// �������� �����
int getCity(List* head);

// �������� ������
void deleteList(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);