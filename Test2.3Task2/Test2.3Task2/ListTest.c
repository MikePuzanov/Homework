#include "List.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test()
{
	List* list1 = createList();
	list1 = readFromFile(list1, "Test1.txt");
	if (getLenght(list1) != 5)
	{
		deleteList(&list1);
		return false;
	}
	if (!checkSymmetry(list1))
	{
		deleteList(&list1);
		return false;
	}
	if (isEmpty(list1))
	{
		deleteList(&list1);
		return false;
	}
	deleteList(&list1);
	List* list2 = createList();
	list2 = readFromFile(list2, "Test2.txt");
	if (getLenght(list2) != 6)
	{
		deleteList(&list2);
		return false;
	}
	if (checkSymmetry(list2))
	{
		deleteList(&list2);
		return false;
	}
	if (isEmpty(list2))
	{
		deleteList(&list2);
		return false;
	}
	deleteList(&list2);
	return true;
}