#include "Stack.h"
#include "TestStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool testStack()
{
	struct StackElement* head = NULL;
	head = push(head, 6);
	if (head->value != 6)
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
	for (int i = 0; i < 3; ++i)
	{
		pop(&head);
	}
	deleteStack(&head);
	return isEmpty(head);
}
