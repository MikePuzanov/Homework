#include "TestToTranslatePolishReverse.h"
#include "TranslateToPolishReverse.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool test()
{
	struct StackElement* head = NULL;
	char line[30];
	char expression[30];
	int index = 0;
	if ( strcmp(translateToPolishReverse(head, "1 + 1", expression, &index), "1 1 +"))
}