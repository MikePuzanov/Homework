#pragma once

#include <stdbool.h>

// ���������� ���������
typedef struct
{
	int key;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

// �������� ������
Node* buildTree(char line[], int* low, int high);

// ������������ ������ ���� ������ ������
Node* checkTree(Node* root);

// ������ ������
char printTree(Node* root, char line[], int* index);

// ������� ������
int countTree(Node* root, bool* correctExpression);

// �������� ������
void deleteTree(Node* root);

// �����
bool test();