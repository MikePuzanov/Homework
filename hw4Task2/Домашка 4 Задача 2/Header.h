#pragma once
#include <stdbool.h>

// меняет значения переменных местами
void swap(int* first, int* second);

// Создает массив из одинаковых элементов
void arraySame(int array[], int size);

// Создает массив из рандомных элементов
void arrayRandom(int array[], int size);

// Вспомогательный алгоритм для быстрой сортировки
int partition(int array[], int low, int high);

// Алгоритм быстрой сортировки
void quickSort(int array[], int low, int high);

// Функция поиска часто встречающегося элемента
int search(int array[], int size);

// Функция тестов
bool test();