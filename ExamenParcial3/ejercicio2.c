#include "stack.h"

int main()
{
    Stack stack;
    char cadena[MAX] = "Tercer Examen";
    char character;
    int longitud;

    setup(&stack);

    longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++)
    {
        push(&stack, cadena[i]);
    }
    
    while (!isEmpty(stack))
    {
        pop(&stack, &character);
        printf("%c", character);
    }
    
    return 0;
}