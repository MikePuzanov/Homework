#pragma once

#include <stdbool.h>

// ñòðóêòóðà êíèæêè êîíòàêòîâ
struct PhoneBook
{
    char name[30];
    char phone[20];
};

<<<<<<< HEAD
// ïðîâåðÿåò êîëè÷åñòâî íîìåðîâ â áàçå
=======
// ��������� ���������� ������� � ����
>>>>>>> master
bool isPhonebookFull(int index);

// ïîèñê èìåíè ïî íîìåðó òåëåôîíà
bool nameSearchByPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// ïîèñê íîìåðà ïî èìåíè
bool phoneSearchByName(struct PhoneBook person[], int index, char name[], int* indexHelp);

<<<<<<< HEAD
// Ïðîâåðÿåò åñòü ëè ââåäåííîå èìÿ â áàçå
=======
// ��������� ���� �� ��������� ��� � ����
>>>>>>> master
bool doesNameExist(struct PhoneBook person[], char name[], int index);

// Ïðîâåðÿåò åñòü ëè ââåäåííûé òåëåôîí â áàçå
bool doesPhoneExist(struct PhoneBook person[], char phone[], int index);

// ôóíêöèÿ äëÿ äîáàâëåíèÿ íîìåðîâ â ôàéë
void printInFile(struct PhoneBook person[], int index, char* file);

<<<<<<< HEAD
// Çàãðóçêà èç ôàéëà
=======
// �������� �� �����
>>>>>>> master
void readFromFile(struct PhoneBook person[], int* index, char* file);