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

void tableroStart(int *tablero[8][8])
{
    int fila,columna;

    tablero[0][0]='T';
    tablero[0][1]='C';
    tablero[0][2]='A';
    tablero[0][3]='R';
    tablero[0][4]='Q';
    tablero[0][5]='A';
    tablero[0][6]='C';
    tablero[0][7]='T';

    tablero[7][0]='t';
    tablero[7][1]='c';
    tablero[7][2]='a';
    tablero[7][3]='r';
    tablero[7][4]='q';
    tablero[7][5]='a';
    tablero[7][6]='c';
    tablero[7][7]='t';

    for(columna = 0;columna < 8;columna++)
    {

        tablero[1][columna]='P';
        tablero[2][columna]=' ';
        tablero[3][columna]=' ';
        tablero[4][columna]=' ';
        tablero[5][columna]=' ';
        tablero[6][columna]='p';


    }

}

void reconocerPieza(int pieza,int turno,int *num,int *piezaI)
{

    if(turno == 0)
    {
        if((pieza>64)&&(pieza<91))
        {
            //printf("%d,%c\n",pieza,pieza);
            if(pieza == 'P')
            {
                *piezaI = 1;
            }else if(pieza == 'T')
            {

                 *piezaI = 2;
            }else if(pieza == 'C')
            {

                 *piezaI = 3;
            }else if(pieza == 'A')
            {

                 *piezaI = 4;
            }else if(pieza == 'R')
            {

                 *piezaI = 5;
            }else if(pieza == 'Q')
            {

                 *piezaI = 6;
            }
            *num = 1;

        }else if(pieza == 32)
        {
            printf("Eso es un espacio vacio\n");

        }else
        {
            printf("Esa pieza es del otro jugador\n");

        }


    }else if(turno == 1)
    {
         if(pieza>96&&pieza<123)
        {
            //printf("%d,%c\n",pieza,pieza);
             if(pieza == 'p')
            {
                *piezaI = 1;
            }else if(pieza == 't')
            {

                 *piezaI = 2;
            }else if(pieza == 'c')
            {

                 *piezaI = 3;
            }else if(pieza == 'a')
            {

                 *piezaI = 4;
            }else if(pieza == 'r')
            {

                 *piezaI = 5;
            }else if(pieza == 'q')
            {

                 *piezaI = 6;
            }
            *num = 1;

        }else if(pieza == 32)
        {
            printf("Eso es un espacio vacio\n");

        }else
        {
            printf("Esa pieza es del otro jugador\n");

        }

    }

}

void cambioTurno(int *turno)
{
    if(*turno == 0)
    {
        *turno = 1;

    }else if(*turno == 1)
    {

        *turno = 0;
    }

}

void verificarMovimiento(int *tablero[8][8],int piezaI,int *num2,int *num3,int filaInicial,int filaFinal,int columnaInicial,int columnaFinal,int *turno)
{
   if(*turno == 0)
   {
       if(piezaI == 1)//movimiento del peon
       {

          if(columnaFinal == columnaInicial)//mov rectos
          {
              if((filaInicial == 2)&&(filaFinal - filaInicial == 2))//mov inicial de dos
              {
                    if((tablero[filaFinal-1][columnaFinal-1]==' ')&&(tablero[filaFinal][columnaFinal]==' '))
                    {
                        *num2 = 1;
                        *num3 = 0;

                    }else
                    {
                        printf("Hay una pieza delante del peon\n");
                        *num2 = 1;
                        *num3 = 1;

                    }
              }
              if((filaFinal - filaInicial == 1)&&(columnaFinal == columnaInicial))//movimiento recto
              {
                    if(tablero[filaFinal -1][columnaFinal -1]==' ')
                    {
                        *num2 = 1;
                        *num3 = 0;

                    }else
                    {
                        printf("Espacio ocupado por %c\n",tablero[filaFinal-1][columnaFinal-1]);
                        *num2 = 1;
                        *num3 = 1;
                    }
              }

          }
           if(columnaFinal != columnaInicial)//comer piezas
              {
                    if(columnaInicial == 1 && columnaFinal == 2&&(filaFinal - filaInicial == 1))
                    {
                        printf("c\n");
                        if(tablero[filaFinal-1][columnaFinal-1]!=' ')
                        {

                            *num2 = 1;
                            *num3 = 0;

                        }else
                        {
                            printf("Movimiento no valido\n");
                            *num2 = 1;
                            *num3 = 1;

                        }

                    }
                    if(columnaInicial == 8&&columnaFinal == 7&&(filaFinal - filaInicial == 1))
                    {

                         if(tablero[filaFinal-1][columnaFinal-1]!=' ')
                        {
                            *num2 = 1;
                            *num3 = 0;

                        }else
                        {
                            printf("Movimiento no valido\n");
                            *num2 = 1;
                            *num3 = 1;

                        }
                    }

                    if(columnaInicial>1&&columnaInicial<8)
                    {
                        if(filaFinal -filaInicial == 1)
                        {
                            if(tablero[filaFinal-1][columnaFinal-1]!=' ')
                            {

                                *num2 = 1;
                                *num3 = 0;


                            }else
                            {
                            printf("Movimiento no valido\n");
                            *num2 = 1;
                            *num3 = 1;

                            }

                        }

                    }

              }
       }
   }else if(*turno == 1)
   {

    *num2 = 1;
   }
}


