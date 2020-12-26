#pragma once

#include <stdbool.h>

// структура стека
struct StackElement
{
    int value;
    struct StackElement* next;
};

// функция добавление элемента в стек
struct StackElement* push(struct StackElement* head, int element);

// функция удаление элемента стека
int pop(struct StackElement** head);

// проверка очищенности элемента стека
bool isEmpty(struct StackElement* head);

// функция очистки стека
void deleteStack(struct StackElement** head);
