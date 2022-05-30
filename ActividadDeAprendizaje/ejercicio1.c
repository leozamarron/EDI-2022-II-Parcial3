#include "stack.h"

int recursividad(int M, int N, int w[M][N], Robot robot, Stack *s);
void printStack(Stack s);

int main()
{
    FILE *archivo;
    archivo = fopen("aprendizaje1.txt", "w"); // Siempre crea el archivo
    int M,N;
    Robot robot;
    robot.x = 0;
    robot.y = 0;

    do
    {
        printf("Dame la altura del arreglo: ");
        scanf("%d", &M);
    } while (M < 0 && M > 100);

    do
    {
        printf("Dame la anchura del arreglo: ");
        scanf("%d", &N);
    } while (N < 0 && N > 100);

    int way[M][N];

   
    fprintf(archivo, "000\n");

    way[0][0] = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i != 0 || j != 0) && (i != M-1 || j != M-1))
            {
                printf("presiona 1 si hay un objeto, un 0 si no en (%d,%d): ", i, j);
                scanf("%d",&way[i][j]);
                fprintf(archivo, "%d%d%d\n", i, j, way[i][j]);
            }
        }
    }
    way[2][2] = 0;

    Stack stack;
    setup (&stack);
    recursividad(M, N, way, robot, &stack);
    
    printStack(stack);

    int a = fclose(archivo);

    if (a == EOF) //fclose regresa EOF cuando no se puede cerrar bien
        printf("El archivo no se cerro bien");

    return 0;
}

int recursividad(int M, int N, int w[M][N], Robot robot, Stack *s)
{
    int v;
    if (robot.y == M-1 && robot.x == N-1)
    {
        push(s, robot);
        return 1;
    }
    robot.x++;
    if (w[robot.y][robot.x] == 0 && robot.x < N)
    {
        v = recursividad(M, N, w, robot, s);
        push(s, robot);
        robot.x--;
    } else {
        v = -1;
    }
    if (v == -1)
    {  
        robot.x--;
        robot.y++;
        if (w[robot.y][robot.x] == 0)
        {
            recursividad(M, N, w, robot, s);
            push(s, robot);
        } else {
            return -1; // No puede moverse
        }
        robot.y--;
    }
}

void printStack(Stack s)
{
    printf("(0,0)");
    for (int i = 0; i < s.top; i++)
    {
        printf(" -> (%d,%d)", s.data[s.top-i][1], s.data[s.top-i][0]);
    }
}