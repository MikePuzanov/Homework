#pragma once

#include <stdbool.h>

// ���������
typedef struct Dictionary Dictionary;

// ������� �����
Dictionary* insert(Dictionary* root, char key[], char word[]);

// �������� ����� � ������
Dictionary* isKeyExist(Dictionary* root, char key[]);

// �������� ����
Dictionary* deleteElement(Dictionary* root, char key[]);

// ������ ����� � ���� 
void printWord(Dictionary* root);

// �������� ������
Dictionary* deleteTree(Dictionary* root);

// �������� �� �������
bool isEmpty(Dictionary* root);