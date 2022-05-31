#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct stack
{
    char data[MAX];
    int top;
} Stack;

void setup(Stack *s)
{
    s->top = -1;    // Se inicializa en -1 por que no es un indice valido del arreglo
                    // Nos indica que la pila esta vacia
}

// regresa 1 si la pila esta vacia, 0 en caso contrario
int isEmpty(Stack stack)
{
    if(stack.top == -1)
        return 1;
    return 0;

    // return (stack.top == -1) ? 1 : 0;
    // return stack.top == -1;
}

int isFull(Stack stack)
{
    return stack.top == MAX-1;
}

//inserta un valor en la pila
// Regresa un 1 si pudo insertar y 0 si no
int push(Stack *s, char value)
{
    if (!isFull(*s))
    {
        s->top ++;
        s->data[s->top] = value;
        return 1;
    }
    return 0;
}

int pop(Stack *s, char *v)
{
    if (!isEmpty(*s))
    {
        *v = s->data[s->top];
        s->top --;
        return 1;
    }
    return 0;
}