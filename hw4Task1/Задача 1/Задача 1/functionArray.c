#include "functionArray.h"

#include <stdio.h>
#include <stdlib.h>

void printfÀrray(int array[], int size)
{
	while (size > 0)
	{
		printf("%i ", array[size - 1]);
		size--;
	}
}