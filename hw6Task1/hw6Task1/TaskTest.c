#include "TaskTest.h"
#include "UsefullFunctionForList.h"
#include "../../hw6Node/hw6Node/List.h"

#include <stdio.h>
#include <stdbool.h>

bool testTask()
{
	List* head = NULL;
	int array[11] = { 1, 5, 1, 10, 1, 7, 1, 8, 2, 7, 0 };
	int size = 0;
	int element = 0;
	int min = 0;
	int max = 0;
	for (int i = 0; i < 11; ++i)
	{
		int key = 1;
		while (key != 0)
		{
			key = array[i];
			switch (key)
			{
			case 0:
				break;
			case 1:
				element = array[i + 1];
				size++;
				if (size == 1)
				{
					min = element;
					max = element;
					push(&head, element);
					break;
				}
				if (element < min)
				{
					min = element;
					push(&head, element);
					break;
				}
				if (element > max)
				{
					max = element;
					pushBack(head, element);
					break;
				}
				insert(head, findN(head, element), element);
				break;
			case 2:
				element = array[i + 1];
				if (isEmpty(head))
				{
					break;
				}
				while (checkValue(head, element))
				{
					deleteNth(&head, findN(head, element) + 1);
					size--;
				}
				break;
			case 3:
				break;
			}
		}
	}
	int previos = pop(&head);
	for (int i = 1; i < 4; ++i)
	{
		int now = pop(&head);
		if (now < previos || now == 7)
		{
			return false;
		}
		previos = now;
	}
	int arraySecond[13] = { 1, 5, 1, 15, 1, 8, 1, 7, 1, 7, 2, 7, 0 };
	for (int i = 0; i < 13; ++i)
	{
		int key = 1;
		while (key != 0)
		{
			key = array[i];
			switch (key)
			{
			case 0:
				break;
			case 1:
				element = array[i + 1];
				size++;
				if (size == 1)
				{
					min = element;
					max = element;
					push(&head, element);
					break;
				}
				if (element < min)
				{
					min = element;
					push(&head, element);
					break;
				}
				if (element > max)
				{
					max = element;
					pushBack(head, element);
					break;
				}
				insert(head, findN(head, element), element);
				break;
			case 2:
				element = array[i + 1];
				if (isEmpty(head))
				{
					break;
				}
				while (checkValue(head, element))
				{
					deleteNth(&head, findN(head, element) + 1);
					size--;
				}
				break;
			case 3:
				break;
			}
		}
	}
	previos = pop(&head);
	for (int i = 1; i < 4; ++i)
	{
		int now = pop(&head);
		if (now < previos || now == 7)
		{
			return false;
		}
		previos = now;
	}
	return true;
}