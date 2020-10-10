#pragma once
#include <stdbool.h>

// Перевод десятичных чисел в двоичную систему
int binaryTransfer(int array[], int number);

// Выыод массива в двоичном представлении
void printfarray(int array[], int size);

// Сложение в двоичном представлении
int addition(int arrayFirst[], int sizeFirst, int arraySecond[], int sizeSecond, int arraySum[]);

// Перевод из двоичного представления в десятичное
int decimalTransfer(int array, int size);

// Вспомогательная функция для теста, которая проверяет правильность перевода в двоичную систему
bool compare(int array[], int number, int size);

// функция теста
bool test();