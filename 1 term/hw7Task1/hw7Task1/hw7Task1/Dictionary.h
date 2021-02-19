#pragma once

#include <stdbool.h>

// ��������� �������
typedef struct Node Node;

// ���������� ���� ����
int getKey(Node* root);

// ������� ���� �� �����
Node* findRoot(Node* root, const int key);

// ���������� ���� � ������
void pushToTree(const char* word, const int key, Node** root);

// ���������� ����� �� �����
char* getWord(Node* root, const int key);

// �������� ��������� ����
void deleteNode(Node** root, const int key);

// �������� ������
void deleteTree(Node** root);