#pragma once

#include <stdbool.h>

typedef struct
{
	int key;
	char* word;
	struct Node* left;
	struct Node* right;
} Node;

// �������� �������� �����
Node* createRoot();

// ���������� ���� � �������� ���� ������� ����� ����
Node* findRoot(Node* root, int key);

// ���������� ���� � ������
void pushToTree(char word[], int key, Node* root);

// ����� ���� �� ��� �����
Node* findCurrentNode(Node* root, int key);

// ������� ��������
Node* parent(Node* root, int key);

// ������� ������� � ������� ���� ������ swap
Node* findSwapNode(Node* current);

// �������� ��������� ����
void deleteNode(Node* root, int key);

// �������� ������
void deleteTree(Node* root);

// �������� ����� �� �����
bool checkWordInTree(Node* root, int key);