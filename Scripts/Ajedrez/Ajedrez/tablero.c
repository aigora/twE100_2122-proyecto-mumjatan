#include <stdio.h>
#include "funciones.h"

int main()
{


    int menuNum,numAux=0;

do
{

        printf("Bienvenido!!\n");
        printf("1:Nueva partida\n2:Cargar partida\n3:Normas\n4:Salir\n");


        scanf("%d",&menuNum);
        while(getchar() != '\n');

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
            system("cls");

        break;
        }






}while(numAux!=1);

return 0;
}



