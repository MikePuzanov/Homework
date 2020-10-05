#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int firstElement = 0;
    int secondElement = 0;
    printf("Числа в десятичной сестеме: ");
    scanf("%i %i", &firstElement, &secondElement);
    int element = 0;
    int size = sizeof(int) * 8;
    bool* arrayFirst = (bool*)calloc(size, sizeof(int));
    binaryTransfer(firstElement, arrayFirst, size);
    bool* arraySecond = (bool*)calloc(size, sizeof(int));
    binaryTransfer(secondElement, arraySecond, size);
    bool* arraySum = (bool*)calloc(size, sizeof(int));
    addition(firstElement, secondElement, arraySum, size);
    printf("%i", decimalTransfer(arraySum, size));
    //bool arraySecond[8] =
    //binaryTransfer(secondElement);
    /*printf("Числа в двоичной сестеме: %i ", binaryFirstElement);
    int binarySecondElement = binaryTransfer(secondElement);
    printf("%i\n", binarySecondElement);
    int sumBinary = addition(binaryFirstElement, binarySecondElement);
    printf("Сумма в двоичном представлении: %i\n", sumBinary);
    int sumDecimal = decimalTransfer(sumBinary);
    printf("Сумма в десятичном представлении: %i\n", sumDecimal);*/
}