#pragma once

#include <stdbool.h>

// —труктура списка
typedef struct List List;

// ƒобавление в список
void pushList(List** head, const char* name, const char* phone);

// удаление
void pop(List** head);

// сделать следующий узел NULL
List* assignNextNull(List* head);

// присвоить head->next = node
List* assignToNext(List* head, List* node);

// получить номер
void getPhone(List* head, char phone[]);

// получить им€
void getName(List* head, char name[]);

// получить следующий узел
List* getNext(List* head);

// распечатать телефоннную книжку
void printPhonebook(List* head);

// считывание с файла
void scanfFromFile(char file[], List** head);

// проверка на пустоту
bool isEmpty(List* head);

// удаление списка
void deleteList(List** head);