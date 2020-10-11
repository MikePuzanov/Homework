#pragma once
#include <stdbool.h>

struct testPhoneBook
{
    char name[30];
    char phone[20];
};

// ��������� ������ ���������
struct phoneBook
{
    char name[30];
    char phone[20];
};

//����� ����� �� ������ ��������
void nameSearchWithPhone(struct phoneBook person[], int index, char phone[]);

// ����� ������ �� �����
void phoneSearchWithName(struct phoneBook person[], int index, char name[]);

// ��������������� ������� ��� addPerson, ������� ��������� ���� �� ��������� ��� � ����
bool searchName(struct phoneBook person[], int* index);

// ��������������� ������� ��� addPerson, ������� ��������� ���� �� ��������� ������� � ����
bool searchPhone(struct phoneBook person[], int* index);

// ������� ��� ���������� ������ ��������
void addPerson(struct phoneBook person[], int* index);

// ������� ��� ���������� ������� � ����
void printInFile(struct phoneBook person[], int index);


// ���� ��� ���������� ������ ��������
bool testForAddPerson();

// ���� ��� ������ �������� �� ����� ��� ������
bool testForSearch();

//
bool testWriteToFile();