#pragma once

#include <stdbool.h>

// структура словаря
typedef struct Dictionary Dictionary;

// вставка ключа
Dictionary* insert(Dictionary* root, const char* key, const char* word);

// получить узел по ключу
Dictionary* getNode(Dictionary* root, const char* key);

// проверка ключа в дерева
bool isKeyExist(Dictionary* root, const char* key);

// удаление узла
Dictionary* deleteElement(Dictionary* root, const char* key);

// печать слово в узле 
void printWord(Dictionary* root);

// удаление дерева
void deleteTree(Dictionary* root);