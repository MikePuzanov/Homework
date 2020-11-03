#pragma once

#include <stdbool.h>

// Структура
typedef struct List {
    long value;
    char name[20];
    struct List* next;
} List;

// Добавление в список
void pushList(List** head, char name[20], long element);

// распечатать телефоннную книжку
void printPhonebook(List* head);

// считывае с файла
void scanfFromFile(char file[], List** head);

// проверка на пустоту
bool isEmpty(List* head);

// удаление списка
void deleteList(List** head)