#pragma once

// ���������� ��������� ��� ���������
int priorityOperator(char symbol);

// ���������� ��������� ��� id
int idOperator(char symbol);

// ���������� �������� �� id
char fromIdToOpertor(int idSymbol);

// ������� ����������� ������� � ����������� �����
void translateToPolishReverse(struct StackElement* head, char line[], char expression[], int* index);