#include "DFA.h"
#include "Test.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool test()
{
	int** statesTable = readStateTable("StateTable.txt");
	bool isInComment = false;
	char* answer1 = DFA("asdfg/*asdfgh*/", statesTable, &isInComment);
	char* answer2 = DFA("asd/*asdfgh*/asd", statesTable, &isInComment);
	char* answer3 = DFA("asd/*asdfgh*/asd/*asdfgh*/", statesTable, &isInComment);
	char* answer4 = DFA("asdfgh", statesTable, &isInComment);
	bool result = strcmp(answer1, "/*asdfgh*/") + strcmp(answer2, "/*asdfgh*/") + strcmp(answer3, "/*asdfgh*//*asdfgh*/") + strcmp(answer4, "") == 0;
	free(answer1);
	free(answer2);
	free(answer3);
	free(answer4);
	deleteTable(statesTable);
	return result;
}