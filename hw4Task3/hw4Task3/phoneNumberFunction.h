#pragma once

#include <stdbool.h>

// структура книжки контактов
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// проверяет количество номеров в базе
bool isPhonebookFull(int index);

// поиск имени по номеру телефона
bool nameSearchByPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// поиск номера по имени
bool phoneSearchByName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// Проверяет есть ли введенное имя в базе
bool doesNameExist(struct PhoneBook person[], char name[], int index);

// Проверяет есть ли введенный телефон в базе
bool doesPhoneExist(struct PhoneBook person[], char phone[], int index);

// функция для добавления номеров в файл
void printInFile(struct PhoneBook person[], int index, char* file);

// Загрузка из файла
<<<<<<< HEAD
void readFromFile(struct PhoneBook person[], int* index, char* file);
=======
void readFromFile(struct PhoneBook person[], int* index, char* file);
>>>>>>> hw5Stack
