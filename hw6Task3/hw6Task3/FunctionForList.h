#pragma once

#include <stdbool.h>

// Структура
typedef struct List List;

// Добавление в список
void pushList(List** head, const char* name, const char* phone);

//
void pop(List** head);

//

List* assignNextNull(List* head);

//
List* assignToNext(List* head, List* node);

//
void getPhone(List* head, char phone[]);

//
void getName(List* head, char name[]);

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