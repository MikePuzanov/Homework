#include "List.h"
#include "BuildCounties.h"
#include "ListTest.h"
#include "TaskTest.h"
#include "GraphTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	if (!testList() || !taskTest() || !graphTest())
	{
		printf("Тесты не пройдены!");
		return 5;
	}
	printf("Тесты пройдены!\n\n");
	int countOfCountries = 0;
	List** countries = countriesDesigner("task.txt", &countOfCountries);
	for (int i = 0; i < countOfCountries; i++)
	{
		printf("Государство %i\n", i + 1);
		List* capital = getLast(countries[i]);
		int city = getCity(capital);
		printf("Cтолица: %i\n", city + 1);
		printf("Состав: ");
		List* node = countries[i];
		while (node)
		{
			city = getCity(node);
			printf("%i ", city + 1);
			node = getNextNode(node);
		}
		printf("\n\n");
	}
	for (int i = 0; i < countOfCountries; i++)
	{
		deleteList(&countries[i]);
	}
	free(countries);
}