#pragma once
#include <stdbool.h>

// ������� ���������� ����� � �������� �������
void binaryTransfer(int number, bool array[], int size);

// �������� � �������� �������������
void addition(bool firstElement[], bool secondElement[], bool arraySum[], int size);

// ������� �� ��������� ������������� � ����������
int decimalTransfer(bool arraySum[], int size);

//
bool test();