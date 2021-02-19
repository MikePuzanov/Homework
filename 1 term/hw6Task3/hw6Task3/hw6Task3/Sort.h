#pragma once

#include "FunctionForList.h"

// виды сортировки
enum SortType;

// сортировка слиянием. key == 0 сортировка по номерам, key == 1 сортировка по имени
void mergeSort(List** head, enum SortType key);