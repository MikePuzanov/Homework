#include "PriorityQueue.h"
#include "Test.h"

#include <stdio.h>
#include <stdbool.h>

bool test()
{
	PriorityQueue* head = NULL;
	int size = 0;
	int array[16] = { 1, 1, 2, 2, 5, 5, 3, 3, 4, 4, 5, 5, 4, 4, 2, 2 };
	for (int i = 0; i < 16; i += 2)
	{
		enqueue(&head, array[i], array[i + 1]);
	}
	if (findMaxPriority(head) != 5)
	{
		deletePriorityQueue(&head);
		return false;
	}
	if (dequeue(&head, findMaxPriority(head)) != 5)
	{
		deletePriorityQueue(&head);
		return false;
	}
	dequeue(&head, findMaxPriority(head));
	if (findMaxPriority(head) != 4)
	{
		deletePriorityQueue(&head);
		return false;
	}
	if (dequeue(&head, findMaxPriority(head)) != 4)
	{
		deletePriorityQueue(&head);
		return false;
	}
	for (int i = 0; i < 5; ++i)
	{
		dequeue(&head, findMaxPriority(head));
	}
	if (dequeue(&head, findMaxPriority(head)) != -1)
	{
		deletePriorityQueue(&head);
		return false;
	}
	enqueue(&head, 1, 1);
	if (isEmpty(head))
	{
		deletePriorityQueue(&head);
		return false;
	}
	deletePriorityQueue(&head);
	return isEmpty(head);
}