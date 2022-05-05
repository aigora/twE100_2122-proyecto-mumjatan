#include <stdio.h>

void torre(int fila, int columna);
void caballo (int fila, int columna);
void alfil (int fila, int columna);
void reina (int fila, int columna);
void rey (int fila, int columna);
void peon (int fila, int columna);
void hueco (int fila, int columna);

int main ()
{
    int fila;
    int columna;

     fichas negras

    torre(1,1);
    caballo(1,2);
    alfil(1,3);
    reina(1,4);
    rey(1,5);
    alfil(1,6);
    caballo(1,7);
    torre(1,8);
    printf("\n");

    for (columna=1;columna<=8;columna++)
    {
        peon (2,columna);
    }
    printf("\n");

     espacios vacios

    for (fila=1;fila<=4;fila++)
    {
        for (columna=3;columna<=8;columna++)
        {
            hueco (fila,columna);
        }
        printf("\n");
    }

     fichas blancas

    for (columna=1;columna<=8;columna++)
    {
        peon (7,columna);
    }
    printf("\n");

    torre(8,1);
    caballo(8,2);
    alfil(8,3);
    rey(8,4);
    reina(8,5);
    alfil(8,6);
    caballo(8,7);
    torre(8,8);
    printf("\n");
}

void torre(int fila, int columna)
{
    printf("T ");
}
void caballo (int fila, int columna)
{
     printf("C ");
}
void alfil (int fila, int columna)
{
   printf("A ");
}
void reina (int fila, int columna)
{
    printf("R ");
}
void rey (int fila, int columna)
{
    printf("r ");
}
void peon (int fila, int columna)
{
    printf("P ");
}
void hueco (int fila, int columna)
{
    printf("  ");
}

