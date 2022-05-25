#include "functions.h"
#include <stdio.h>

void tableroShow(int *tablero[8][8],int turno)
{
    int fila,columna;
    printf("\nLista de comandos:\n- 9 0 volver al menu principal\n- 10 0 guardar partida\n- 11 0 limpiar pantalla\n \n \n");

    printf("  ");
    for(fila=0;fila<8;fila++)
    {

        printf("%d ",(fila+1));

    }
    printf("\n");
       for(fila=0;fila<8;fila++)
    {
        for(columna=0;columna<8;columna++)
        {
            if(columna == 0)
            {

                printf("%d ",(fila+1));
            }
            printf("%c ",tablero[fila][columna]);

        }

        printf(" \n");

    }
    printf(".........., %d\n",turno);

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

void verificarMovimiento(int *tablero[8][8],int piezaI,int *num2,int *num3,int filaInicial,int filaFinal,int columnaInicial,int columnaFinal,int turno)
{
   if(turno == 0)//movimientod del jugador 0
   {

       if(piezaI == 1)//movimiento del peon del jugador 0
       {

          if(columnaFinal == columnaInicial)//mov rectos
          {
              if((filaInicial == 2)&&(filaFinal - filaInicial == 2))//mov inicial de dos
              {
                    if((tablero[filaFinal-2][columnaFinal-1]==' ')&&(tablero[filaFinal-1][columnaFinal-1]==' '))
                    {
                        *num2 = 1;
                        *num3 = 0;

                    }else
                    {
                        printf("Hay una pieza delante del peon: %c\n",tablero[filaFinal][columnaFinal-1]);
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

                         if(tablero[filaFinal-1][columnaFinal-1]!=' '&&tablero[filaFinal-1][columnaFinal-1]<123&&tablero[filaFinal-1][columnaFinal-1]>96)
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
                            if(tablero[filaFinal-1][columnaFinal-1]!=' '&&tablero[filaFinal-1][columnaFinal-1]<123&&tablero[filaFinal-1][columnaFinal-1]>96)
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
       }else
        if(piezaI == 2)//Movimiento de torre jugador 0
       {

            if(columnaFinal == columnaInicial)//Movimientos rectos en columna
            {
                int i,vNum=0;
                if(filaFinal>filaInicial)
                {
                for(i=(filaInicial);i<(filaFinal-1);i++)
                {
                    printf("%c_\n",tablero[i][columnaFinal-1]);
                    if(tablero[i][columnaFinal-1]==' ')
                    {
                        if(vNum == 0)
                        {

                            vNum = 0;
                        }

                    }else if(tablero[i][columnaFinal-1]!=' ')
                    {
                       vNum = 1;
                       break;

                    }

                }

                }else if(filaInicial>filaFinal)
                {
                     for(i=(filaInicial);i<(filaFinal-1);i++)
                {
                    printf("%c_\n",tablero[i][columnaFinal-1]);
                    if(tablero[i][columnaFinal-1]==' ')
                    {
                        if(vNum == 0)
                        {

                            vNum = 0;
                        }

                    }else if(tablero[i][columnaFinal-1]!=' ')
                    {
                       vNum = 1;
                       break;

                    }

                }

                }

                if(tablero[filaFinal-1][columnaFinal-1]=='P'||tablero[filaFinal-1][columnaFinal-1]=='T'||tablero[filaFinal-1][columnaFinal-1]=='C'
                   ||tablero[filaFinal-1][columnaFinal-1]=='A'||tablero[filaFinal-1][columnaFinal-1]=='R'||tablero[filaFinal-1][columnaFinal-1]=='Q')
                {
                    if(vNum == 0)
                    {
                        vNum = 1;

                    }

                }
                if(vNum == 0)
                {
                    *num2 = 1;
                    *num3 = 0;

                }else if(vNum == 1)
                {
                    printf("Movimiento no valido_c\n");

                    *num2 = 1;
                    *num3 = 1;

                }

            }else if(filaFinal == filaInicial)//Movimientos rectos en FILA
            {
                int i,vNum=0;
                if(columnaFinal>columnaInicial)
                {

                     for(i=(columnaInicial);i<(columnaFinal-1);i++)
                {

                    printf("%c_\n",tablero[filaFinal-1][i]);

                    if(tablero[filaFinal-1][i]==' ')
                    {
                        if(vNum == 0)
                        {

                            vNum = 0;
                        }

                    }else if(tablero[filaFinal-1][i]!=' ')
                    {
                       vNum = 1;
                       break;

                    }

                }
                }else if(columnaInicial>columnaFinal)
                {
                     for(i=(columnaFinal);i<(columnaInicial-1);i++)
                {

                    printf("%c_\n",tablero[filaFinal-1][i]);

                    if(tablero[filaFinal-1][i]==' ')
                    {
                        if(vNum == 0)
                        {

                            vNum = 0;
                        }

                    }else if(tablero[filaFinal-1][i]!=' ')
                    {
                       vNum = 1;
                       break;

                    }

                }

                }

                if(tablero[filaFinal-1][columnaFinal-1]=='P'||tablero[filaFinal-1][columnaFinal-1]=='T'||tablero[filaFinal-1][columnaFinal-1]=='C'
                   ||tablero[filaFinal-1][columnaFinal-1]=='A'||tablero[filaFinal-1][columnaFinal-1]=='R'||tablero[filaFinal-1][columnaFinal-1]=='Q')
                {
                    if(vNum == 0)
                    {
                        printf("%c\n",tablero[filaFinal-1][columnaFinal-1]);
                        vNum = 1;

                    }

                }
                if(vNum == 0)
                {
                    *num2 = 1;
                    *num3 = 0;

                }else if(vNum == 1)
                {
                    printf("Movimiento no valido_f\n");

                    *num2 = 1;
                    *num3 = 1;

                }

            }


       }
   }else if(turno == 1)
   {

    if(piezaI == 1)//movimiento del peon del jugador 1
       {

          if(columnaFinal == columnaInicial)//mov rectos
          {
              if((filaInicial == 7)&&(filaFinal - filaInicial == -2))//mov inicial de dos
              {
                    if((tablero[filaFinal-1][columnaFinal-1]==' ')&&(tablero[filaFinal][columnaFinal-1]==' '))
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
              if((filaFinal - filaInicial == -1)&&(columnaFinal == columnaInicial))//movimiento recto
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
                    if(columnaInicial == 1 && columnaFinal == 2&&(filaFinal - filaInicial == -1))
                    {
                        printf("c\n");
                        if(tablero[filaFinal-1][columnaFinal-1]!=' '&&tablero[filaFinal-1][columnaFinal-1]<91&&tablero[filaFinal-1][columnaFinal-1]>64)
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
                    if(columnaInicial == 8&&columnaFinal == 7&&(filaFinal - filaInicial == -1))
                    {

                         if(tablero[filaFinal-1][columnaFinal-1]!=' '&&tablero[filaFinal-1][columnaFinal-1]<91&&tablero[filaFinal-1][columnaFinal-1]>64)
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
                        if(filaFinal -filaInicial == -1)
                        {
                            if(tablero[filaFinal-1][columnaFinal-1]!=' '&&tablero[filaFinal-1][columnaFinal-1]<91&&tablero[filaFinal-1][columnaFinal-1]>64)
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
   }
}

void posicion(mCoordenadas *mCoord,int *tablero[8][8],int turno,int coordenada,int AI)
{
    if(coordenada == 1)
    {

        mCoord->filaInicial = -1;
        mCoord->columnaInicial = -1;
        int numAux=0,fila1=-1,columna1=-1;
    do
    {
    printf("Introduca la coordenada %d: ",coordenada);


     scanf("%d %d",&fila1,&columna1);

    while(getchar() != '\n');
    mCoord->filaInicial = fila1;
    mCoord->columnaInicial = columna1;
    if(fila1 == 11 && columna1 == 0)
    {


        system("cls");

        tableroShow(tablero,turno);
    }
    if(fila1 == 10&&columna1==0)
    {
        if(AI==1)
        {
            printf("No se puede guardar una partida contra la AI\n");

        }else
        {
            guardarPartida(tablero,turno);
        printf("Partida guardada\n");

        }


    }
    if(fila1 == 9&&columna1==0)
    {

        numAux =1;
    }
    if(fila1 == -1||columna1 == -1)
    {

        printf("Error, Introduzca de nuevo la ultima posicion\n");
    }else if(fila1 != -1&&columna1 != -1&&fila1 != 11&&fila1!=9&&fila1 != 10)
    {
        if(fila1>0&&fila1<9&&columna1>0&&columna1<9)
        {

            numAux = 1;
        }else{
        printf("Numero no valido,Introduzca de nuevo el ultimo valor deseado\n");
        }

    }


    }while(numAux != 1);

    }else if(coordenada == 2)
    {
        mCoord->filaFinal = -1;
        mCoord->columnaFinal = -1;
        int numAux=0,fila1=-1,columna1=-1;
    do
    {
    printf("Introduca la coordenada %d: ",coordenada);
     scanf("%d %d",&fila1,&columna1);
    while(getchar() != '\n');
    mCoord->filaFinal = fila1;
    mCoord->columnaFinal = columna1;
    if(fila1 == 11 && columna1 == 0)
    {

        system("cls");

        tableroShow(tablero,turno);
    }
    if(fila1 == 10&&columna1==0)
    {

        guardarPartida(tablero,turno);
        printf("Partida guardada\n");

    }
    if(fila1 == 9&&columna1==0)
    {

        numAux =1;
    }
    if(fila1 == -1||columna1 == -1)
    {

        printf("Error, Introduzca de nuevo la ultima posicion\n");
    }else if(fila1 != -1&&columna1 != -1&&fila1 != 11&&fila1!=9&&fila1 != 10)
    {
        if(fila1>0&&fila1<9&&columna1>0&&columna1<9)
        {

            numAux = 1;
        }else{
        printf("Numero no valido,Introduzca de nuevo el ultimo valor deseado\n");
        }

    }


    }while(numAux != 1);

    }





}

void Nuevapartida()
{

    int turno=0;//turno 0 mueve jugador 1(mayusculas),turno 1 mueve jugador 2(minusculas)
    int tablero[8][8];
    int fila=0,columna=0;
    tableroStart(&tablero);//inicializa el tablero con cada pieza en su posicion
    tableroShow(&tablero,turno);//muestra el tablero en pantalla

    while(fila != 9)//si el usuario al introducir el sacanf mete un 9 el programa se acaba
    {

        char aux;
        int num = 0;
        int num2 = 0;
        int num3 = 0;
        int piezaI;

        mCoordenadas coordenadas;


        do
        {
            posicion(&coordenadas,&tablero,turno,1,0);
            fila = coordenadas.filaInicial;
            if(fila != 9)
            {
                 aux = tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1];
            reconocerPieza(tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1],turno,&num,&piezaI);
            //printf("%c.\n",tablero[filaInicial - 1][columnaInicial - 1]);

            }else{

            num = 1;
            }




        }while(num != 1);
        do
        {
            if(fila != 9)
            {
                posicion(&coordenadas,&tablero,turno,2,0);
            verificarMovimiento(&tablero,piezaI,&num2,&num3,coordenadas.filaInicial,coordenadas.filaFinal,coordenadas.columnaInicial,coordenadas.columnaFinal,turno);

            }else{
            num2 = 1;
            num3 = 1;
            }




        }while(num2 != 1);

        if(num3 == 0)
        {
            tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1] = ' ';
            tablero[coordenadas.filaFinal-1][coordenadas.columnaFinal-1]=aux;
            system("cls");
            cambioTurno(&turno);
            tableroShow(&tablero,turno);
        }





    }

    system("cls");



}

void menuNormas()
{
    int numA,numAux = 0;

    while(numAux != 1)
    {
        printf("1:Movimiento\n2:Normas Basicas\n3:Como funciona \n4:Volver Menu Principal\n");
        scanf("%d",&numA);
        while(getchar() != '\n');

    switch(numA)
    {
        case 1:
            menuMovimiento();
        break;

        case 2:
            menuNormasBasicas();
        break;

        case 3:
            menuFuncionamiento();
        case 4:
            system("cls");
            numAux = 1;
        break;

        default:
            system("cls");
        break;

    }

    }



}

void menuMovimiento()
{

int num=0;
while(num != 1)
{
    FILE *p_movimientos;
    char texto[5000];
    int i=0;

    system("cls");

    p_movimientos=fopen("movimiento_fichas.txt","r");

    if (p_movimientos==NULL)
    {
        printf("Error en la apertura del archivo\n");
    }else
    {
       printf("Normas de movimiento:\n");

       while (fscanf(p_movimientos,"%c", &texto[i])!=EOF)
       {
           i++;
       }

       texto[i]='\0';
       printf("%s",texto);
       fclose(p_movimientos);
    }

    printf("Pulse 1 para volver\n");
    scanf("%d",&num);
    while(getchar() != '\n');
}
system("cls");

}

void menuNormasBasicas()
{

 int num=0;
while(num != 1)
{
    system("cls");

    FILE *p_normas;
    char texto[5000];
    int i=0;

    system("cls");

    p_normas=fopen("reglas_basicas.txt","r");

    if (p_normas==NULL)
    {
        printf("Error en la apertura del archivo\n");
    }else
    {
       printf("Normas basicas sobre el juego:\n");

       while (fscanf(p_normas,"%c", &texto[i])!=EOF)
       {
           i++;
       }

       texto[i]='\0';
       printf("%s",texto);
       fclose(p_normas);
    }

    printf("Pulse 1 para volver\n");
    scanf("%d",&num);
    while(getchar() != '\n');
}
system("cls");

}

void menuFuncionamiento()
{
    int num=0;
    while(num != 1)
    {
    system("cls");

    FILE *p_funcionamiento;
    char texto[5000];
    int i=0;

    system("cls");

    p_funcionamiento=fopen("como_funciona.txt","r");

    if (p_funcionamiento==NULL)
    {
        printf("Error en la apertura del archivo\n");
    }else
    {
       printf("Este programa funciona de la siguiente manera::\n");

       while (fscanf(p_funcionamiento,"%c", &texto[i])!=EOF)
       {
           i++;
       }

       texto[i]='\0';
       printf("%s",texto);
       fclose(p_funcionamiento);
    }

    printf("Pulse 1 para volver\n");
    scanf("%d",&num);
    while(getchar() != '\n');

}
system("cls");


}

void guardarPartida(int *tablero[8][8],int turno)
{
    int guardado[8][8];
    int fila, columna;
    FILE *pf,*pt;
    for(fila=0; fila<8; fila++)
    {
        for(columna=0; columna<8; columna++)
         {
             guardado[fila][columna]=tablero[fila][columna];
         }
    }

    pf = fopen("guardado.txt", "w");
    pt = fopen("turnoGuardado.txt","w");
    if (pf == NULL||pt==NULL)
    {
      printf("Error al abrir el fichero.\n");
      return -1;
    }
    else
    {
                for(fila=0; fila<8; fila++)
                {
                  for(columna=0; columna<8; columna++)
                  {
                    fprintf(pf,"%d; ",guardado[fila][columna]);
                  }
                 fprintf(pf,"\n");
                }

        fprintf(pt,"%d,",&turno);
        fclose(pt);
      fclose(pf);
      return 0;
    }

}

void tableroLoad(int *tablero[8][8],int *turno)
{
    int fila,columna,vector1[8],vector2[8],vector3[8],vector4[8],vector5[8],vector6[8],vector7[8],vector8[8],i=0;
    FILE *pf,*pt;
    pf=fopen("guardado.txt","r");
     pt = fopen("turnoGuardado.txt","r");
     if(pf==NULL||pt==NULL)
     {
         printf("Error 404\n");
         return -1;
     }else
     {
         fscanf(pt,"%d,",turno);

        while(fscanf(pf,"%d; %d; %d; %d; %d; %d; %d; %d;\n",&vector1[i],&vector2[i],&vector3[i],&vector4[i],&vector5[i],&vector6[i],&vector7[i],&vector8[i]) != EOF)
        {
            i+=1;

        }

        for(i=0;i<8;i++)
        {
            tablero[i][0]=vector1[i];
            tablero[i][1]=vector2[i];
            tablero[i][2]=vector3[i];
            tablero[i][3]=vector4[i];
            tablero[i][4]=vector5[i];
            tablero[i][5]=vector6[i];
            tablero[i][6]=vector7[i];
            tablero[i][7]=vector8[i];

        }





    }







     pclose(pf);
     fclose(pt);
}

void cargarPartida()
{
     int turno=0;//turno 0 mueve jugador 1(mayusculas),turno 1 mueve jugador 2(minusculas)
    int tablero[8][8];
    int fila=0,columna=0;
    tableroLoad(&tablero,&turno);//inicializa el tablero con cada pieza en su posicion
    tableroShow(&tablero,turno);//muestra el tablero en pantalla

    while(fila != 9)//si el usuario al introducir el sacanf mete un 9 el programa se acaba
    {

        char aux;
        int num = 0;
        int num2 = 0;
        int num3 = 0;
        int piezaI;
        mCoordenadas coordenadas;

        do
        {
            posicion(&coordenadas,&tablero,turno,1,0);
            fila = coordenadas.filaInicial;
            if(fila != 9)
            {
                 aux = tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1];
            reconocerPieza(tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1],turno,&num,&piezaI);
            //printf("%c.\n",tablero[filaInicial - 1][columnaInicial - 1]);

            }else{

            num = 1;
            }




        }while(num != 1);
        do
        {
            if(fila != 9)
            {
                posicion(&coordenadas,&tablero,turno,2,0);
            verificarMovimiento(&tablero,piezaI,&num2,&num3,coordenadas.filaInicial,coordenadas.filaFinal,coordenadas.columnaInicial,coordenadas.columnaFinal,turno);

            }else{
            num2 = 1;
            num3 = 1;
            }




        }while(num2 != 1);

        if(num3 == 0)
        {
            tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1] = ' ';
            tablero[coordenadas.filaFinal-1][coordenadas.columnaFinal-1]=aux;
            system("cls");
            cambioTurno(&turno);
            tableroShow(&tablero,turno);
        }





    }

    system("cls");

}

void NuevaPartidaAI()
{
    int turno=0;//turno 0 mueve jugador 1(mayusculas),turno 1 mueve jugador 2(minusculas)
    int tablero[8][8];
    int fila=0,columna=0;
    tableroStart(&tablero);//inicializa el tablero con cada pieza en su posicion
    tableroShow(&tablero,turno);//muestra el tablero en pantalla

    while(fila != 9)//si el usuario al introducir el sacanf mete un 9 el programa se acaba
    {

        char aux;
        int num = 0;
        int num2 = 0;
        int num3 = 0;
        int piezaI;
        mCoordenadas coordenadas;

        do
        {
            posicion(&coordenadas,&tablero,turno,1,1);
            fila = coordenadas.filaInicial;
            if(fila != 9)
            {
                 aux = tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1];
            reconocerPieza(tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1],turno,&num,&piezaI);
            //printf("%c.\n",tablero[filaInicial - 1][columnaInicial - 1]);

            }else{

            num = 1;
            }




        }while(num != 1);
        do
        {
            if(fila != 9)
            {
                posicion(&coordenadas,&tablero,turno,2,1);
            verificarMovimiento(&tablero,piezaI,&num2,&num3,coordenadas.filaInicial,coordenadas.filaFinal,coordenadas.columnaInicial,coordenadas.columnaFinal,turno);

            }else{
            num2 = 1;
            num3 = 1;
            }




        }while(num2 != 1);

        if(num3 == 0)
        {
            tablero[coordenadas.filaInicial-1][coordenadas.columnaInicial-1] = ' ';
            tablero[coordenadas.filaFinal-1][coordenadas.columnaFinal-1]=aux;
            system("cls");
            movimientoAI(&tablero);
            tableroShow(&tablero,turno);
        }





    }

    system("cls");


}

void movimientoAI(int *tablero[8][8])//hay un limite de 15000 posibles calculos de posiciones aleatorias.
{
    int filaInicial=-1,columnaInicial=-1,numAux1=0,i,comb=0;
    do
    {
        filaInicial = rand() % 8;
        columnaInicial = rand() % 8;
        comb+=1;
        if(comb>15000)
        {

            numAux1 = 1;
        }
        if(tablero[filaInicial][columnaInicial]=='p'||tablero[filaInicial][columnaInicial]=='t'||tablero[filaInicial][columnaInicial]=='c'||
           tablero[filaInicial][columnaInicial]=='a'||tablero[filaInicial][columnaInicial]=='r'||tablero[filaInicial][columnaInicial]=='q')
        {
            //printf("%d %d %c\n",filaInicial,columnaInicial,tablero[filaInicial][columnaInicial]);
           if(tablero[filaInicial][columnaInicial]=='p')//solo hace movimientos rectos
           {
               if(tablero[filaInicial-1][columnaInicial]==' ')
               {
                   char aux;

                    tablero[filaInicial-1][columnaInicial] = 'p';
                    tablero[filaInicial][columnaInicial]=' ';
                    numAux1 = 1;
               }else
               {

                   numAux1 = 0;
               }

           }
           if(tablero[filaInicial][columnaInicial]=='t')//movimientos de la torre hacia los lados y en vertical
           {
                int dir = rand()% 2;
                int sent,casillas,casAux=0,i;

                if(dir == 0)//movimiento hacia los lados
                {
                    sent = rand()%2;
                    if(sent == 0)//mover hacia la derecha
                    {
                        casillas=rand()%2;
                        if(casillas == 0)
                        {

                            casillas = 1;
                        }
                        if((columnaInicial+casillas)<=7)
                        {
                            for(i=columnaInicial;i<(columnaInicial+casillas);i++)
                            {
                                if(tablero[filaInicial][i]!=' ')
                                {
                                    casAux = 1;
                                    break;
                                }else if(tablero[filaInicial][i]==' ')
                                {
                                    if(casAux == 0)
                                    {

                                        casAux = 0;
                                    }
                                }

                            }

                        if(casAux == 0)
                        {
                                if(tablero[filaInicial][columnaInicial+casillas]<91&&tablero[filaInicial][columnaInicial+casillas]>64)
                                {

                                     tablero[filaInicial][columnaInicial+casillas] = 't';
                                    tablero[filaInicial][columnaInicial]=' ';
                                    numAux1 = 1;
                                }else
                                {

                                    numAux1 = 0;
                                }

                        }
                        }else
                        {

                            numAux1 = 0;
                        }



                    }
                    if(sent == 1)//mover hacia la izquierda
                    {
                        casillas=rand()%4;

                        if((columnaInicial-casillas)>=0)
                        {
                            for(i=(columnaInicial-1);i<(columnaInicial-casillas);i--)
                            {
                                if(tablero[filaInicial][i]!=' ')
                                {
                                    casAux = 1;
                                    break;
                                }else if(tablero[filaInicial][i]==' ')
                                {
                                    if(casAux == 0)
                                    {

                                        casAux = 0;
                                    }
                                }

                            }

                        if(casAux == 0)
                        {
                                if(tablero[filaInicial][columnaInicial+casillas]<91&&tablero[filaInicial][columnaInicial+casillas]>64)
                                {

                                     tablero[filaInicial][columnaInicial+casillas] = 't';
                                    tablero[filaInicial][columnaInicial]=' ';
                                    numAux1 = 1;
                                }else
                                {

                                    numAux1 = 0;
                                }

                        }
                        }else
                        {

                            numAux1 = 0;
                        }
                    }


                }
                if(dir == 1)//movimiento en vertical
                {
                    sent = rand()%2;
                     if(sent == 0)//mover hacia arriba
                    {
                        casillas=rand()%4;
                        if((filaInicial-casillas)>=0)
                        {
                            for(i=(filaInicial-1);i<(filaInicial-casillas);i--)
                            {
                                if(tablero[i][columnaInicial]!=' ')
                                {
                                    casAux = 1;
                                    break;
                                }else if(tablero[i][columnaInicial]==' ')
                                {
                                    if(casAux == 0)
                                    {

                                        casAux = 0;
                                    }
                                }

                            }

                        if(casAux == 0)
                        {
                                if(tablero[filaInicial-casillas][columnaInicial]<91&&tablero[filaInicial-casillas][columnaInicial]>64)
                                {

                                     tablero[filaInicial-casillas][columnaInicial] = 't';
                                    tablero[filaInicial][columnaInicial]=' ';
                                    numAux1 = 1;
                                }else
                                {

                                    numAux1 = 0;
                                }

                        }
                        }else
                        {

                            numAux1 = 0;
                        }

                    }
                    if(sent == 1)//mover hacia abajo
                    {

                        casillas=rand()%4;
                        if((filaInicial+casillas)<=7)
                        {
                            for(i=(filaInicial+1);i<(filaInicial+casillas);i++)
                            {
                                if(tablero[i][columnaInicial]!=' ')
                                {
                                    casAux = 1;
                                    break;
                                }else if(tablero[i][columnaInicial]==' ')
                                {
                                    if(casAux == 0)
                                    {

                                        casAux = 0;
                                    }
                                }

                            }

                        if(casAux == 0)
                        {
                                if(tablero[filaInicial+casillas][columnaInicial]<91&&tablero[filaInicial+casillas][columnaInicial]>64)
                                {

                                    tablero[filaInicial+casillas][columnaInicial] = 't';
                                    tablero[filaInicial][columnaInicial]=' ';
                                    numAux1 = 1;
                                }else
                                {

                                    numAux1 = 0;
                                }

                        }
                        }else
                        {

                            numAux1 = 0;
                        }
                    }

                }
           }
           if(tablero[filaInicial][columnaInicial]=='c')//movimientos del caballo al completo
           {
                int incFila = rand() % 3;
                int vert,horz;
                if(incFila == 0)
                {
                    incFila = 1;
                }

                if(incFila == 1)//incremento de fila igual a 1
                {
                    vert = rand()%2;

                    if(vert==0)//se desplaza una fila hacia arriba
                    {
                        horz = rand() % 2;
                        if(horz == 0&&(filaInicial-1>=0&&filaInicial-1<=7)&&(columnaInicial+2>=0&&columnaInicial+2<=7))//se desplaza dos columnas a la derecha
                        {
                            if(tablero[filaInicial-1][columnaInicial+2]==' ')
                            {

                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-1][columnaInicial+2]='c';
                                numAux1 = 1;

                            }else
                            {
                                if(tablero[filaInicial-1][columnaInicial+2]<91&&tablero[filaInicial-1][columnaInicial+2]>64)
                                {
                                    printf("%c\n",tablero[filaInicial-1][columnaInicial+2]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-1][columnaInicial+2]='c';
                                numAux1 = 1;
                                }

                            }
                        }
                        if(horz == 1&&(filaInicial-1>=0&&filaInicial-1<=7)&&(columnaInicial-2>=0&&columnaInicial-2<=7))//se desplaza dos columnas a la izquierda
                        {
                            if(tablero[filaInicial-1][columnaInicial+2]==' ')
                            {

                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-1][columnaInicial-2]='c';
                                numAux1 = 1;

                            }else
                            {
                                if(tablero[filaInicial-1][columnaInicial+2]<91&&tablero[filaInicial-1][columnaInicial+2]>64)
                                {
                                    printf("%c\n",tablero[filaInicial-1][columnaInicial-2]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-1][columnaInicial-2]='c';
                                numAux1 = 1;
                                }

                            }
                        }
                    }
                    if(vert==1)//se desplaza una fila hacia abajo
                    {
                         horz = rand() % 2;
                        if(horz == 0&&(filaInicial+1>=0&&filaInicial+1<=7)&&(columnaInicial+2>=0&&columnaInicial+2<=7))//se desplaza dos columnas a la derecha
                        {
                            if(tablero[filaInicial+1][columnaInicial+2]==' ')
                            {

                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+1][columnaInicial+2]='c';
                                numAux1 = 1;

                            }else
                            {
                                if(tablero[filaInicial+1][columnaInicial+2]<91&&tablero[filaInicial+1][columnaInicial+2]>64)
                                {
                                        printf("%c\n",tablero[filaInicial+1][columnaInicial+2]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+1][columnaInicial+2]='c';
                                numAux1 = 1;
                                }

                            }
                        }
                        if(horz == 1&&(filaInicial+1>=0&&filaInicial+1<=7)&&(columnaInicial-2>=0&&columnaInicial-2<=7))//se desplaza dos columnas a la izquierda
                        {
                            if(tablero[filaInicial+1][columnaInicial+2]==' ')
                            {
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+1][columnaInicial-2]='c';
                                numAux1 = 1;

                            }else
                            {
                                if(tablero[filaInicial+1][columnaInicial+2]<91&&tablero[filaInicial+1][columnaInicial+2]>64)
                                {

                                    printf("%c\n",tablero[filaInicial+1][columnaInicial-2]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+1][columnaInicial-2]='c';
                                numAux1 = 1;
                                }
                            }
                        }
                    }

                }
                if(incFila == 2)//incremento de fila igual a 2
                {

                    vert = rand()%2;

                    if(vert==0)//se desplaza dos fila hacia arriba
                    {
                        horz = rand() % 2;
                        if(horz == 0&&(filaInicial-2>=0&&filaInicial-2<=7)&&(columnaInicial+1>=0&&columnaInicial+1<=7))//se desplaza dos columnas a la derecha
                        {
                            if(tablero[filaInicial-2][columnaInicial+1]==' ')
                            {

                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-2][columnaInicial+1]='c';
                                numAux1 = 1;

                            }else
                            {

                                if(tablero[filaInicial-2][columnaInicial+1]<91&&tablero[filaInicial-2][columnaInicial+1]>64)
                                {
                                     printf("%c\n",tablero[filaInicial-2][columnaInicial+1]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-2][columnaInicial+1]='c';
                                numAux1 = 1;

                                }
                            }
                        }
                        if(horz == 1&&filaInicial-2>=0&&filaInicial-2<=7&&columnaInicial-1>=0&&columnaInicial-1<=7)//se desplaza dos columnas a la izquierda
                        {
                            if(tablero[filaInicial-2][columnaInicial+1]==' ')
                            {
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-2][columnaInicial-1]='c';
                                numAux1 = 1;

                            }else
                            {

                                if(tablero[filaInicial-2][columnaInicial+1]<91&&tablero[filaInicial-2][columnaInicial+1]>64)
                                {
                                    printf("%c\n",tablero[filaInicial-2][columnaInicial-1]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-2][columnaInicial-1]='c';
                                numAux1 = 1;
                                }
                            }
                        }
                    }
                    if(vert==1)//se desplaza dos fila hacia abajo
                    {
                         horz = rand() % 2;
                        if(horz == 0&&filaInicial+2>=0&&filaInicial+2<=7&&columnaInicial+1>=0&&columnaInicial+1<=7)//se desplaza dos columnas a la derecha
                        {
                            if(tablero[filaInicial+2][columnaInicial+1]==' ')
                            {
                               tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+2][columnaInicial+1]='c';
                                numAux1 = 1;

                            }else
                            {

                                 if(tablero[filaInicial+2][columnaInicial+1]<91&&tablero[filaInicial+2][columnaInicial+1]>64)
                                 {
                                     printf("%c\n",tablero[filaInicial+2][columnaInicial+1]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+2][columnaInicial+1]='c';
                                numAux1 = 1;
                                 }

                            }
                        }
                        if(horz == 1&&filaInicial+2>=0&&filaInicial+2<=7&&columnaInicial-1>=0&&columnaInicial-1<=7)//se desplaza dos columnas a la izquierda
                        {
                            if(tablero[filaInicial+2][columnaInicial+1]==' ')
                            {

                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+2][columnaInicial-1]='c';
                                numAux1 = 1;

                            }else
                            {
                                 if(tablero[filaInicial+2][columnaInicial-1]<91&&tablero[filaInicial+2][columnaInicial-1]>64)
                                {
                                     printf("%c\n",tablero[filaInicial+2][columnaInicial-1]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+2][columnaInicial-1]='c';
                                numAux1 = 1;

                                }

                            }
                        }
                    }
                }





           }
           if(tablero[filaInicial][columnaInicial]=='a')//movimientos del alfil al completo
           {
                int incr = rand()%3;
                int vert = rand()%2;
                int dir,vNum=0,i;
                if(incr == 0)
                {
                    incr = 1;
                }
                if(vert == 0)//movimiento hacia arriba
                {
                    dir=rand()%2;
                    if(dir == 0&&(filaInicial-incr<8)&&(filaInicial-incr>=0)&&(columnaInicial+incr<8)&&(columnaInicial+incr>=0))//mov hacia deracha
                    {
                        for(i=1;i<incr;i++)
                        {
                            if(tablero[filaInicial-i][columnaInicial+i]!=' ')
                            {
                                vNum = 1;
                                break;
                            }
                        }

                        if(vNum == 0)
                        {
                            if(tablero[filaInicial-incr][columnaInicial+incr]==' ')
                            {
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-incr][columnaInicial+incr]='a';
                                numAux1 = 1;

                            }else if(tablero[filaInicial-incr][columnaInicial+incr]<91&&tablero[filaInicial-incr][columnaInicial+incr]>64)
                            {
                                printf("%c\n",tablero[filaInicial-incr][columnaInicial+incr]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-incr][columnaInicial+incr]='a';
                                numAux1 = 1;

                            }
                        }
                    }
                    if(dir==1&&(filaInicial-incr<8)&&(filaInicial-incr>=0)&&(columnaInicial-incr<8)&&(columnaInicial-incr>=0))//mov hacia izquierda
                    {
                        for(i=1;i<incr;i++)
                        {
                            if(tablero[filaInicial-i][columnaInicial-i]!=' ')
                            {
                                vNum = 1;
                                break;
                            }
                        }

                        if(vNum == 0)
                        {
                            if(tablero[filaInicial-incr][columnaInicial-incr]==' ')
                            {
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-incr][columnaInicial-incr]='a';
                                numAux1 = 1;

                            }else if(tablero[filaInicial-incr][columnaInicial-incr]<91&&tablero[filaInicial-incr][columnaInicial-incr]>64)
                            {
                                printf("%c\n",tablero[filaInicial-incr][columnaInicial-incr]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial-incr][columnaInicial-incr]='a';
                                numAux1 = 1;

                            }
                        }
                    }
                }
                if(vert == 1)//movimiento hacia debajo
                {
                    dir=rand()%2;
                    if(dir == 0&&(filaInicial+incr<8)&&(filaInicial+incr>=0)&&(columnaInicial+incr<8)&&(columnaInicial+incr>=0))//mov hacia deracha
                    {
                        for(i=1;i<incr;i++)
                        {
                            if(tablero[filaInicial+i][columnaInicial+i]!=' ')
                            {
                                vNum = 1;
                                break;
                            }
                        }

                        if(vNum == 0)
                        {
                            if(tablero[filaInicial+incr][columnaInicial+incr]==' ')
                            {
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+incr][columnaInicial+incr]='a';
                                numAux1 = 1;

                            }else if(tablero[filaInicial+incr][columnaInicial+incr]<91&&tablero[filaInicial+incr][columnaInicial+incr]>64)
                            {
                                printf("%c\n",tablero[filaInicial+incr][columnaInicial+incr]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+incr][columnaInicial+incr]='a';
                                numAux1 = 1;

                            }
                        }
                    }
                    if(dir==1&&(filaInicial+incr<8)&&(filaInicial+incr>=0)&&(columnaInicial-incr<8)&&(columnaInicial-incr>=0))//mov hacia izquierda
                    {
                        for(i=1;i<incr;i++)
                        {
                            if(tablero[filaInicial+i][columnaInicial-i]!=' ')
                            {
                                vNum = 1;
                                break;
                            }
                        }

                        if(vNum == 0)
                        {
                            if(tablero[filaInicial+incr][columnaInicial-incr]==' ')
                            {
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+incr][columnaInicial-incr]='a';
                                numAux1 = 1;

                            }else if(tablero[filaInicial+incr][columnaInicial-incr]<91&&tablero[filaInicial+incr][columnaInicial-incr]>64)
                            {
                                printf("%c\n",tablero[filaInicial+incr][columnaInicial-incr]);
                                tablero[filaInicial][columnaInicial]=' ';
                                tablero[filaInicial+incr][columnaInicial-incr]='a';
                                numAux1 = 1;

                            }
                        }
                    }
                }





           }
           if(tablero[filaInicial][columnaInicial]=='r')
           {


           }
           if(tablero[filaInicial][columnaInicial]=='q')
           {


           }

        }else
        {


        }



    }while(numAux1 != 1);

    if(comb>=15000)
    {

        printf("No se han detectado movimientos posibles :(\n");
    }


    return 0;

}
