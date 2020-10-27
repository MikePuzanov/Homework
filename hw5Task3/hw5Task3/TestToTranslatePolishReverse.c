#include "TestToTranslatePolishReverse.h"
#include "TranslateToPolishReverse.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool test()
{
	struct StackElement* head = NULL;
	char expression[30];
	int size = 0;
	translateToPolishReverse(head, "1 + 1", expression, &size);
	char answer[6] = "1 1 +";
	for (int i = 0; i < size; ++i)
	{
		if (answer[i] != expression[i])
		{
			return false;
		}
	}
	size = 0;
	translateToPolishReverse(head, "(1 + 1) * 2", expression, &size);
	char answer2[10] = "1 1 + 2 *";
	for (int i = 0; i < size; ++i)
	{
		if (answer2[i] != expression[i])
		{
			return false;
		}
	}
	return true;
}