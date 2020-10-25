#include "Stack.h"

#include <stdio.h>

int main(void)
{
	if (!testStack())
	{
		return 1;
	}
	struct Stack* stack = createStack();
	push(stack, 3);
	push(stack, 5);
	push(stack, 6);
	push(stack, 6);
	push(stack, 5);
	push(stack, 3);
	printf("%i\n", pop(stack));
	printf("%i\n", pop(stack));
	printf("%i\n", pop(stack));
	deleteStack(&stack);
	printf(isEmpty(&stack) ? "true" : "false");
	return 0;
}