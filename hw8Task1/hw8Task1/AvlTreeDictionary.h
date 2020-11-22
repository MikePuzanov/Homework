#pragma once

#include <stdbool.h>

// структура
typedef struct Node Node;

// вставка ключа
Node* insert(Node* root, int key, char word[]);

// проверка ключа в дерева
bool isKeyExist(Node* root, int key);

// удаление узла
Node* deleteNode(Node* root, int key);

// получить узел по ключу
Node* getNode(Node* root, int key);

// печать слово в узле 
void printWord(Node* root);

//
Node* deleteTree(Node* root);

//
bool isEmpty(Node* root);