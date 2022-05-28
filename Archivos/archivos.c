#include <stdio.h>

int main()
{
    FILE *archivo;
    int a;
    int valor;
    char nombre[30];
    int leer;

    archivo = fopen("ejemplo.txt", "r"); // Si el archivo no existe y lo intento abrir con r, me regresa null
    /*
    archivo = fopen("ejemplo.txt", "w"); // Siempre crea el archivo

    for (int i = 0; i < 10; i++)
    {
        printf("Dame un nombre: ");
        scanf("%s", nombre);

        printf("Dame un valor entero: ");
        scanf("%d", &valor);

        fprintf(archivo, "%s %d\n", nombre, valor);
    }
    

    printf("Dame un nombre: ");
    scanf("%s", nombre);

    printf("Dame un valor entero: ");
    scanf("%d", &valor);

    fprintf(archivo, "%s %d", nombre, valor);
    */

   do
   {
        fscanf(archivo, "%s", nombre);
        leer = fscanf(archivo, "%d", &valor);

        printf("%s - %d\n", nombre, valor);
   }while (leer != EOF);
   
   


    a = fclose(archivo);

    if (a == EOF) //fclose regresa EOF cuando no se puede cerrar bien
        printf("El archivo no se cerro bien");
    

    return 0;
}
