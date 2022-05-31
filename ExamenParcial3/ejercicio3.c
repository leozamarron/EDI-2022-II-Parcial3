#include "BFS.h"

int main()
{
    Graph graph;

    initGraph(&graph);

    addVertice(&graph, "A");
    addVertice(&graph, "B");
    addVertice(&graph, "C");
    addVertice(&graph, "D");
    addVertice(&graph, "E");
    addVertice(&graph, "F");
    addVertice(&graph, "G");
    addVertice(&graph, "H");
    // Vertices de A
    addEdge(&graph, graph.vertices[0], graph.vertices[1]);
    addEdge(&graph, graph.vertices[0], graph.vertices[3]);
    addEdge(&graph, graph.vertices[0], graph.vertices[4]);
    addEdge(&graph, graph.vertices[0], graph.vertices[6]);
    // Vertices de B
    addEdge(&graph, graph.vertices[1], graph.vertices[0]);
    addEdge(&graph, graph.vertices[1], graph.vertices[2]);
    addEdge(&graph, graph.vertices[1], graph.vertices[4]);
    // Vertices de C
    addEdge(&graph, graph.vertices[2], graph.vertices[1]);
    // Vertices de D
    addEdge(&graph, graph.vertices[3], graph.vertices[0]);
    addEdge(&graph, graph.vertices[3], graph.vertices[7]);
    // Vertices de E
    addEdge(&graph, graph.vertices[4], graph.vertices[0]);
    addEdge(&graph, graph.vertices[4], graph.vertices[1]);
    // Verices de F - ninguno
    // Vertices de G
    addEdge(&graph, graph.vertices[6], graph.vertices[0]);
    addEdge(&graph, graph.vertices[6], graph.vertices[7]);
    // Vertices de H
    addEdge(&graph, graph.vertices[7], graph.vertices[3]);
    addEdge(&graph, graph.vertices[7], graph.vertices[6]);

    bfs(&graph, "A");
}