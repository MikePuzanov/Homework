#include "Graph.h"
#include "GraphTest.h"

#include <stdbool.h>
#include <stdio.h>

bool graphTest()
{
	FILE* file = fopen("Test.txt", "r");
	int cities = 0;
	int roads = 0;
	fscanf(file, "%i %i", &cities, &roads);
	Graph* graph = createGraph(cities);
	for (int i = 0; i < roads; ++i)
	{
		int cityFirst = 0;
		int citySecond = 0;
		int len = 0;
		fscanf(file, "%i %i %i", &cityFirst, &citySecond, &len);
		fillGraph(graph, cityFirst - 1, citySecond - 1, len);
	}
	fclose(file);
	List* node = getList(graph, 2);
	if (getCity(node) != 0)
	{
		deleteGraph(&graph);
		return false;
	}
	int len = getLen(graph, 0, 1);
	if (getLen(graph, 0, 1) != 4 || getLen(graph, 2, 3) != 1)
	{
		deleteGraph(&graph);
		return false;
	}
	if (getCount(graph) != 4)
	{
		deleteGraph(&graph);
		return false;
	}
	deleteGraph(&graph);
	return true;
}