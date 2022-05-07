#include "stack.h"
#include "queue.h"
#include <string.h>

#define CIRCLE_SANDWICH 0
#define SQUARE_SANDWICH 1   

void sell_sandwiches(Cola *c, Stack *s);

int main()
{
    Stack stack;
    Cola cola;
    Estudiante estudiante;

    inicializaCola(&cola);
    setup(&stack);

    // Insertar los sandwich
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, SQUARE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);

    //formar a los estudiantes en la cola
    strcpy(estudiante.nombre, "juan");
    estudiante.sandwich = CIRCLE_SANDWICH;
    
    insertar(&cola, estudiante);

    strcpy(estudiante.nombre, "juan");
    estudiante.sandwich = CIRCLE_SANDWICH;

    insertar(&cola, estudiante);

    strcpy(estudiante.nombre, "pedro");
    estudiante.sandwich = CIRCLE_SANDWICH;

    insertar(&cola, estudiante);

    strcpy(estudiante.nombre, "angelica");
    estudiante.sandwich = SQUARE_SANDWICH;

    insertar(&cola, estudiante);

    sell_sandwiches(&cola, &stack);

    printf("Estudiantes");

    return 0;
}

void sell_sandwiches(Cola *c, Stack *s)
{
    Estudiante estudianteActual;
    int sandwichActual;

    while (estaVacia(*c) == 0)
    {
        eliminar(c, &estudianteActual);
        pop(s, &sandwichActual);

        printf("El estudiante %s quiere un sandwich: %d y en la pila hay %d", estudianteActual.nombre, estudianteActual.sandwich , sandwichActual);

        if (estudianteActual.sandwich != sandwichActual)
        {
            printf("\n\tNo se pudo entrgar, regresando el estudiante a la cola y el sandwich a la pila ");
            insertar(c, estudianteActual);
            push(s, sandwichActual);
        } else {
            printf("\n\tEl sandwich se entrego ");
        }
        printf("\n");
    }
}