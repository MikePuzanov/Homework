#include "Graph.h"
#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
	List** matrix;
	int count;
}Graph;

Graph* createGraph(int count)
{
	Graph* newGraph = calloc(1, sizeof(Graph));
	if (newGraph == NULL)
	{
		return NULL;
	}
	newGraph->count = count;
	newGraph->matrix = calloc(count, sizeof(List*));
	return newGraph;
}

List* getList(Graph* graph, int i)
{
	return graph->matrix[i];
}

void fillGraph(Graph* graph, int i, int j, int len)
{
	append(graph->matrix[i], j, len);
	append(graph->matrix[j], i, len);
}

int getCount(Graph* graph)
{
	return graph->count;
}

int getLen(Graph* graph, int i, int j)
{
	List* node = graph->matrix[i];
	while (getCity(node) != j && node)
	{
		node = getNextNode(node);
	}
	return node ? getRoadLength(node) : 0;
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->count; ++i)
	{
		deleteList(&(*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}