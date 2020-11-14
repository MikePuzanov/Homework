#pragma once

#include <stdbool.h>

// Выполняет функцию калькулятора
int calculator(char element, int first, int second);

// Переводит число(char) в число(int)
int translateToInt(char element[], int low, int high);

// Обратная польская запись
int reversePolish(char element[], struct StackElement* head, bool* isCorrect);