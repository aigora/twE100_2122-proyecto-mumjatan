#include <stdio.h>
#include "functions.h"

int main()
{


    int menuNum,numAux=0;

do
{

        animacion_bienvenida();
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
        system("cls");
        NuevaPartidaAI();
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
        animacion_despedida();
        break;

        default:
            system("cls");

        break;
        }






}while(numAux!=1);

return 0;
}




