#pragma once

// структура
typedef struct Graph Graph;

// создание графа 
Graph* createGraph(int count);

// для заполнения графа
void fillGraph(Graph* graph, int i, int j, int distance);

// получить кол-во вершин
int getCount(Graph* graph);

// получить длину между городами
int getLen(Graph* graph, int i, int j);

// удаления графа
void deleteGraph(Graph** graph);