#include "Graph.h"

#include <stdio.h>

int main()
{
    Graph* graph = createGraph("GraphFile.txt");
    printGraph(graph);
    printf("\n");
    graph = floyd(graph);
    printGraph(graph);
}