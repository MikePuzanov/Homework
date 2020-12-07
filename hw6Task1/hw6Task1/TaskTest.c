#include "TaskTest.h"
#include "SortList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testTask()
{
	List* head = NULL;
	pushtoList(&head, 1);
	pushtoList(&head, 5);
	pushtoList(&head, 2);
	pushtoList(&head, 6);
	pushtoList(&head, 4);
	pushtoList(&head, 3);
	for (int i = 1; i <= 6; ++i)
	{
		if (pop(&head) != i)
		{
			deleteList(&head);
			return false;
		}
	}
	pushtoList(&head, 1);
	pushtoList(&head, 5);
	pushtoList(&head, 2);
	pushtoList(&head, 6);
	pushtoList(&head, 4);
	pushtoList(&head, 3);
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