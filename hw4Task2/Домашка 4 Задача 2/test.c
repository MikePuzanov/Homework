#include "test.h"
#include "sort.h"
#include "searchElement.h"

#include <stdbool.h>
#include <stdlib.h>

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
    search(array, 10);
    return search(array, 10) == array[0];
}