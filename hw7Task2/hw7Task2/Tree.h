#pragma once

typedef struct
{
	int key;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

// �������� �������� �����
Node* expressionMath(char line[], int* low, int high);

char printTree(Node* root);