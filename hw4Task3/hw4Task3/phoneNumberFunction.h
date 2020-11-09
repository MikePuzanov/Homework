#pragma once

#include <stdbool.h>

// ñòðóêòóðà êíèæêè êîíòàêòîâ
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// ïðîâåðÿåò êîëè÷åñòâî íîìåðîâ â áàçå
bool isPhonebookFull(int index);

// ïîèñê èìåíè ïî íîìåðó òåëåôîíà
bool nameSearchByPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// ïîèñê íîìåðà ïî èìåíè
bool phoneSearchByName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// Ïðîâåðÿåò åñòü ëè ââåäåííîå èìÿ â áàçå
bool doesNameExist(struct PhoneBook person[], char name[], int index);

// Ïðîâåðÿåò åñòü ëè ââåäåííûé òåëåôîí â áàçå
bool doesPhoneExist(struct PhoneBook person[], char phone[], int index);

// ôóíêöèÿ äëÿ äîáàâëåíèÿ íîìåðîâ â ôàéë
void printInFile(struct PhoneBook person[], int index, char* file);

// Çàãðóçêà èç ôàéëà
void readFromFile(struct PhoneBook person[], int* index, char* file);