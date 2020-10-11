﻿#include "Utility.h"
#include "functionArray.h"
#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!");
        return 1;
    }
    printf("Тест пройден!\n");
    int firstElement = 0;
    int secondElement = 0;
    printf("Введите числа в десятичной сестеме: ");
    scanf("%i %i", &firstElement, &secondElement);
    int element = 0;
    int arrayFirst[32] = { 0 };
    int sizeFirst = binaryTransfer(arrayFirst, firstElement);
    printf("Числа в двоичной системе: ");
    printfarray(arrayFirst, sizeFirst);
    int arraySecond[32] = { 0 };
    int sizeSecond = binaryTransfer(arraySecond, secondElement);
    printf(" ");
    printfarray(arraySecond, sizeSecond);
    int arraySum[32] = { 0 };
    int sizeSum = addition(arrayFirst, sizeFirst, arraySecond, sizeSecond, arraySum);
    printf("\nСумма в двоичном представлении: ");
    printfАrray(arraySum, sizeSum);
    int numberSum = decimalTransfer(arraySum, sizeSum);
    printf("\nСумма в десятичном представлении: %i\n", numberSum);
}