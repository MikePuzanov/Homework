#include "Stack.h"
#include "testStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool test()
{
	struct Stack* stack = createStack();
	push(stack, 6);
	if (pop(&stack) != 6)
	{
		return false;
	}
	push(stack, 5);
	push(stack, 6);
	push(stack, 1);
	for (int i = 0; i < 3; ++i)
	{
		pop(&stack);
	}
	deleteStack(&stack);
	return isEmpty(&stack);
}
