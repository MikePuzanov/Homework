#include "TaskTest.h"
#include "SortList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testTask()
{
	List* head = NULL;
	pushToList(&head, 1);
	pushToList(&head, 5);
	pushToList(&head, 2);
	pushToList(&head, 6);
	pushToList(&head, 4);
	pushToList(&head, 3);
	for (int i = 1; i <= 6; ++i)
	{
		if (removeFromHead(&head) != i)
		{
			deleteList(&head);
			return false;
		}
	}
	pushToList(&head, 1);
	pushToList(&head, 5);
	pushToList(&head, 2);
	pushToList(&head, 6);
	pushToList(&head, 4);
	pushToList(&head, 3);
	if (!checkValue(head, 5))
	{
		deleteList(&head);
		return false;
	}
	if (checkValue(head, 115))
	{
		deleteList(&head);
		return false;
	}
	head = deleteNode(head, 5);
	if (checkValue(head, 5))
	{
		deleteList(&head);
		return false;
	}
	if (isEmpty(head))
	{
		deleteList(&head);
		return false;
	}
	deleteList(&head);
	return isEmpty(&head);
}