#include "Node.h"
#include "NodeTest.h"

#include <stdio.h>
#include <stdbool.h>

bool testNode()
{
	Node* head = NULL;
	push(&head, 5);
	if (head->value != 5)
	{
		return false;
	}
	if (pop(&head) != 5)
	{
		return false;
	}
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	insert(head, 2, 333);
	if (getLastButOne(head)->value != 333)
	{
		return false;
	}
	if (getLast(head)->value != 2)
	{
		return false;
	}
	if (getNth(head, 3)->value != 333)
	{
		return false;
	}
	pushBack(head, 123);
	if (getLast(head)->value != 123)
	{
		return false;
	}
	popBack(&head);
	if (getLast(head)->value == 123)
	{
		return false;
	}
	if (deleteNth(&head, 2) != 3)
	{
		return false;
	}
	return true;
}