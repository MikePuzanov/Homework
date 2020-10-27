#pragma once

//
int priorityOperator(char symbol);

//
int idOperator(char symbol);

//
char fromIdToOpertor(int idSymbol);

//
void translateToPolishReverse(struct StackElement* head, char line[], char expression[], int* index);