#pragma once

#include <stdbool.h>

// структура списка
typedef struct List List;

// создание списка
List* createList();

// получить слово
char* getWord(List* list, int index);

// получить частоту слова
int getFrequency(List* list, int index);

// получить длину списка
int getLength(List* list);

// добавить узел 
void append(List* list, const char* word);

// добавить узел в другой список
void rePush(List* list, const char* word, const int frequency);

// удалить узел
bool deleteNode(struct List* list, int index);

// удалить список
void deleteList(List** list);