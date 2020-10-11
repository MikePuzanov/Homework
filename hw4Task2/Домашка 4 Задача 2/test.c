#include "test.h"
#include "functionForSort.h"

#include <stdbool.h>

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
    return search(array, 10, element) == array[0]
}
