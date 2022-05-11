#include "funciones.h"
void tableroShow(int *tablero[8][8])
{
    int fila,columna;

       for(fila=0;fila<8;fila++)
    {
        for(columna=0;columna<8;columna++)
        {
            printf("%c ",tablero[fila][columna]);

        }

        printf(" \n");

    }

}
