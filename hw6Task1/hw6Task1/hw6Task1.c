#include "../../hw6Node/hw6Node/List.h"
#include "../../hw6Node/hw6Node/ListTest.h"
#include "UsefullFunctionForList.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!testList() && !testTask())
	{
		printf("Тест не пройден!\n");
		return 1;
	}
	printf("Тест пройден!\n");
	printf("\n0 – выйти\n");
	printf("1 – добавить значение в сортированный список\n");
	printf("2 – удалить значение из списка\n");
	printf("3 – распечатать список\n");
	int key = -1;
	int element = 0;
	int min = 0;
	int max = 0;
	int max2 = 0;
	int min2 = 0;
	int size = 0;
	List* head = NULL;
	while (key != 0)
	{
		printf("\nВвведите цифру от 0 до 3 - ");
		scanf("%i", &key);
		switch (key)
		{
		case 0:
			printf("\nВыход.\n");
			break;
		case 1:
			printf("\nВведите значение, которое хотите добавить в список - ");
			scanf("%i", &element);
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
			printf("\nВведите значение, которое вы хотите удалить из списка - ");
			scanf("%i", &element);
			if (isEmpty(head))
			{
				printf("Список пуст!\n");
				break;
			}
			while (checkValue(head, element))
			{
				deleteNth(&head, findN(head, element) + 1);
				size--;
			}
			break;
		case 3:
			printList(head);
			break;
		default:
			printf("\nПопробуйте еще раз:)\n");
			break;
		}
	}
	if (!isEmpty(head))
	{
		deleteList(&head);
	}
	if (!isEmpty(head))
	{
		return 2;
	}
}