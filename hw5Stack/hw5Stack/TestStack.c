#include "Stack.h"
#include "TestStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool testStack()
{
	struct StackElement* head = NULL;
	head = push(head, 6);
	if (push(head, 6)->value != 6)
	{
		deleteStack(&head);
		return false;
	}
	if (pop(&head) != 6)
	{
		deleteStack(&head);
		return false;
	}
	head = push(head, 5);
	head = push(head, 6);
	head = push(head, 1);
	if (isEmpty(head))
	{
		deleteStack(&head);
		return false;
	}
	for (int i = 0; i < 3; ++i)
	{
		pop(&head);
	}
	if (!isEmpty(head))
	{
		deleteStack(&head);
		return false;
	}
	deleteStack(&head);
	if (!isEmpty(head))
	{
		deleteStack(&head);
		return false;
	}
	return true;
}
