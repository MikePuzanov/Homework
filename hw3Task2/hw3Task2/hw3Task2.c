#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

void swap(int* firstElement, int* secondElement)
{
    int additionalElement = 0;
    additionalElement = *firstElement;
    *firstElement = *secondElement;
    *secondElement = additionalElement;
}

int partition(int array[], int low, int high)
{
    const int pivot = array[high];
    int wall = low;
    for (int j = low; j < high; ++j)
    {
        if (array[j] <= pivot)
        {
            if (j == wall)
            {
                wall++;
            }
            else
            {
                swap(&array[wall], &array[j]);
                wall++;
            }
        }
    }
    if (wall == high)
    {
        return wall;
    }
    swap(&array[wall], &array[high]);
    return wall;
}

int quickSort(int array[], int low, int high)
{
    if ((high - low) < 1)
    {
        return 0;
    }
    if (low < high)
    {
        quickSort(array, low, partition(array, low, high) - 1);
        quickSort(array, partition(array, low, high) + 1, high);
    }
}

int numberInArray(int array[], int number, int low, int high)
{
    if (high - low <= 1)
    {
        if (number == array[low] || number == array[high])
        {
            return number;
        }
        return number + 1;
    }
    if (number <= array[(low + high) / 2])
    {
        high = (low + high) / 2;
    }
    else
    {
        low = (low + high) / 2 + 1;
    }
    return numberInArray(array, number, low, high);
}

int compare(int arrayK[], int arrayN[], int sizeK, int sizeN)
{
    int answer = 0;
    for (int i = 0; i < sizeK; ++i)
    {
        if (arrayK[i] == numberInArray(arrayN, arrayK[i], 0, sizeN))
        {
            ++answer;
        }
    }
    return answer;
}

void arraySame(int arrayN[], int sizeN, int arrayK[], int sizeK)
{
    for (int i = 0; i < sizeN; ++i)
    {
        arrayN[i] = 3;
    }
    for (int i = 0; i < sizeK; ++i)
    {
        arrayK[i] = 3;
    }
}

bool test()
{
    int arrayN[10] = { 3, 5, 1, 2, -4, -2, -9, 0, 24, -13 };
    int arrayK[5] = { 3, 12, 2, -34, -11 };
    int size = 10;
    quickSort(arrayN, 0, 9);
    return compare(arrayK, arrayN, 5, 10) == 2;
    arraySame(arrayN, 10, arrayK, 5);
    quickSort(arrayN, 0, 9);
    return compare(arrayK, arrayN, 5, 10) == 5;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test)
    {
        printf("Тест не пройден!");
        return 1;
    }
    printf("Тест пройден!\n");
    int sizeN = 0;
    int sizeK = 0;
    printf("Введите числа n и k: ");
    scanf("%i %i", &sizeN, &sizeK);
    int array[100] = { 0 };
    printf("Массив: ");
    for (int i = 0; i < sizeN; ++i)
    {
        array[i] = (-50 + (rand() % 100));
        printf("%i ", array[i]);
    }
    quickSort(array, 0, sizeN - 1);
    printf("\n");
    for (int i = 0; i < sizeK; ++i)
    {
        int number = -50 + (rand() % 100);
        if ((number >= array[0]) && (number <= array[sizeN - 1]))
        {
            if (number == numberInArray(array, number, 0, sizeN - 1))
            {
                printf("Число %i содержится!\n", number);
            }
            else
            {
                printf("Число %i не содержится!\n", number);
            }
        }
        else
        {
            printf("Число %i не содержится!\n", number);
        }
    }
}