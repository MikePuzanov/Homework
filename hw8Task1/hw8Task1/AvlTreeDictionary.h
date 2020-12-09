#pragma once

#include <stdbool.h>

// ���������
typedef struct Dictionary Dictionary;

// ������� �����
Dictionary* insert(Dictionary* root, char key[], char word[]);

// �������� ����� � ������
bool isKeyExist(Dictionary* root, char key[]);

// �������� ����
Dictionary* deleteNode(Dictionary* root, char key[]);

// �������� ���� �� �����
Dictionary* getNode(Dictionary* root, char key[]);

// ������ ����� � ���� 
void printWord(Dictionary* root);

//
Dictionary* deleteTree(Dictionary* root);

//
bool isEmpty(Dictionary* root);