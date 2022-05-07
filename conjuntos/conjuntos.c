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

void main()
{
    Set set;

    init_set(&set);
    add(&set, 10);
    add(&set, 1);
    add(&set, 14);
    add(&set, 5);
    add(&set, 14);
}

int add(Set *s, int value)
{
    int exists, result = 0;
    int i;

    //Si hay espacio y el valor no existe en el conjunto
    if (s->size < SET_CAPACITY)
    {
        //find es una funcion que busca el valor dentro del conjunto (Busqueda binaria)
        // Regresa 0 si no lo encontro y un 1 si lo encontro
        exists = find(*s, value);
        if (!exists) // exists == 0
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
            return 1;
            
        if (centerValue > value)
            end = center-1;
        else
            beginning = center + 1;
    }
    

    return 0;
}

void init_set(Set *s)
{
    s->size = 0; 
}