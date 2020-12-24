#pragma once

#include <stdbool.h>

// структура словаря
typedef struct Node Node;

// возвращает ключ узла
int getKey(Node* root);

// находит узел по ключу
Node* findRoot(Node* root, const int key);

// добавление узла в дерево
void pushToTree(const char* word, const int key, Node** root);

// возвращает слово по ключу
char* getWord(Node* root, const int key);

// удаление заданного узла
void deleteNode(Node** root, const int key);

// удаление дерева
void deleteTree(Node** root);