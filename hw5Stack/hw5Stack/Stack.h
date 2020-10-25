#pragma once

#include <stdbool.h>

// 
struct Stack;

//
struct Stack* createStack(void);

// Функция добавление элемента в стек
void push(struct Stack* stack, int value);

// Функция удаление элемента стека
int pop(struct Stack* stack);

// Проверка очищенности элемента стека
bool isEmpty(struct Stack* stack);

// Функция очистки стека
void deleteStack(struct Stack** stack);
