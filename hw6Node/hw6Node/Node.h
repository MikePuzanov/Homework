#pragma once
#include <stdbool.h>

// ��������� ������
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// ������� ���������� � ������
void push(Node** head, int element);

// ������� �������� �� ������
int pop(Node** head);

// ������� ��� ��������� n-��� �������� � ������
Node* getNth(Node* head, int n);

// ������� ��� ��������� ���������� �������� � ������
Node* getLast(Node* head);

// ������� ���������� �������� � ����� ������
void pushBack(Node* head, int value);

// ������� ��� ��������� �������������� �������� � ������
Node* getLastButOne(Node* head);

// ������� ��� �������� ���������� �������� � ������
void popBack(Node** head);

// ������� ��� ���������� �������� � ������ �� n-�� ������� 
void insert(Node* head, int n, int val);

// ������� �������� n-��� ��������
int deleteNth(Node** head, int n);

// �������� ������
void deleteList(Node** head);

// �������� �� ������� ������
bool isEmpty();