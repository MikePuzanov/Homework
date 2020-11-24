#include "Graph.h"

#include <stdio.h>

int main()
{
    Graph* graph = createGraph("GraphFile.txt");
    printf("\n");
    graph = floyd(graph);
    printGraph(graph, "Answer.txt");
}