#include "List.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool testList()
{
	List* list = createList();
	append(list, "Abc");
	append(list, "aBc");
	append(list, "abC");
	append(list, "yzx");
	append(list, "Yzx");
	append(list, "Yzx");
	append(list, "Yzx");
	if (getLength(list) != 5)
	{
		deleteList(&list);
		return false;
	}
	deleteNode(list, 3);
	if (getLength(list) != 4)
	{
		deleteList(&list);
		return false;
	}
	if (strcmp(getWord(list, 2), "abC") != 0)
	{
		deleteList(&list);
		return false;
	}
	if (getFrequency(list, 0) != 3)
	{
		deleteList(&list);
		return false;
	}
	deleteList(&list);
	return true;
}