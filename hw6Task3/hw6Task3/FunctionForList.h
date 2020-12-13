#pragma once

#include <stdbool.h>

// Структура
typedef struct List List;

// Добавление в список
void pushList(List** head, const char* name, const char* phone);

//
void pop(List** head);

//
void nextToNext(List** head, List* node);

//
char getPhone(List* head);

//
char getName(List* head);

//
List* getNext(List* head);

// распечатать телефоннную книжку
void printPhonebook(List* head);

// считывае с файла
void scanfFromFile(char file[], List** head);

// проверка на пустоту
bool isEmpty(List* head);

// удаление списка
void deleteList(List** head);