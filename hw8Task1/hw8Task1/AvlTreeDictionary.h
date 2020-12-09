#pragma once

#include <stdbool.h>

// структура
typedef struct Dictionary Dictionary;

// вставка ключа
Dictionary* insert(Dictionary* root, char key[], char word[]);

// проверка ключа в дерева
bool isKeyExist(Dictionary* root, char key[]);

// удаление узла
Dictionary* deleteNode(Dictionary* root, char key[]);

// получить узел по ключу
Dictionary* getNode(Dictionary* root, char key[]);

// печать слово в узле 
void printWord(Dictionary* root);

//
Dictionary* deleteTree(Dictionary* root);

//
bool isEmpty(Dictionary* root);