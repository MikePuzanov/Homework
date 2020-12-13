#pragma once

#include "FunctionForList.h"
 
// вспомогтаельная функция для сортировки по номерам
void merge(List* firstPart, List* secondPart, List** sort);

// функция разделение списка
void split(List* src, List** low, List** high);

// сортировка по номерам
void mergeSortPhone(List** head);

// вспомогательная функция для сортировки имени
void mergeName(List* firstPart, List* secondPart, List** sort);

// сортировка для имени 
void mergeSortName(List** head);