#define MAX 10 //capacidad de la cola

typedef struct cola
{
    int datos[MAX + 1];
    int inicio;
    int fin;
}Cola;

int estaLlena(Cola cola)
{
    if (cola.inicio == cola.fin + 1 || (cola.inicio == 0 && cola.fin == MAX))
    {
        return 1;
    }
    return 0;
}

int estaVacia(Cola cola)
{
    if((cola.inicio + 2) % (MAX+1) == cola.fin)
    {
        return 1;
    }
    return 0;
}

int insertar(Cola *c, int valor)
{
    int r = 0;

    if (estaLlena(*c) == 0) //Hay espacio para insertar, la cola no esta llena
    {
        //  Poner el valor dentro del arreglo dentro dentro de la posicion que dice fin
        c->datos[c->fin] = valor;
        //  Mover fin a la siguiente casilla libre
        c->fin = (c->fin + 1) % (MAX+1);
        r = 1;
    }

    return r;
}

int eliminar(Cola *c, int v)
{
    int r = 0;
    if (!estaVacia(*c))
    {
        
        if (c->inicio > c->fin)
        {
            while (0 != c->inicio)
            {
                for (int i = c->fin; i != c->inicio; i--)
                {
                    if (i == 0)
                    {
                        i = 11;
                        c->datos[0] = c->datos[i-1];
                    }else{
                        c->datos[i] = c->datos[i-1];
                    }
                }
                c->inicio = (c->inicio +1) % (MAX+1);
                c->fin = (c->fin +1) % (MAX+1);
            }
        }
        if (v + c->inicio >= c->fin)
        {
            v = (v - c->fin) + c->inicio;
        }
        
        if (c->fin-1 == v + c->inicio)
        {
            c->fin = (c->fin -1) % (MAX+1);
            r = c->datos[v-1];
        }
        else if (c->inicio == v+c->inicio)
        {
            c->inicio = (c->inicio +1) % (MAX+1);
            r = c->datos[c->fin - 1];
        }
        else
        {
            for (int i = v + c->inicio; i != c->fin -1 ; i = (i+1) % (MAX+1))
            {
                c->datos[i] = c->datos[i+1];
            }
            c->fin = (c->fin -1) % (MAX+1);
            r = c->datos[v-1];
        }
        
        int a;
        
        while (r != c->datos[c->inicio])
        {
            a = c->datos[c->inicio];
            c->inicio = (c->inicio +1) % (MAX+1);
            insertar(c, a);
        }
    }
    else
    {
        r = 0;
        for(int i = 0; i < v; i++)
        {
            if (i % 2 == 0)
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        if (r == 1)
            c->inicio = (c->inicio + 1);
    }
    return r;
}

void inicializaCola(Cola *c)
{
    c->inicio = 0;
    c->fin = 0;
}