#pragma once

typedef struct Node Node;

// cтруктура хэш-таблицы
typedef struct Hash Hash;

// создание таблицы
Hash* createHashTable();

// хэш-функция
int hashFunction(char* value, int hashSize);

//
int getHashSize(Hash* hashTable);

// добавление узла в таблицу
Hash* insert(char* word, Hash* hashTable);

// чтение с файла
Hash* readFromFile(Hash* hashTable, char fileName[]);

// частота элемента 
int frequency(Hash* hash, int index, char word[]);

// печать частот в таблице
void printFrequency(Hash* hashTable);

// печать коэфициента заполняемости
float fillFactor(Hash* hashTable);

// нахождение максимальной и средней длины списка в сегменте таблицы
void listLenght(Hash* hashTable, int* max, float* mid);

//
void deleteHashTable(Hash** hashTable);