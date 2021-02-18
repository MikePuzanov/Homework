#include "BuildCounties.h"
#include "Graph.h"
#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool addCity(Graph* graph, List** list, int country, bool isCityInCountry[])
{
	int minLen = INT_MAX;
	int idSwapCity = -1;
	List* town = list[country];
	while (town)
	{
		int checkCity = getCity(town);
		List* roads = getList(graph, checkCity);
		while (roads)
		{
			int id = getCity(roads);
			int len = getRoadLength(roads, );
			if (!isCityInCountry[id] && len > 0 && len < minLen)
			{
				minLen = len;
				idSwapCity = id;
			}
			roads = getNextNode(roads);
		}
		town = getNextNode(town);
	}
	if (idSwapCity != -1)
	{
		push(&list[country], idSwapCity, 0);
		isCityInCountry[idSwapCity] = true;
	}
	return idSwapCity != -1;
}

void fillCountries(Graph* graph, List** list, int countries, bool isCityInCountry[], int freeCities)
{
	int countCounties = 0;
	while (freeCities > 0)
	{
		if (addCity(graph, list, countCounties, isCityInCountry))
		{
			freeCities--;
 		}
		countCounties = (countCounties + 1) % countries;
	}
}

List** designCountries(char fileName[], int* countries)
{
	FILE* file = fopen(fileName, "r");
	int cities = 0;
	int roads = 0;
	fscanf(file, "%i %i", &cities, &roads);
	bool* isCityInCountry = calloc(cities, sizeof(bool));
	Graph* graph = createGraph(cities);
	for (int i = 0; i < roads; ++i)
	{
		int cityFirst = 0;
		int citySecond = 0;
		int len = 0;
		fscanf(file, "%i %i %i", &cityFirst, &citySecond, &len);
		fillGraph(graph, cityFirst - 1, citySecond - 1, len);
	}
	fscanf(file, "%i", &(*countries));
	List** list = calloc(*countries, sizeof(List*));
	for (int i = 0; i < *countries; ++i)
	{
		list[i] = createList();
		int capital = 0;
		fscanf(file, "%i", &capital);
		append(list[i], capital - 1, 0);
		isCityInCountry[capital - 1] = true;
	}
	fclose(file);
	fillCountries(graph, list, *countries, isCityInCountry, cities - *countries);
	free(isCityInCountry);
	deleteGraph(&graph);
	return list;
}