#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void randomArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = -50 + (rand() % 100);
    }
}

void sameArray(int array[], int size)
{
    array[0] = -50 + (rand() % 100);
    for (int i = 1; i < size; i++)
    {
        array[i] = array[0];
    }
}

bool compare(int array[],int size)
{
    for (int index = 0; index < size - 1; ++index)
    {
        if (array[index] > array[index + 1])
        {
            return false;
        }
    }
    return true;
}

void swap(int* first, int* second)
{
    int third = 0;
    third = *first;
    *first = *second;
    *second = third;
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

void insertionSort(int array[], int low, int high)
{
    for (int index = low + 1; index <= high; ++index)
    { 
        int addIndex = index;
        while (array[addIndex] <= array[addIndex - 1] && (addIndex != low))
        {
            swap(&array[addIndex], &array[addIndex - 1]);
            --addIndex;
        }
    }
}

void quickSort(int array[], int low, int high)
{
    if ((high - low) < 1) 
    {
        return 0;
    }
    if ((high - low + 1) < 10)
    {
        insertionSort(array, low, high);
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

bool test()
{
    int array[100] = { 0 };
    int size = 0;
    randomArray(array, 30);
    quickSort(array, 0, 29);
    if (!compare(array, 30))
    {
        return false;
    }
    sameArray(array, 30);
    quickSort(array, 0, 29);
    if (!compare(array, 30))
    {
        return false;
    }
    randomArray(array, 8);
    quickSort(array, 0, 7);
    if (!compare(array, 8))
    {
        return false;
    }
    return compare(array, 8);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!");
        return 1;
    }
    printf("Тест пройден!\n");
    int array[100] = {0};
    int size = 0;
    printf("Введите данные: ");
    scanf("%i", &size);
    if (size < 1)
    {
        printf("Ввод некорректных данных!");
        return 1;
    }
    printf("Массив: ");
    for (int i = 0; i < size; ++i)
    {
        array[i] = (50 - rand() % 100);
        printf("%i ", array[i]);
    }
    quickSort(array, 0, size - 1);
    printf("\nОтвет: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%i ", array[i]);
    }
}