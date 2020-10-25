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
	if (push(head, 6)->value != 6)
	{
		return false;
	}
	head = push(head, 6);
	if (pop(&head) != 6)
	{
		return false;
	}
	deleteStack(&head);
	return isEmpty(head);
}
