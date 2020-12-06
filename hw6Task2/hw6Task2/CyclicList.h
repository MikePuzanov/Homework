#pragma once

// ��������� ������
typedef struct List List;

// ��� �������� ������������ ������
void init(List* head);

// ������� ���������� � ������
void push(List** head, int element);

// ������� ��� ���������� �������� � ������ �� n-�� ������� 
void insert(List* head, int n, int val);

// ������� �������� ���� �� ������������ ������
void popFor(List** head);