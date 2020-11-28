#pragma once

//
typedef struct Node Node;

//
int hashFunction(char* value);

//
Node* insert(char* word, Node** hashTable);

//
Node** createHashTable(const char fileName[], Node** hashTable);