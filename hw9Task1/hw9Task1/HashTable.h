#pragma once

// ��������� ������
typedef struct Node Node;

// c�������� ���-�������
typedef struct Hash Hash;

// �������� �������
Hash* createHashTable();

// �������� ������ �������
int getHashSize(Hash* hashTable);

// ���������� ���� � �������
Node* insert(const char* word, Hash* hashTable, const int index);

// ������ � �����
Hash* readFromFile(Hash* hashTable, const char* fileName);

// ������� �������� 
int frequency(Hash* hash, const char* word);

// ������ ������ � �������
void printFrequency(Hash* hashTable);

// ������ ����������� �������������
float fillFactor(Hash* hashTable);

// ���������� ������������ � ������� ����� ������ � �������� �������
void listLength(Hash* hashTable, int* max, float* mid);

// �������� �������
void deleteHashTable(Hash** hashTable);