#include "List.h"
#include "Test.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool test()
{
	int size = 0;
	List* head1 = NULL;
	makeList(&head1, "test.txt", &size);
	List* head2 = NULL;
	turnList(&head1, &head2);
	while (size > 1)
	{
		if (size != deleteNth(&head2, size - 1))
		{
			return false;
		}
		size--;
	}
}