#include "Graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
	int** matrix;
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
	newGraph->matrix = calloc(count, sizeof(int*));
	for (int i = 0; i < count; ++i)
	{
		newGraph->matrix[i] = calloc(count, sizeof(int));
	}
	return newGraph;
}

void fillGraph(Graph* graph, int i, int j, int len)
{
	graph->matrix[i][j] = len;
	graph->matrix[j][i] = len;
}

int getCount(Graph* graph)
{
	return graph->count;
}

int getLen(Graph* graph, int i, int j)
{
	if (j < 0 || j > graph->count || i < 0 || i > graph->count)
	{
		return -1;
	}
	return graph->matrix[i][j];
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->count; ++i)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}