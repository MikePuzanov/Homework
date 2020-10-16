#include "Utility.h"
#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define size 32

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
    printf("Числа в двоичной системе: ");
    binaryTransfer(arrayFirst, firstElement, size);
    arrayPrint(arrayFirst, size);
    printf("  ");
    int arraySecond[32] = { 0 };
    binaryTransfer(arraySecond, secondElement, size);
    arrayPrint(arraySecond, size);
    int arraySum[32] = { 0 };
    int sizeSum = 0;
    addition(arrayFirst, size, arraySecond, arraySum);
    printf("\nСумма в двоичном представлении: ");
    arrayPrint(arraySum, size);
    int numberSum = decimalTransfer(arraySum, size);
    printf("\nСумма в десятичном представлении: %i\n", numberSum);
}