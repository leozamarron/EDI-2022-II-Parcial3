#include <stdio.h>
#include <string.h>

#define MAX 100 //capacidad de la cola

typedef struct colas
{
    char datos[MAX + 1][50];
    int inicio;
    int fin;
}Cola;

#define GRAPH_CAPACITY 32

typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int flag[GRAPH_CAPACITY];
    int size;
}Graph;

//-------------------------------------------------------//
//-------------------------Pilas------------------------//
//-------------------------------------------------------//

int eliminar(Cola *c, char valor[50])
{
    int r = 0;
    if (!estaVacia(*c))
    {
        strcpy(valor, c->datos[c->inicio]);
        c->inicio = (c->inicio + 1) % (MAX+1);
        r = 1;
    }
    return r;
}

int insertar(Cola *c, char valor[50])
{
    int r = 0;

    if (estaLlena(*c) == 0) //Hay espacio para insertar, la cola no esta llena
    {
        //  Poner el valor dentro del arreglo dentro dentro de la posicion que dice fin
        strcpy(c->datos[c->fin], valor);
        //  Mover fin a la siguiente casilla libre
        c->fin = (c->fin + 1) % (MAX+1);
        r = 1;
    }

    return r;
}

int estaLlena(Cola cola)
{
    if (cola.inicio == cola.fin + 1 || (cola.inicio == 0 && cola.fin == MAX))
    {
        return 1;
    }
    return 0;
}

int estaVacia(Cola cola)
{
    if(cola.inicio == cola.fin)
    {
        return 1;
    }
    return 0;
}

void inicializaCola(Cola *c)
{
    c->inicio = 0;
    c->fin = 0;
}

//-------------------------------------------------------//
//-------------------------Grafos------------------------//
//-------------------------------------------------------//

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