#include <stdio.h>
#include "funciones.h"
int main()
{
    int turno=0;//turno 0 mueve jugador 1(mayusculas),turno 1 mueve jugador 2(minusculas)
    int tablero[8][8];
    int fila,columna;
    tableroStart(&tablero);//inicializa el tablero con cada pieza en su posicion
    tableroShow(&tablero);//muestra el tablero en pantalla

    while(fila != 9)//si el usuario al introducir el sacanf mete un 9 el programa se acaba
    {
        char aux;
        int num = 0;
        int num2 = 0;
        int num3 = 0;
        int piezaI;
        int filaInicial = 0,columnaInicial = 0,filaFinal = 0,columnaFinal = 0;
        printf(".......,%d\n",turno);
        do
        {
            posicion(&filaInicial,&columnaInicial,&tablero);
            aux = tablero[filaInicial-1][columnaInicial-1];
            reconocerPieza(tablero[filaInicial-1][columnaInicial-1],turno,&num,&piezaI);
            //printf("%c.\n",tablero[filaInicial - 1][columnaInicial - 1]);


        }while(num != 1);
        do
        {
            posicion(&filaFinal,&columnaFinal,&tablero);
            verificarMovimiento(&tablero,piezaI,&num2,&num3,filaInicial,filaFinal,columnaInicial,columnaFinal,&turno);



        }while(num2 != 1);

        if(num3 == 0)
        {
            tablero[filaInicial-1][columnaInicial-1] = ' ';
            tablero[filaFinal-1][columnaFinal-1]=aux;
            system("cls");
            cambioTurno(&turno);
            tableroShow(&tablero);
        }





    }
    return 0;
}

