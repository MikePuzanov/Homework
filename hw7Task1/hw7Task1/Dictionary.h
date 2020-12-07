#pragma once

#include <stdbool.h>

// ���������
typedef struct Node Node;

// �������� �������� �����
Node* createRoot(int key, const char word);

// ���������� ���� � ������
void pushToTree(char word[], int key, Node* root);

// ����� ���� �� ��� �����
Node* findCurrentNode(Node* root, int key);

// �������� ��������� ����
void deleteNode(Node* root, int key);

// �������� ������
void deleteTree(Node* root);

// �������� ����� �� �����
bool checkWordInTree(Node* root, int key);