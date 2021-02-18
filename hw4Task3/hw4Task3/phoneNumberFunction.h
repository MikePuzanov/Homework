#pragma once

#include <stdbool.h>

// ��������� ������ ���������
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// ��������� ���������� ������� � ����
bool isPhonebookFull(int index);

// ����� ����� �� ������ ��������
bool nameSearchByPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// ����� ������ �� �����
bool phoneSearchByName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// ��������� ���� �� ��������� ��� � ����
bool doesNameExist(struct PhoneBook person[], char name[], int index);

// ��������� ���� �� ��������� ������� � ����
bool doesPhoneExist(struct PhoneBook person[], char phone[], int index);

// ������� ��� ���������� ������� � ����
void printInFile(struct PhoneBook person[], int index, char* file);

// �������� �� �����
<<<<<<< HEAD
void readFromFile(struct PhoneBook person[], int* index, char* file);
=======
void readFromFile(struct PhoneBook person[], int* index, char* file);
>>>>>>> hw5Stack
