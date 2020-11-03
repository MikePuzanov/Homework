#pragma once

#include "FunctionForList.h"
 
//
void merge(List* firstPart, List* secondPart, List** sort);

//
void split(List* src, List** low, List** high);

//
void mergeSortPhone(List** head);

//
int compareString(char name1[], char name2[]);

//
void mergeName(List* firstPart, List* secondPart, List** sort);

//
void mergeSortName(List** head);