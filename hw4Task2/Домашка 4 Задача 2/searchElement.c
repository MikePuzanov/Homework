#include "searchElement.h"

#include <stdio.h>
#include <stdlib.h>

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