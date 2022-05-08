#include <stdio.h>
#include "stack.h"

void dataCapture(String *v);
void backSpace(Stack *s, int j);
int compareStrings(Stack string);

int main()
{
    Stack string;
    int out;
    String value;

    setup(&string);

    dataCapture(&value);
    push(&string, value);
    dataCapture(&value);
    push(&string, value);

    backSpace(&string, 0);
    backSpace(&string, 1);

    out = compareStrings(string);

    printf("%d", out);
    scanf("%d", out);

    return 0;
}

int compareStrings(Stack string)
{
    int i, r = 1;
    while (string.data[0].string[i] != string.data[1].string[i])
    {
        r = 0;
    }
    return r;
}

void backSpace(Stack *s, int j)
{
    for (int i = 0; i < N; i++)
    {
        if (s->data[j].string[i] == "#")
        {
            s->data[j].string[i-1] = s->data[j].string[i+1];

            for (int k = i; k < N-2; k++)
            {
                s->data[j].string[k] = s->data[j].string[k+2];
            }
        }   
    }
}

void dataCapture(String *v)
{
    printf("Introduzca los datos: ");
    scanf("%s",v->string);
}