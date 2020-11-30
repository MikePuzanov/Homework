#pragma once

typedef struct Node Node;

// c�������� ���-�������
typedef struct Hash Hash;

// �������� �������
Hash* createHashTable();

// ���-�������
int hashFunction(char* value, int hashSize);

// ���������� ���� � �������
Hash* insert(char* word, Hash* hashTable);

//
Hash* readFromFile(Hash* hashTable, char fileName[]);

// ������� �������� 
int frequency(Hash* hash, int index, char word[]);

// ������ ������ � �������
void printFrequency(Hash* hashTable, char fileName[]);

// ������ ����������� �������������
float fillFactor(Hash* hashTable);

// ���������� ������������ � ������� ����� ������ � �������� �������
void listLenght(Hash* hashTable, int* max, float* mid);