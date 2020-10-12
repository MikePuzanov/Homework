#include "sort.h"
#include "test.h"
#include "searchElement.h"

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
    FILE* fileWithArray= fopen("hw4Task2array.txt", "r");
    if (fileWithArray == NULL)
    {
        printf("Файл не найден!\n");
        return 1;
    }
    int size = 0;
    int number = 0;
    int array[100] = { 0 }; 
    printf("Массив: ");
    while ((fscanf(fileWithArray, "%i", &number)) != EOF)
    {
        array[size] = number;
        printf("%i ", array[size]);
        ++size;
    }
    fclose(fileWithArray);
    quickSort(array, 0, size - 1);
    search(array, size);
    printf("\nОтвет: %i", search(array, size));
}