#include "Graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
	int** matrix;
	int count;
}Graph;

Graph* createGraph(const char* fileName[])
{
	Graph* newGraph = calloc(1, sizeof(Graph));
	if (newGraph == NULL)
	{
		return NULL;
	}
	FILE* file = fopen(fileName, "r");
	int count = 0; // количество вершин в графе
	fscanf(file, "%i\n", &count);
	newGraph->count = count;
	newGraph->matrix = calloc(count, sizeof(int*));
	for (int i = 0; i < count; ++i)
	{
		newGraph->matrix[i] = calloc(count, sizeof(int));
		for (int j = 0; j < count; ++j)
		{
			fscanf(file, "%i", &(newGraph->matrix[i][j]));
		}
	}
	fclose(file);
	return newGraph;
}

Graph* floyd(Graph* graph)
{
	for (int k = 0; k < graph->count; k++) {
		for (int i = 0; i < graph->count; i++) {
			for (int j = 0; j < graph->count; j++) {
				if (graph->matrix[i][j] <= graph->matrix[i][k] + graph->matrix[k][j])
				{
					graph->matrix[i][j] = graph->matrix[i][j];
				}
				else
				{
					graph->matrix[i][j] = graph->matrix[i][k] + graph->matrix[k][j];
				}
			}
		}
	}
	return graph;
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

void printGraph(Graph* graph, char fileName[])
{
	FILE* file = fopen(fileName, "w");
	for (int i = 0; i < graph->count; ++i)
	{
		for (int j = 0; j < graph->count; ++j)
		{
			fprintf(file, "%i ", graph->matrix[i][j]);
		}
		fprintf(file,"\n");
	}
}
