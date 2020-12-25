#pragma once

// c�������� ���-�������
typedef struct Hash Hash;

// �������� �������
Hash* createHashTable();

// �������� ������ �������
int getHashSize(Hash* hashTable);

// ���������� �������� � �������
void add(Hash* hashTable, const char* word);

// ������ ������ � �������
void printFrequency(Hash* hashTable);

// ������ ����������� �������������
float fillFactor(Hash* hashTable);

// ���������� ������������ � ������� ����� ������ � �������� �������
void listLength(Hash* hashTable, int* max, float* mid);

// �������� �������
void deleteHashTable(Hash** hashTable);