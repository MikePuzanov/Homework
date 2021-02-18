#include "ListSort.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test()
{
	List* head = NULL;
	int array[15] = { 5, 2, 2, 4, 1, 3, 1, 5, 6, 3, 1, 23, 12, 7, 6};
	for (int i = 0; i < 15; ++i)
	{
		pushtoList(&head, array[i]);
	}
	if (getValue(head) != 1 && getCount(head) != 3)
	{
		deleteList(&head);
		return false;
	}
	head = getNext(head);
	if (getValue(head) != 2 && getCount(head) != 2)
	{
		deleteList(&head);
		return false;
	}

	head = getNext(head);
	if (getValue(head) != 3 && getCount(head) != 1)
	{
		deleteList(&head);
		return false;
	}
	deleteList(&head);
	return isEmpty(head);
}