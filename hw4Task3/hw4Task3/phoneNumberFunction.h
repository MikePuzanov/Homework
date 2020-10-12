#pragma once

#include <stdbool.h>

// структура книжки контактов
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// проверяет количество номеров в базе
bool addPerson(int index);

//поиск имени по номеру телефона
bool nameSearchWithPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// поиск номера по имени
bool phoneSearchWithName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// Проверяет есть ли введенное имя в базе
bool searchName(struct PhoneBook person[], int index);

// Проверяет есть ли введенный телефон в базе
bool searchPhone(struct PhoneBook person[], int index);

// функция для добавления номеров в файл
void printInFile(struct PhoneBook person[], int index, char* file);