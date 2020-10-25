#pragma once

#include <stdbool.h>

struct StackElement
{
    double value;
    struct StackElement* next;
};

// Функция добавление элемента в стек
struct StackElement* push(struct StackElement* head, double element);

// Функция удаление элемента стека
double pop(struct StackElement** head);

// Проверка очищенности элемента стека
bool isEmpty(struct StackElement* head);

// Функция очистки стека
void deleteStack(struct StackElement** head);