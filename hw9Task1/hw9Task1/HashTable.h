#pragma once

// cтруктура хэш-таблицы
typedef struct Hash Hash;

// создание таблицы
Hash* createHashTable();

// получить размер таблицы
int getHashSize(Hash* hashTable);

// добавление элемента в таблицу
void add(Hash* hashTable, const char* word);

// печать частот в таблице
void printFrequency(Hash* hashTable);

// печать коэфициента заполняемости
float fillFactor(Hash* hashTable);

// нахождение максимальной и средней длины списка в сегменте таблицы
void listLength(Hash* hashTable, int* max, float* mid);

// удаление таблицы
void deleteHashTable(Hash** hashTable);