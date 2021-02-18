#include "List.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool testList()
{
	List* list = createList();
	append(list, 123);
	append(list, 431);
	append(list, 321);
	append(list, 213);
	append(list, 312);
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
	if (getValue(list, 3) != 123)
	{
		deleteList(&list);
		return false;
	}
	if (getValue(list, 0) != 312)
	{
		deleteList(&list);
		return false;
	}
	list = reversalList(list);
	if (getValue(list, 0) != 123)
	{
		deleteList(&list);
		return false;
	}
	if (getValue(list, 3) != 312)
	{
		deleteList(&list);
		return false;
	}
	deleteList(&list);
	return true;
}