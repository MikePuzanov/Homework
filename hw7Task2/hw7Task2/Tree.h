#pragma once

#include <stdbool.h>

// обьявление структуры
typedef struct
{
	int key;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

// создание дерева
Node* buildTree(char line[], int* low, int high);

// дорабатывает дерево если корень плохой
Node* checkTree(Node* root);

// печать дерева
char printTree(Node* root, char line[], int* index);

// подсчет дерева
int countTree(Node* root, bool* correctExpression);

// удаление дерева
void deleteTree(Node* root);

// тесты
bool test();