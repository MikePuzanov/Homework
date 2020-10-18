#pragma once

#include <stdbool.h>

// ��������� ������ ���������
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// ��������� ���������� ������� � ����
bool checkNumberOfPerson(int index);

// ����� ����� �� ������ ��������
bool nameSearchByPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// ����� ������ �� �����
bool phoneSearchByName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// ��������� ���� �� ��������� ��� � ����
bool checkName(struct PhoneBook person[], char name[], int index);

// ��������� ���� �� ��������� ������� � ����
bool checkPhone(struct PhoneBook person[], char phone[], int index);

// ������� ��� ���������� ������� � ����
void printInFile(struct PhoneBook person[], int index, char* file);