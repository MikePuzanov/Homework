#include "SortList.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!testTask())
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
			pushtoList(&head, element);
			break;
		case 2:
			printf("\nВведите значение, которое вы хотите удалить из списка - ");
			scanf("%i", &element);
			if (isEmpty(head))
			{
				printf("Список пуст!\n");
				break;
			}
			head = deleteNode(head, element);
			break;
		case 3:
			printList(head);
			break;
		default:
			printf("\nПопробуйте еще раз:)\n");
			break;
		}
	}
	deleteList(&head);
}