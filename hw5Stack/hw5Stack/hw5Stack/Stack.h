#pragma once

#include <stdbool.h>

// Структура стек
struct StackElement
{
    int value;
    struct StackElement* next;
};

// Функция добавление элемента в стек
struct StackElement* push(struct StackElement* head, int element);

// Функция удаление элемента стека
int pop(struct StackElement** head);

// Проверка очищенности элемента стека
bool isEmpty(struct StackElement* head);

// Функция очистки стека
void deleteStack(struct StackElement** head);
