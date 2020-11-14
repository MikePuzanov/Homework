#pragma once

typedef struct
{
	int key;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

// создание главного корня
Node* expressionMath(char line[], int* low, int high);

char printTree(Node* root);