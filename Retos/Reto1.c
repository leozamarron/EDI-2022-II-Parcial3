#include <stdio.h>

#define MAX 10

typedef struct stack
{
    int data[MAX];
    int top;
} Stack;

void setup(Stack *s);
int isEmpty(Stack stack);
int isFull(Stack stack);
int push(Stack *s, int value);
int pop(Stack *s, int *v);

int main()
{
    Stack stack;

    setup(&stack);

    int r;
    int value;

    r = push(&stack, 5);
    r = push(&stack, 6);
    r = push(&stack, 8);
    r = push(&stack, 23);
    r = push(&stack, 56);
    r = push(&stack, 87);
    r = push(&stack, 12);
    r = push(&stack, 23);
    r = push(&stack, 54);
    r = push(&stack, 10);

    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);

    return 0;
}

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
int push(Stack *s, int value)
{
    if (!isFull(*s))
    {
        s->top ++;
        s->data[s->top] = value;
        return 1;
    }
    return 0;
}

int pop(Stack *s, int *v)
{
    if (!isEmpty(*s))
    {
        *v = s->data[s->top];
        s->top --;
        return 1;
    }
    return 0;
}