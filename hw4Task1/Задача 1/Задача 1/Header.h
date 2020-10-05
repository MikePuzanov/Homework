#pragma once
#include <stdbool.h>

// Перевод десятичных чисел в двоичную систему
void binaryTransfer(int number, bool array[], int size);

// Сложение в двоичном представлении
void addition(bool firstElement[], bool secondElement[], bool arraySum[], int size);

// Перевод из двоичного представления в десятичное
int decimalTransfer(bool arraySum[], int size);

//
bool test();