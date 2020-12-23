#include "List.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdbool.h>

bool testList()
{
	List* head = NULL;
	push(&head, 5, 1);
	if (getCity(head) != 5)
	{
		deleteList(&head);
		return false;
	}
	if (getRoadLength(head) != 1)
	{
		deleteList(&head);
		return false;
	}
	push(&head, 6, 3);
	removeFromHead(&head);
	if (getCity(head) != 5 && getRoadLength(head) != 1)
	{
		deleteList(&head);
		return false;
	}
	push(&head, 2, 11);
	List* node = head;
	node = getNextNode(node);
	if (getCity(node) != 5 && getRoadLength(node) != 1)
	{
		deleteList(&head);
		return false;
	}
	push(&head, 2, 11);
	push(&head, 2, 11);
	push(&head, 2, 11);
	if (getCity(getLast(head)) != 5 && getRoadLength(getLast(head)) != 1)
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
	return isEmpty(head);
}