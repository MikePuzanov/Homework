#include "List.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main()
{
	if (!test())
	{
		return 1;
	}
	int size = 0;
	List* head = NULL;
	makeList(&head, "file.txt", &size);
	List* newHead = NULL;
	turnList(&head, &newHead);
	printList(newHead, size);
	if (!isEmpty(head))
	{
		deleteList(&head);
	}
	if (!isEmpty(newHead))
	{
		deleteList(&newHead);
	}
}