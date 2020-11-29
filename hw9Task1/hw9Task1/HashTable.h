#pragma once

typedef struct Node Node;

// c�������� ���-�������
typedef struct Hash Hash;

// ���-�������
int hashFunction(char* value);

// ���������� ���� � �������
Hash* insert(char* word, Hash* hashTable);

// �������� �������
Hash* createHashTable();

// ������� �������� 
int frequency(Hash* hash, int index, char word[]);

// ������ ������ � �������
void printFrequency(Hash* hashTable, char fileName[]);

// ������ ����������� �������������
float fillFactor(Hash* hashTable);

// ���������� ������������ � ������� ����� ������ � �������� �������
void listLenght(Hash* hashTable, int* max, float* mid);