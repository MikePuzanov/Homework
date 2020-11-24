#pragma once

#include "../../Queue/Queue/Queue.h"

typedef struct Graph Graph;

Graph* createGraph(const char* fileName[]);

Graph* floyd(Graph* graph);

void deleteGraph(Graph** graph);

void printGraph(Graph* graph);