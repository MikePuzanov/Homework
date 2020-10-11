#pragma once
#include <stdbool.h>

// ��������� ������ ���������
struct phoneBook
{
    char name[30];
    char phone[20];
};

//����� ����� �� ������ ��������
void nameSearchWithPhone(struct phoneBook person[], int* index, char phone[]);

// ����� ������ �� �����
void phoneSearchWithName(struct phoneBook person[], int* index, char name[]);

// ��������������� ������� ��� addPerson, ������� ��������� ���� �� ��������� ������� � ����
bool searchPhone(struct phoneBook person[], int* index);

// ������� ��� ���������� ������ ��������
void addPerson(struct phoneBook person[], int* index);

// ������� ��� ���������� ������� � ����
void printInFile(struct phoneBook person[], int index);
