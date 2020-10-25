#include "Stack.h"
#include "testStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool test()
{
	struct StackElement* head = NULL;
	if (push(head, 6)->value != 6)
	{
		return false;
	}
	push(head, 6);
	if (pop(&head) != 6)
	{
		return false;
	}
	push(head, 5);
	push(head, 6);
	push(head, 1);
	for (int i = 0; i < 3; ++i)
	{
		pop(&head);
	}
	deleteStack(&head);
	return isEmpty(head);
}
