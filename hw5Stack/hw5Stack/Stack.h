#pragma once

#include <stdbool.h>

// Обьявление структуры
struct StackElement
{
<<<<<<< HEAD
	int value;
	struct StackElement* next;
=======
    int value;
    struct StackElement* next;
>>>>>>> hw5Stack
};

// Функция добавление элемента в стек
struct StackElement* push(struct StackElement* head, int element);

// Функция удаление элемента стека
int pop(struct StackElement** head);

// Проверка очищенности элемента стека
bool isEmpty(struct StackElement* head);

// Функция очистки стека
void deleteStack(struct StackElement** head);