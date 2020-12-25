#pragma once

#include <stdbool.h>

// ��������� �������
typedef struct Dictionary Dictionary;

// ������� �����
Dictionary* insert(Dictionary* root, const char* key, const char* word);

// �������� ���� �� �����
Dictionary* getNode(Dictionary* root, const char* key);

// �������� ����� � ������
bool isKeyExist(Dictionary* root, const char* key);

// �������� ����
Dictionary* deleteElement(Dictionary* root, const char* key);

// ������ ����� � ���� 
void printWord(Dictionary* root);

// �������� ������
void deleteTree(Dictionary* root);