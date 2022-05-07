#include <stdio.h>
#define MAX 10 //capacidad de la cola

typedef struct colas
{
    int datos[MAX + 1];
    int inicio;
    int fin;
}Cola;

void inicializaCola(Cola *c); //encabezado
int estaVacia(Cola cola);
int estaLlena(Cola cola);
int insertar(Cola *c, int valor);
int eliminar(Cola *c, int *v);

int main()
{
    Cola cola;
    int r;
    int valor;

    inicializaCola(&cola);
    r = estaVacia(cola);

    printf("Valor de r: %d", r);

    r = insertar(&cola, 7);
    r = insertar(&cola, 3);
    r = insertar(&cola, 8);
    r = insertar(&cola, 5);
    r = insertar(&cola, 7);
    r = insertar(&cola, 3);

    r = eliminar(&cola, &valor);
    r = eliminar(&cola, &valor);
    r = eliminar(&cola, &valor);

    return 0;
}

int eliminar(Cola *c, int *v)
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

int insertar(Cola *c, int valor)
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

//  las operaciones basicas sobre la cola son:
//  1. inicializar - aseguramos que al inicio todo esta en orden para usarla
//  2. Saber cuando esta llena. si fin esta en una posicion antes que inicio entonces esta llena y debe regresar un 1 si lo esta o un 0 si no
//  3. Cuando esta vacia. si inicio es igual a fin entonces la cola esta vacia y debe regresar 1 y 0 en caso contrario
//  4. insertar (Enqueue). Regresar 1 si se pudo insertar y un 0 si no
//      4.1 Preguntar si hay espacio en la cola. que no este llena
//      4.2 inserto en la posicion que me dice fin
//      4.3 incrementa fin
//  5. Elimiar(Dequeue). Regresamos 1 si se pudo sacar de la cola o 0 si no
//      5.1 Preguntar si hay valores en la cola
//      5.2 Obtenemos el valor que esta en la posicion inicio
//      5.3 regresamos ese valor
//      5.4 Incrementamos inicio