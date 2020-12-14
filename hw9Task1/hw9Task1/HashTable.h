#pragma once

// структура списка
typedef struct Node Node;

// cтруктура хэш-таблицы
typedef struct Hash Hash;

// создание таблицы
Hash* createHashTable();

// получить размер таблицы
int getHashSize(Hash* hashTable);

// добавление узла в таблицу
Node* insert(const char* word, Hash* hashTable, const int index);

// чтение с файла
Hash* readFromFile(Hash* hashTable, const char* fileName);

// частота элемента 
int frequency(Hash* hash, const char* word);

// печать частот в таблице
void printFrequency(Hash* hashTable);

// печать коэфициента заполняемости
float fillFactor(Hash* hashTable);

// нахождение максимальной и средней длины списка в сегменте таблицы
void listLength(Hash* hashTable, int* max, float* mid);

// удаление таблицы
void deleteHashTable(Hash** hashTable);