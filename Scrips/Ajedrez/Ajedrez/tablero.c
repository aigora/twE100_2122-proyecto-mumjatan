#include <stdio.h>
#include "funciones.h"

int main()
{
    printf("Bienvenido!!\n");

    int menuNum,numAux=0;

do
{


        printf("1:Nueva partida\n2:Cargar partida\n3:Normas\n4:Salir\n");


        scanf("%d",&menuNum);

            switch(menuNum)
        {


        case 1://Nueva partida
        system("cls");
        Nuevapartida();
        break;

        case 2://Cargar partida

        printf("B\n");
        system("cls");
        break;

        case 3://Normas
        system("cls");
        menuNormas();
        break;

        case 4://Salir
        numAux = 1;
        break;

        default:
            printf("Error");
            return 0;
        break;
        }






}while(numAux!=1);

return 0;
}



