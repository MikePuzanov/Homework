#pragma once

#include "FunctionForList.h"

// ���� ����������
enum SortType;

// ���������� ��������. key == 0 ���������� �� �������, key == 1 ���������� �� �����
void mergeSort(List** head, enum SortType key);