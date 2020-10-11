#pragma once
#include <stdbool.h>

// структура книжки контактов
struct phoneBook
{
    char name[30];
    char phone[20];
};

//поиск имени по номеру телефона
void nameSearchWithPhone(struct phoneBook person[], int* index, char phone[]);

// поиск номера по имени
void phoneSearchWithName(struct phoneBook person[], int* index, char name[]);

// вспомогательная функция для addPerson, которая проверяет есть ли введенный телефон в базе
bool searchPhone(struct phoneBook person[], int* index);

// функция для добавления нового контакта
void addPerson(struct phoneBook person[], int* index);

// функция для добавления номеров в файд
void printInFile(struct phoneBook person[], int index);
