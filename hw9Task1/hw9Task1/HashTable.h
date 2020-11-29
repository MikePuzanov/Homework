#pragma once

typedef struct Node Node;

// cтруктура хэш-таблицы
typedef struct Hash Hash;

// хэш-функция
int hashFunction(char* value);

// добавление узла в таблицу
Hash* insert(char* word, Hash* hashTable);

// создание таблицы
Hash* createHashTable();

// частота элемента 
int frequency(Hash* hash, int index, char word[]);

// печать частот в таблице
void printFrequency(Hash* hashTable, char fileName[]);

// печать коэфициента заполняемости
float fillFactor(Hash* hashTable);

// нахождение максимальной и средней длины списка в сегменте таблицы
void listLenght(Hash* hashTable, int* max, float* mid);