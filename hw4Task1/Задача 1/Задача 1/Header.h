#pragma once
#include <stdbool.h>

// ������� ���������� ����� � �������� �������
int binaryTransfer(int array[], int number);

// ����� ������� � �������� �������������
void printfarray(int array[], int size);

// �������� � �������� �������������
int addition(int arrayFirst[], int sizeFirst, int arraySecond[], int sizeSecond, int arraySum[]);

// ������� �� ��������� ������������� � ����������
int decimalTransfer(int array, int size);

// ��������������� ������� ��� �����, ������� ��������� ������������ �������� � �������� �������
bool compare(int array[], int number, int size);

// ������� �����
bool test();