#include "PriorityQueue.h"
#include "Test.h"

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!test())
	{
		printf("Тест не пройден!\n");
		return 5;
	}
	printf("Тест пройден!\n");
	PriorityQueue* head = NULL;
	int size = 0;
	printf("Введите количество вводимых элементов -");
	scanf("%i", &size);
	printf("\nВведите значение и приоритет:\n");
	int priority = 0;
	for (int i = 0; i < size; ++i)
	{
		int value = 0;
		scanf("%i %i", &value, &priority);
		enqueue(&head, value, priority);
	}
	priority = findMaxPriority(head);
	printf("Элемент или элементы с самым большим приоритетом, которые удалили - ");
	while (priority == findMaxPriority(head))
	{
		printf("%i ", dequeue(&head, priority));
	}
}