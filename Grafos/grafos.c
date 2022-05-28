/*
Grafos
Estructura de datos compleja
- Vertices - Elemntos que queremos relacionar
- Aristas - Indican cuando un elemento está relacionado con varios elemntos

Dos tipos de grafos:

- Dirigidos - Sus aristas tienen direcciones
- No Dirigido - Sus aristas son bidireccionales

    OPERACIONES
    - Inicializar
    - Insertar vertices
    - Insertar aristas (edges) / relaciones
    - Eliminar vertices
    - Eliminar relaciones
    - Si existe una relacion entre dos vertices
    - Imprimir formato de tabla
    - Dos tipos de recorrido:
        - Recorrido en pronfundidad
        - Recorrido en amplitud
*/

#include <stdio.h>
#include <string.h>
#include "queue.h"

#define GRAPH_CAPACITY 32

typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int flag[GRAPH_CAPACITY];
    int size;
}Graph;

void initGraph(Graph *g);
int addVertice(Graph *g, char vertice[20]);
int findVertice(Graph graph, char vertice[20]);
int addEdge(Graph *g, char verticeSource[20], char verticeDestiny[20]);
void printGraph(Graph graph);
int deleteVertice(Graph *g, char vertice[20]);  //  Recorre el espacio del vertice que se elimino y mover los demas tanto en la lista de vertices como en las aristas
int deleteEdge(Graph *g, char verticeSource[20], char verticeDestiny[20]);
int areRelated(Graph graph, char verticeSource[20], char verticeDestiny[20]);
void bfs(Graph *g, char vertice[50]);

int main()
{
    Graph graph;
    int relacion;

    initGraph(&graph);

    addVertice(&graph, "San Luis Potosi");
    addVertice(&graph, "Querétaro");
    addVertice(&graph, "Nuevo Leon");
    addVertice(&graph, "Jalisco");
    addVertice(&graph, "Tamaulipas");

    for (int i = 0; i < graph.size; i++)
    {
        for (int j = i; j < graph.size; j++)
        {
            printf("%s tinen relacion con %s? (1 - si, 0 - no) ", graph.vertices[i], graph.vertices[j]);
            scanf("%d", &relacion);

            if (relacion == 1)
                addEdge(&graph, graph.vertices[i], graph.vertices[j]);
        }
        
    }

    deleteVertice(&graph, "Jalisco");

    printGraph(graph);

    if (areRelated(graph, "San Luis Potosi", "Tamaulipas") == 1)
        printf("Si estan relacionados san luis y tamaulipas");
    else
        printf("No estan relacionados san luis y tamaulipas");

    return 0;
}

void initGraph(Graph *g)
{
    g->size = 0;

    for (int i = 0; i < GRAPH_CAPACITY; i++)
    {
        g->flag[i] = 0;
    }
}

int addVertice(Graph *g, char vertice[20])
{
    //posibles validaciones:
    //  1. revisar que exista espacio
    //  2. Revisar que el vertice no exista

    int exist = findVertice(*g, vertice);

    if (g->size < GRAPH_CAPACITY && exist == -1){
        //Deberia validar que el vertice no exista
        strcpy(g->vertices[g->size], vertice);

        for (int i = 0; i < g->size+1; i++)
        {
            g->edges[i][g->size] = 0;
        }

        for (int i = 0; i < g->size; i++)
        {
            g->edges[g->size][i] = 0;
        }
        
        g->size++;

    }
}

int findVertice(Graph graph, char vertice[20])
{
    int i;
    int result = -1; // que el valor no va a estar en el arreglo

    for (i = 0; i < graph.size && result == -1; i++)
    {
        if (strcmp(graph.vertices[i], vertice) == 0)
            result = i;
    }
    return result;
}

int addEdge(Graph *g, char verticeSource[20], char verticeDestiny[20])
{
    int posSource = findVertice(*g, verticeSource);
    int posDestiny = findVertice(*g, verticeDestiny);

    if (posSource != -1 && posDestiny != -1) //Encontró los dos vertices
    {
        g->edges[posSource][posDestiny] = 1;
        g->edges[posDestiny][posSource] = 1;

        return 1;
    }
    return 0;
}

void printGraph(Graph graph)
{
    printf("\t\t");
    for (int i = 0; i < graph.size; i++)
    {
        printf("%s\t", graph.vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < graph.size; i++)
    {
        printf("%s\t", graph.vertices[i]);
        for (int j = 0; j < graph.size; j++)
        {
            printf("%d\t\t", graph.edges[i][j]);
        }
        printf("\n");
    }
}

int deleteVertice(Graph *g, char vertice[20])
{
    //  Recorre el espacio del vertice que se elimino y mover los demas tanto en la lista de vertices como en las aristas
    //  Validaciones:
    //  1. revisar que no este vacío
    //  2. Revisar que el vertice exista

    int exist = findVertice(*g, vertice);

    if (g->size > 0 && exist != -1) //  Valida que exista el vertice y que tenga contenido el grafo
    {
        for (int i = exist; i < g->size-1; i++)
        {
            strcpy(g->vertices[i], g->vertices[i+1]);
        }
        for (int i = 0; i < g->size; i++)
        {
            g->edges[i][exist] = g->edges[i][exist+1];
        }
        for (int i = 0; i < g->size; i++)
        {            
            g->edges[exist][i] = g->edges[exist+1][i];
        }
        
        g->size--;
        return 1;
    }
    return 0;
}

int deleteEdge(Graph *g, char verticeSource[20], char verticeDestiny[20])
{
    int posSource = findVertice(*g, verticeSource);
    int posDestiny = findVertice(*g, verticeDestiny);

    if (posSource != -1 && posDestiny != -1) //Encontró los dos vertices
    {
        g->edges[posSource][posDestiny] = 0;
        g->edges[posDestiny][posSource] = 0;

        return 1;
    }
    return 0;
}

int areRelated(Graph graph, char verticeSource[20], char verticeDestiny[20])
{
    int posSource = findVertice(graph, verticeSource);
    int posDestiny = findVertice(graph, verticeDestiny);

    if (posSource != -1 && posDestiny != -1) //Encontró los dos vertices
        if (graph.edges[posSource][posDestiny] == 1 && graph.edges[posDestiny][posSource] == 1)
            return 1;
    return 0;
}

// Recorrido en amplitud BFS - Breath Fisrt Search
void bfs(Graph *g, char vertice[50])
{
    Cola colaVertice;
    int posVertice = findVertice(*g, vertice);
    char verticeActual[50];

    inicializaCola(&colaVertice);

    g->flag[posVertice] = 1; //  Marcando el vertice como visitado
    insertar(&colaVertice, vertice);

    while (!estaVacia(colaVertice))
    {
        eliminar(&colaVertice, verticeActual);
        posVertice = findVertice(*g, verticeActual);
        printf("%s ", verticeActual);

        //  Meter las relaciones de ese vertice
        for (int i = 0; i < g->size; i++)
        {
            if (posVertice != i && g->edges[posVertice][i] == 1 && g->flag[i] == 0)
            {
                g->flag[i] = 1;
                insertar(&colaVertice, g->vertices[i]);
            }
        }
    }
}