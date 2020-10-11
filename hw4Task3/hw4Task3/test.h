#pragma once
#include <stdbool.h>

struct testPhoneBook
{
    char name[30];
    char phone[20];
};

// тест для добавления нового контакта
bool testForAddPerson();

// тест для поиска телефона по имени или номеру
bool testForSearch();

// тест длә проверки ввода данных в файл
bool testWriteToFile();