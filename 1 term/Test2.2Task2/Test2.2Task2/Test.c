#include "List.h"
#include "Test.h"

#include <stdio.h>
#include <stdbool.h>

bool testList()
{
	List* head = NULL;
	push(&head, "fe" ,2);
	if (getValue(head) != 2)
	{
		deleteList(&head);
		return false;
	}
	pop(&head);
	if (head)
	{
		deleteList(&head);
		return false;
	}
	return true;
}