#pragma once

#include <stdbool.h>

// ��������� ������ ���������
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// ��������� ���������� ������� � ����
<<<<<<< HEAD
bool checkNumberOfPerson(int index);
=======
bool isPhonebookFull(int index);
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675

// ����� ����� �� ������ ��������
bool nameSearchByPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// ����� ������ �� �����
bool phoneSearchByName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// ��������� ���� �� ��������� ��� � ����
<<<<<<< HEAD
bool checkName(struct PhoneBook person[], char name[], int index);

// ��������� ���� �� ��������� ������� � ����
bool checkPhone(struct PhoneBook person[], char phone[], int index);

// ������� ��� ���������� ������� � ����
void printInFile(struct PhoneBook person[], int index, char* file);
=======
bool doesNameExist(struct PhoneBook person[], char name[], int index);

// ��������� ���� �� ��������� ������� � ����
bool doesPhoneExist(struct PhoneBook person[], char phone[], int index);

// ������� ��� ���������� ������� � ����
void printInFile(struct PhoneBook person[], int index, char* file);

// �������� �� �����
void readFromFile(struct PhoneBook person[], int* index, char* file);
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
