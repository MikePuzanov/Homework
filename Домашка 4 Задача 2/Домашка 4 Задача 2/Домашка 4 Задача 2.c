#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!");
        return 2;
    }
    printf("Тест пройден!\n");
    int array[100] = { 0 };
    int size = 0;
    printf("Введите длину массива - ");
    scanf("%i", &size);
    printf("\n");
    if (size < 1)
    {
        printf("Ввод некорректных данных!");
        return 1;
    }
    arrayRandom(array, size);
    printf("Массив: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%i ", array[i]);
    }
    quickSort(array, 0, size - 1);
    printf("\n");
    search(array, size);
    printf("\nОтвет: %i", search(array, size));
}