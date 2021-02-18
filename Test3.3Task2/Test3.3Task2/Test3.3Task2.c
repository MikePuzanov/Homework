#include "List.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!testList())
	{
		printf("Тест не пройден!\n");
		return 5;
	}
	printf("Тест пройден!\n");
	List* list = createList();
	int size = 0;
	int min = 0;
	int max = 0;
	printf("\nМеню:\n");
	printf("0 — выйти\n");
	printf("1 — заполнить список случайными значениями(размер списка и диапазон значений задаются с консоли\n");
	printf("2 — развернуть список\n");
	printf("3 — распечатать список\n");
	while (true)
	{
		int key = -1;
		printf("\nВведите ключ дейсвтия - ");
		scanf("%i", &key);
		switch (key)
		{
		case 0:
			deleteList(&list);
			return 0;
		break;
		case 1:
			printf("Введите размер списка - ");
			scanf("%i", &size);
			printf("Введите минмальное значений - ");
			scanf("%i", &min);
			printf("Введите максимальное значений - ");
			scanf("%i", &max);
			for (int i = 0; i < size; ++i)
			{
				append(list, rand() % (max + abs(min)) - min);
			}
		break;
		case 2:
			list = reversalList(list);
		break;
		case 3:
			printList(list);
		break;
		default:
			printf("\nВведите ключ действия заново!\n");
		break;
		}
	}
}