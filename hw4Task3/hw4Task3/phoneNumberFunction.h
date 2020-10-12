#pragma once

#include <stdbool.h>

// ��������� ������ ���������
struct PhoneBook
{
    char name[30];
    char phone[20];
};

// ��������� ���������� ������� � ����
bool addPerson(int index);

//����� ����� �� ������ ��������
bool nameSearchWithPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp);

// ����� ������ �� �����
bool phoneSearchWithName(struct PhoneBook person[], int index, char name[], int* indexHelp);

// ��������� ���� �� ��������� ��� � ����
bool searchName(struct PhoneBook person[], int index);

// ��������� ���� �� ��������� ������� � ����
bool searchPhone(struct PhoneBook person[], int index);

// ������� ��� ���������� ������� � ����
void printInFile(struct PhoneBook person[], int index, char* file);