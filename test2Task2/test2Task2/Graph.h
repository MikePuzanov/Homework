#pragma once

typedef struct Graph Graph;

Graph* createGraph(const char* fileName[]);

Graph* floyd(Graph* graph);

void deleteGraph(Graph** graph);

void printGraph(Graph* graph, char file[]);