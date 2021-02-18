#pragma once

#include <stdbool.h>

// структура приоритетной очереди
typedef struct PriorityQueue PriorityQueue;

// ‘ункци€ добавление
void enqueue(PriorityQueue** head, int value, int priority);

// удаление
int dequeue(PriorityQueue** head, int priority);

// ѕроверка на списка
bool isEmpty(PriorityQueue* head);

// ”даление очереди
void deletePriorityQueue(PriorityQueue** head);

// нахождение самого высокого приоритета
int findMaxPriority(PriorityQueue* head);