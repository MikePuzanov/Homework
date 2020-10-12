#include "functionForSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void swap(int* first, int* second)
{
    int third = *first;
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
        return;
    }
    int section = 0;
    if (low < high)
    {
        section = partition(array, low, high);
    }
    quickSort(array, low, section - 1);
    quickSort(array, section + 1, high);
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