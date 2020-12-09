#pragma once

#include <stdbool.h>

// структура
typedef struct Dictionary Dictionary;

// вставка ключа
Dictionary* insert(Dictionary* root, char key[], char word[]);

// проверка ключа в дерева
Dictionary* isKeyExist(Dictionary* root, char key[]);

// удаление узла
Dictionary* deleteElement(Dictionary* root, char key[]);

// печать слово в узле 
void printWord(Dictionary* root);

// удаление дерева
Dictionary* deleteTree(Dictionary* root);

// проверка на пустоту
bool isEmpty(Dictionary* root);