#include <stdio.h>
#include <string.h>
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
    out = push(&string, value);
    dataCapture(&value);
    out = push(&string, value);

    backSpace(&string, 0);
    backSpace(&string, 1);

    out = compareStrings(string);

    printf("%d", out);

    return 0;
}

int compareStrings(Stack string)
{
    int i = 0;
    int r = 0;
    while ((string.data[0].string[i] == string.data[1].string[i]) && (i < strlen(string.data[0].string)))
    {
        r = 1;
        i++;
    }
    if(string.data[0].string[i] != string.data[1].string[i])
        r = 0;

    return r;
}

void backSpace(Stack *s, int j)
{
    int limit = strlen(s->data[j].string);

    for (int i = 0; i < limit; i++)
    {
        if (s->data[j].string[0] == *"#")
        {
            for (int k = 0; k < limit; k++)
            {
                s->data[j].string[k] = s->data[j].string[k+1];
            }
        }
        else if (s->data[j].string[i] == *"#")
        {
            s->data[j].string[i-1] = s->data[j].string[i+1];

            for (int k = i; k < limit-1; k++)
            {
                s->data[j].string[k] = s->data[j].string[k+2];
            }
        }
    }
}

void dataCapture(String *v)
{
    printf("Introduzca los datos: ");
    scanf("%s", &v->string);
}