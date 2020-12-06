#include "List.h"
#include "BuildCounties.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	if (!testList())
	{
		return 5;
	}
	List** countries = countriesDesigner("task.txt");
	int countOfCountries = 2;
	for (int i = 0; i < countOfCountries; i++)
	{
		printf("Государство %i", i + 1);
		printf("\n");
		int city = getCity(countries[i]);
		printf("Cтолица: %i", city + 1);
		printf("\n");
		printf("Состав: ");
		List* node = countries[i];
		while (node)
		{
			city = getCity(node);
			printf("%i ", city + 1);
			node = getNextNode(node);
		}
		printf("\n");
		printf("\n");
	}
	for (int i = 0; i < countOfCountries; i++)
	{
		deleteList(&countries[i]);
	}
	free(countries);
}