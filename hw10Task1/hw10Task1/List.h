#pragma once
#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ������� ���������� � ������
void push(List** head, int element, int roadLength);

// ������� �������� �� ������
void removeFromHead(List** head);

// ������� � ���������� �������� � ������
List* getNextNode(List* head);

// �������� ���������
int getRoadLength(List* head);

// �������� �����
int getCity(List* head);

// �������� ������
void deleteList(List** head);

// �������� �� ������� ������
bool isEmpty(List* head);

// ������� ��� ��������� ���������� �������� � ������
List* getLast(List* head);