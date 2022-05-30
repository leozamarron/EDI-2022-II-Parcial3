#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char lastName[50];
    float average;
} Alumno;

typedef struct {
    char name[20][50];
    char lastName[20][50];
    float average[20];
    int top;
} Alumnos;

void sortOut(Alumnos *a);
void students(Alumnos *a, FILE *data);
void ordenaAscendente(Alumnos *a, char *abecedario);
void cambio(Alumnos *a, int i);
void repeat(Alumnos *a);
void imprimeDatos(Alumnos alumno);

int main()
{
    Alumnos scanAlumno;
    FILE *data = fopen("aprendizaje2.dat", "rb");
    

    if (!data)
    {
        printf("No he podido abrir el archivo. ");
        return -1;
    }

    students(&scanAlumno, data);
    sortOut(&scanAlumno);
    repeat(&scanAlumno);
    imprimeDatos(scanAlumno);

    fclose(data);
    
    return 0;
}

void sortOut(Alumnos *a)
{
    char abecedario[52];
    abecedario[0]='A'; abecedario[1]='a'; abecedario[2]='B'; abecedario[3]='b'; abecedario[4]='C'; abecedario[5]='c';
    abecedario[6]='D'; abecedario[7]='d'; abecedario[8]='E'; abecedario[9]='e'; abecedario[10]='F'; abecedario[11]='f';
    abecedario[12]='G'; abecedario[13]='g'; abecedario[14]='H'; abecedario[15]='h'; abecedario[16]='I'; abecedario[17]='i'; 
    abecedario[18]='J'; abecedario[19]='j'; abecedario[20]='K'; abecedario[21]='k'; abecedario[22]='L'; abecedario[23]='l'; 
    abecedario[24]='M'; abecedario[25]='m'; abecedario[26]='N'; abecedario[27]='n'; abecedario[28]='O'; abecedario[29]='o'; 
    abecedario[30]='P'; abecedario[31]='p'; abecedario[32]='Q'; abecedario[33]='q'; abecedario[34]='R'; abecedario[35]='r';
    abecedario[36]='S'; abecedario[37]='s'; abecedario[38]='T'; abecedario[39]='t'; abecedario[40]='U'; abecedario[41]='u'; 
    abecedario[42]='V'; abecedario[43]='v'; abecedario[44]='W'; abecedario[45]='w'; abecedario[46]='X'; abecedario[47]='x'; 
    abecedario[48]='Y'; abecedario[49]='y'; abecedario[50]='Z'; abecedario[51]='z';

    ordenaAscendente(a, abecedario);
}

void students(Alumnos *a, FILE *data)
{
    Alumno readAlumno;
    a->top = 0;
    while (!feof(data))
    {
        if (!feof(data))
        {
            fread(&readAlumno, sizeof(Alumno), 1, data);
            strcpy(a->name[a->top], readAlumno.name);
            strcpy(a->lastName[a->top], readAlumno.lastName);
            a->average[a->top] = readAlumno.average;
            a->top++;
        }
    }
    a->top-2;
}

void ordenaAscendente(Alumnos *a, char abecedario[52])
{
    int aux, contador;
    for (int j = 0; j < a->top; j++)
    {     
        for (int i = 0; i < a->top; i++)
        {
            contador = 0;
            while (a->lastName[i][0] != abecedario[contador])
            {
                contador++;
            }

            if (i > 0 && aux > contador)
            {
                cambio(a, i);
            }
            aux = contador;
        }
    }

}

void cambio(Alumnos *a, int i)
{
    char aux[20];
    strcpy(aux, a->lastName[i]);
    strcpy(a->lastName[i], a->lastName[i-1]);
    strcpy(a->lastName[i-1], aux);

    strcpy(aux, a->name[i]);
    strcpy(a->name[i], a->name[i-1]);
    strcpy(a->name[i-1], aux);

    int auxx;

    auxx = a->average[i];
    a->average[i] = a->average[i-1];
    a->average[i-1] = auxx;
}

void repeat(Alumnos *a)
{
    for (int i = 0; i < a->top-2; i++)
    {
        if (strcmp(a->name[i], a->name[i+1]) == 0 && strcmp(a->lastName[i], a->lastName[i+1]) == 0)
        {
            for (int j = i+1; j < a->top; j++)
            {
                char aux[20];
                strcpy(a->lastName[j], a->lastName[j+1]);

                strcpy(a->name[j], a->name[j+1]);

                int auxx;
                a->average[j] = a->average[j+1];
            }
            a->top--;
        }
    }
}

void imprimeDatos(Alumnos alumno)
{
    for (int i = 0; i < alumno.top; i++)
    {
        printf("%s %s %.1f \n",alumno.name[i], alumno.lastName[i], alumno.average[i]);
    }
}