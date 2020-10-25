#include "Stack.h"
#include "testStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct StackElement
{
	int value;
	struct StackElement* next;
};

bool testStack()
{
	struct StackElement* head = NULL;
	push(head, 6);
	if (push(head, 6)->value != 6)
	{
		return false;
	}
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
