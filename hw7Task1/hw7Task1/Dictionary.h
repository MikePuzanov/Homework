#pragma once

#include <stdbool.h>

// структура
typedef struct Node Node;

// создание главного корня
Node* createRoot(int key, const char word);

// добавление узла в дерево
void pushToTree(char word[], int key, Node* root);

// наход узла по его ключу
Node* findCurrentNode(Node* root, int key);

// удаление заданного узла
void deleteNode(Node* root, int key);

// удаление дерева
void deleteTree(Node* root);

// проверка слова по ключу
bool checkWordInTree(Node* root, int key);