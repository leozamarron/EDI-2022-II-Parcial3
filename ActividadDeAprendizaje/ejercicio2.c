#include <stdio.h>

typedef struct {
    char name[50];
    char lastName[50];
    float average;
} Alumno;

int main()
{

    FILE *data = fopen("aprendizaje2.dat", "rb");

    if (!data)
    {
        printf("No he podido abrir el archivo. ");
        return 1;
    }

    do
    {
        fscanf(archivo, "%s", nombre);
        leer = fscanf(archivo, "%d", &valor);

        printf("%s - %d\n", nombre, valor);
    }while (leer != EOF);
    

    fclose(data);
    
    return 0;
}