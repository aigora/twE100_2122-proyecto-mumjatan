#include <stdio.h>
#include "funciones.h"

int main()
{


    int menuNum,numAux=0;

do
{

        printf("Bienvenido!!\n\n");
        printf("1:Nueva partida\n\n2:Nueva partida contra AI\n\n3:Cargar ultima partida\n\n4:Menu de normas\n\n5:Salir\n");



        scanf("%d",&menuNum);
        while(getchar() != '\n');

            switch(menuNum)
        {


        case 1://Nueva partida
        system("cls");
        Nuevapartida();
        break;
        case 2://Nueva partida contra AI
        printf("A");
         system("cls");
        break;

        case 3://Cargar partida
        system("cls");
        cargarPartida();

        break;

        case 4://Normas
        system("cls");
        menuNormas();
        break;

        case 5://Salir
        numAux = 1;
        break;

        default:
            system("cls");

        break;
        }






}while(numAux!=1);

return 0;
}



