#include <stdio.h>
#include "common.h"

typedef struct estudiante {
    char nombre[50];
    int sandwich;
}Estudiante;

typedef struct Colas
{
    Estudiante datos[MAX + 1];
    int inicio;
    int fin;
}Cola;

int eliminar(Cola *c, Estudiante *v)
{
    int r = 0;
    if (!estaVacia(*c))
    {
        *v = c->datos[c->inicio];
        c->inicio = (c->inicio + 1) % (MAX+1);
        r = 1;
    }
    return r;
}

int insertar(Cola *c, Estudiante valor)
{
    int r = 0;

    if (estaLlena(*c) == 0) //Hay espacio para insertar, la cola no esta llena
    {
        //  Poner el valor dentro del arreglo dentro dentro de la posicion que dice fin
        c->datos[c->fin] = valor;
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