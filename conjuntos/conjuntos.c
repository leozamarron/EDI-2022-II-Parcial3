// set - conjunto
/*
1.- Grupo de elementos que no se repiten
2. operaciones
    2.1 Agregar al conjunto - verificar que el elemento no exita dentro del conjunto - Si hay esoacio
    2.2 Eliminar un elemento de un conjunto - Exista - Elimina
    2.3 Pertenencia - Elemento X pertenece al conjunto
3. Operaciones entre conjuntos. Dado 2 conjuntos
    3.1 Calcular su interseccion - Valores comunes a los 2 conjuntos
    3.2 Union - Todos los elementos de A + Todos los elementos de B sin repetirlos
    3.3 Complemento - Complemento de A. Todos los elemntos que no pertenezcan a A
    3.4 Diferencia - A - B. Todo lo que este en A que no este en B
*/

#include <stdio.h>

#define SET_CAPACITY 10

typedef struct set
{
    int data[SET_CAPACITY];
    int size; //Cuantos elementos de han intersetado en el conjunto
} Set;

void init_set(Set *s);
int add(Set *s, int value);
int find(Set set, int value);
int removeSet(Set *s, int value);
int exist(Set set, int value);
int removeFirst(Set *s, int *v);
int removeLast(Set *s, int *v);
void junction(Set setA, Set setB, Set *sC);
void intersect(Set setA, Set setB, Set *sC);
void complement(Set setA, Set setB, Set *sC);
void difference(Set setA, Set setB, Set *sC);

void main()
{
    Set setA;
    Set setB;
    Set setC;
    int value;

    init_set(&setA);
    add(&setA, 23);
    add(&setA, 11);
    add(&setA, 16);
    add(&setA, 5);
    add(&setA, 7);

    init_set(&setB);
    add(&setB, 10);
    add(&setB, 11);
    add(&setB, 21);
    add(&setB, 5);

    printf("La interseccion del conjunto A y B es: \n");
    init_set(&setC);
    intersect(setA, setB, &setC);
    printSet(setC);

    printf("La union del conjunto A y B es: \n");
    init_set(&setC);
    junction(setA, setB, &setC);
    printSet(setC);

    printf("El complemento del conjunto A es: \n");
    init_set(&setC);
    complement(setA, setB, &setC);
    printSet(setC);

    printf("El complemento del conjunto B es: \n");
    init_set(&setC);
    complement(setB, setA, &setC);
    printSet(setC);

    printf("La diferencia del conjunto A - B es: \n");
    init_set(&setC);
    difference(setA, setB, &setC);
    printSet(setC);

    printf("La diferencia del conjunto B - A es: \n");
    init_set(&setC);
    difference(setB, setA, &setC);
    printSet(setC);

//    removeSet(&setA, 1);

//    exist(setA, 5); //0
//    exist(setA, 10); //1
    
//    removeFirst(&setA, &value);
//    removeLast(&setA, &value);

}

void printSet(Set set)
{
    printf("[");
    for (int i = 0; i < set.size; i++)
    {
        printf(" %d", set.data[i]);
    }
    printf(" ]\n");
}

void difference(Set setA, Set setB, Set *sC)
{
    int e;
    for (int i = 0; i < setA.size; i++)
    {
        e = exist(setB, setA.data[i]);
        if (e==0)
        {
            add(sC, setA.data[i]);
        }
    }
}

void complement(Set setA, Set setB, Set *sC)
{
    int e;
    for (int i = 0; i < setB.size; i++)
    {
        e = exist(setB, setA.data[i]);
        if (e==0)
        {
            add(sC, setB.data[i]);
        }
    }
}

void junction(Set setA, Set setB, Set *sC)
{
    intersect(setA, setB, sC);
    complement(setA, setB, sC);
    difference(setA, setB, sC);
}

void intersect(Set setA, Set setB, Set *sC)
{
    int e;
    for (int i = 0; i < setA.size; i++)
    {
        e = exist(setB, setA.data[i]);
        if (e==1)
        {
            add(sC, setA.data[i]);
        }
    }
}

int exist(Set set, int value)
{
    int i = find(set, value);

    if (i == -1)
        return 0; // No existe
    return 1;
}

int add(Set *s, int value)
{
    int exists, result = 0;
    int i;

    //Si hay espacio y el valor no existe en el conjunto
    if (s->size < SET_CAPACITY)
    {
        //find es una funcion que busca el valor dentro del conjunto (Busqueda binaria)
        // Regresa -1 si no lo encontro y la posicion si lo encontro
        exists = find(*s, value);
        if (exists == -1) // si no existe
        {
            // insertar el valor en el arreglo de forma ordenada
            // Vamos a empezar a revisar desde la posicion size-1 mientras el valor que este en la posicion
            // sea maypr que voy a insertar -> lo recorre

            for (i = s->size-1; i >= 0 && s->data[i] > value; i--)
            {
                s->data[i+1] = s->data[i];
            }
            s->data[i+1] = value;
            s->size++;
            result = 1;
        }
    }

    return result;
}

int find(Set set, int value)
{
    // Esta funcion debe de buscar el valor value dentro
    // del arreglo set.data y regresar 0 si no lo encontro y 1 si si lo encontro
    // usando búsqueda binaria
    int beginning = 0;
    int end = set.size-1;
    int center; 
    int centerValue;

    while (beginning <= end)
    {
        center = (beginning + end)/2;
        centerValue = set.data[center];

        if(value == centerValue)
            return center;
            
        if (centerValue > value)
            end = center-1;
        else
            beginning = center + 1;
    }
    

    return -1;
}

void init_set(Set *s)
{
    s->size = 0; 
}

int removeSet(Set *s, int value)
{
    //find regresa -1 y la posicion si es que se encuentra
    int i = find(*s, value);

    if (i != -1)
    {
        s->size--;
        for (; i < s->size ; i++)
        {
            s->data[i] = s->data[i+1];
        }
        return 1;
    }
    return 0;
}

int removeFirst(Set *s, int *v)
{
    if (s->size != 0)
    {
        s->size--;
        for (int i = 0; i < s->size ; i++)
        {
            s->data[i] = s->data[i+1];
        }
        return 1;
    }
    return 0;
}

int removeLast(Set *s, int *v)
{
    if (s->size != 0)
    {
        s->size--;
        return 1;
    }
    return 0;
}