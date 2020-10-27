#pragma once

// Возвращает опературу его приоритет
int priorityOperator(char symbol);

// Возвращает опературу его id
int idOperator(char symbol);

// Возвращает оператор по id
char fromIdToOpertor(int idSymbol);

// Функция выполняющая перевод в потсфиксную форму
void translateToPolishReverse(struct StackElement* head, char line[], char expression[], int* index);