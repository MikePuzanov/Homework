#pragma once

#include <stdbool.h>

// ���������
typedef struct Node Node;

// �������� �������� �����
Node* createRoot(int key, const char word[]);

// ���������� ���� ����
int getKey(Node* root);

// ������� ���� �� �����
Node* findRoot(Node* root, int key);

// ���������� ���� � ������
void pushToTree(char word[], int key, Node** root);

// ���������� ����� �� �����
char* getWord(Node* root, int key);

// �������� ��������� ����
void deleteNode(Node** root, int key);

// �������� ������
void deleteTree(Node** root);