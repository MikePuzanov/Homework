#pragma once
#include "../../hw6Node/hw6Node/List.h"

#include <stdbool.h>

// ������� ����� n-��� �������� � ������
int findN(head, element);

// ��������� ���� �� � ����-�� ���� � ������ ����� ��������
bool checkValue(List* head, int val);

// �������� ������
void printList(List* head);