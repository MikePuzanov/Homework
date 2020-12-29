#include "DFA.h"
#include "Test.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool test()
{
	char* answer1 = DFA("asdfg/*asdfgh*/");
	char* answer2 = DFA("asd/*asdfgh*/asd");
	char* answer3 = DFA("asd/*asdfgh*/asd/*asdfgh*/");
	char* answer4 = DFA("asdfgh");
	bool result = strcmp(answer1, "/*asdfgh*/") + strcmp(answer2, "/*asdfgh*/") + strcmp(answer3, "/*asdfgh*//*asdfgh*/") + strcmp(answer4, "") == 0;
	free(answer1);
	free(answer2);
	free(answer3);
	free(answer4);
	return result;
}