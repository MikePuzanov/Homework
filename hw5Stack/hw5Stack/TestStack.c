#include "Stack.h"
#include "TestStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool testStack()
{
	struct StackElement* head = NULL;
	if (push(head, 6)->value != 6)
	{
		return false;
	}
	head = push(head, 6);
	if (pop(&head) != 6)
	{
		return false;
	}
	head = push(head, 6);
	head = push(head, 6);
	head = push(head, 6);
	for (int i = 0; i < 3; ++i)
	{
		pop(&head);
	}
	deleteStack(&head);
	return isEmpty(head);
}