#pragma once

#include <stdbool.h>

// структура
typedef struct Node Node;

// создание главного корня
Node* createRoot(int key, const char word[]);

// возвращает ключ узла
int getKey(Node* root);

// находит узел по ключу
Node* findRoot(Node* root, int key);

// добавление узла в дерево
void pushToTree(char word[], int key, Node** root);

// возвращает слово по ключу
char* getWord(Node* root, int key);

// удаление заданного узла
void deleteNode(Node** root, int key);

// удаление дерева
void deleteTree(Node** root);