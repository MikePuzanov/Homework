#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// �������� ������
List* createList();

// �������� �����
char* getWord(List* list, int index);

// �������� ������� �����
int getFrequency(List* list, int index);

// �������� ����� ������
int getLength(List* list);

// �������� ���� 
void append(List* list, const char* word);

// �������� ���� � ������ ������
void rePush(List* list, const char* word, const int frequency);

// ������� ����
bool deleteNode(struct List* list, int index);

// ������� ������
void deleteList(List** list);