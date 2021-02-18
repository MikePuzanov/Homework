#pragma once

#include <stdbool.h>

// ��������� ������������ �������
typedef struct PriorityQueue PriorityQueue;

// ������� ����������
void enqueue(PriorityQueue** head, int value, int priority);

// ��������
int dequeue(PriorityQueue** head, int priority);

// �������� �� ������
bool isEmpty(PriorityQueue* head);

// �������� �������
void deletePriorityQueue(PriorityQueue** head);

// ���������� ������ �������� ����������
int findMaxPriority(PriorityQueue* head);