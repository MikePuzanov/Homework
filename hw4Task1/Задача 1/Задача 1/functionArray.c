#include "functionArray.h"

#include <stdio.h>
#include <stdlib.h>

void arrayPrint(int array[], int size)
{
	while (size > 0)
	{
		printf("%i ", array[size - 1]);
		size--;
	}
}