#include <stdio.h>


int main()
{
    int num;
    printf("Bienvenido\n");
    printf("1:Nueva partida\n2:cargar partida\n3:ver puntuacion\n4:salir\n");
    while (num!=1||num!=2||num!=3||num!=4)
    {
         scanf("%d",&num);

    switch (num)
    {
    case 1:
        printf("Cargar nueva partida\n");//crear una nueva partida
        break;
    case 2:
        printf("Cargar partida\n");//cargar partida existente
    break;
    case 3:
        printf("ver puntuacion\n");//visualizar mejores puntuaciones
    break;
    case 4:
        printf("Salir\n");//realizar la funcion de salir
    break;
    default:
        printf("Introduzca uno de los numeros marcados\n");//el usuario no introdujo un numero entre el 1-4
        break;
    }
    }
    return 0;
}
