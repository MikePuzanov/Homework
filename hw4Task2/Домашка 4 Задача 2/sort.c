#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second)
{
    int third = *first;
    *first = *second;
    *second = third;
}

void quickSort(int array[], int low, int high)
{
    if ((high - low) < 1)
    {
        return;
    }
    int section = 0;
    int wall = low;
    if (low < high)
    {
        int pivot = array[high];
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
        if (wall != high)
        {
           swap(&array[wall], &array[high]);
        }
    }
    quickSort(array, low, wall - 1);
    quickSort(array, wall + 1, high);
}