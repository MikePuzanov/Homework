#pragma once

#include <stdbool.h>

typedef struct
{
	int key;
	char* word;
	struct Node* left;
	struct Node* right;
} Node;

// создание главного корня
Node* createRoot();

// находитить узел к которому надо крепить новый узел
Node* findRoot(Node* root, int key);

// добавление узла в дерево
void pushToTree(char word[], int key, Node* root);

// наход узла по его ключу
Node* findCurrentNode(Node* root, int key);

// находит родителя
Node* parent(Node* root, int key);

// находит элемент с который надо делать swap
Node* findSwapNode(Node* current);

// удаление заданного узла
void deleteNode(Node* root, int key);

// удаление дерева
void deleteTree(Node* root);

// проверка слова по ключу
bool checkWordInTree(Node* root, int key);