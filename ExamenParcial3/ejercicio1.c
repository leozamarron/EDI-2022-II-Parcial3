#include <stdio.h>

typedef struct alumnos
{
    float valor;
    char nombre[30];
    int leer;
    int alumnosTotal;
}Alumnos;

void alumnosN(Alumnos *a);
void capturaDatos(FILE *archivo, Alumnos alumnos);

int main()
{
    Alumnos alumnos;
    FILE *archivo;

    archivo = fopen("ejercicio1.txt", "w"); // Siempre crea el archivo

    alumnosN(&alumnos);
    capturaDatos(archivo, alumnos);

    fclose(archivo);

    return 0;
}

void alumnosN(Alumnos *a)
{
    printf("Dame el total de alumnos: ");
    scanf("%d", &a->alumnosTotal);
}

void capturaDatos(FILE *archivo, Alumnos alumnos)
{
    for (int i = 0; i < alumnos.alumnosTotal; i++)
    {
        printf("Dame un nombre: ");
        scanf("%s", &alumnos.nombre);

        printf("Dame la calficacion: ");
        scanf("%f", &alumnos.valor);

        fprintf(archivo, "%s %f\n", alumnos.nombre, alumnos.valor);
    }
}