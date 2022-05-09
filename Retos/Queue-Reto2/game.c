#include <stdio.h>
#include "queue.h"

int playersData(Cola *queue);
int theGame(Cola *queue, int v, int c);

int main()
{
    Cola queue;
    int v;
    int count;

    inicializaCola(&queue);

    count = playersData(&queue);

    printf("Dame un numero k para el contador: ");
    scanf("%d", &v);

    theGame(&queue, v, count);
    

    printf("El ganador es: %d", queue.datos[queue.inicio]);

    return 0;
}

int theGame(Cola *queue, int v, int c)
{
    int value = v;
    if (queue->fin == (queue->inicio + 1) % (MAX+1))
        return queue->inicio;

    while (c != 1)
    {
        value = eliminar(queue, v);
        c--;
    }
}

int playersData(Cola *queue)
{
    int gamerNumbers;
    int count = 1;

    printf("Dame el numero de jugadores: ");
    scanf("%d", &gamerNumbers);

    insertar(queue, gamerNumbers);

    for (int i = 1; i < gamerNumbers; i++)
    {
        insertar(queue, i);
        count++;
    }
    return count;
}