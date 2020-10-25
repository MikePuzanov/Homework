#include "Stack.h"
#include "testStack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct StackElement
{
    int number;
    struct StackElement* next;
};

struct Stack
{
    struct StackElement* head;
};

struct Stack* createStack(void)
{
	struct Stack* newStack = malloc(sizeof(struct Stack));
	newStack->head = NULL;
	return newStack;
}

void push(struct Stack* stack, int value)
{
	struct StackElement* newElement = malloc(sizeof(struct StackElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->number = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

int pop(struct Stack* stack)
{
	if (stack->head == NULL)
	{
		return 0;
	}
	int element = stack->head->number;
	struct StackElement* oldElement = stack->head;
	stack->head = stack->head->next;
	free(oldElement);
	return element;
}

bool isEmpty(struct Stack* stack)
{
	return stack->head == NULL;
}

void deleteStack(struct Stack** stack)
{
	while ((*stack)->head != NULL)
	{
		pop(*stack);
	}
	free(*stack);
	*stack = NULL;
}