#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void swap(int* first, int* second)
{
    int third = 0;
    third = *first;
    *first = *second;
    *second = third;
}

void arraySame(int array[], int size)
{
    array[0] = -50 + (rand() % 100);
    for (int i = 1; i < size; ++i)
    {
        array[i] = array[0];
    }
}

void arrayRandom(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = -50 + (rand() % 100);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
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

void quickSort(int array[], int low, int high)
{
    if ((high - low) < 1)
    {
        return 0;
    }
    int section = 0;
    if (low < high)
    {
        section = partition(array, low, high);
        quickSort(array, low, section - 1);
        quickSort(array, section + 1, high);
    }
}

int search(int array[], int size)
{
    int countMain = 0;
    int countSecond = 0;
    int element = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] == array[i + 1])
        {
            countSecond++;
        }
        else
        {
            if (countSecond >= countMain)
            {
                countMain = countSecond;
                countSecond = 0;
                element = array[i];
            }
            else
            {
                countSecond = 0;
            }
        }
    }
    if (countSecond > countMain)
    {
        element = array[size - 1];
    }
    return element;
}

bool test()
{
    int element = 0;
    int array[100] = { 5, 5, 5, 1, 2, 12, 41, 12, 12, 1 };
    int size = 0;
    quickSort(array, 0, 9);
    search(array, 10, element);
    if (!(search(array, 10, element) == 5 || search(array, 10, element) == 12))
    {
        return false;
    }
    arraySame(array, 10);
    quickSort(array, 0, 9);
    search(array, 10, element);
    if (search(array, 10, element) != array[0])
    {
        return false;
    }
    return true;
}

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