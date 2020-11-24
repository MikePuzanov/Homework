#pragma once

// структура
typedef struct Graph Graph;

// создание графа
Graph* createGraph(const char* fileName[]);

// алгоритм флойда
Graph* floyd(Graph* graph);

//удаление графа
void deleteGraph(Graph** graph);

// печать графа в файл
void printGraph(Graph* graph, char file[]);