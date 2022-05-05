#include <stdio.h>


int main()
{
    int num;
    printf("Bienvenido, indique que le apetece hacer\n");
    printf("1:Nueva partida\n2:Cargar partida\n3:Ver puntuaci%cn\n4:Salir\n",162);
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
        printf("Ver puntuaci%cn\n",162);//visualizar mejores puntuaciones
    break;
    case 4:
        printf("Salir\n");//realizar la funcion de salir
        return 0;
    break;
    default:
        printf("Introduzca uno de los numeros marcados\n");//el usuario no introdujo un numero entre el 1-4
        break;
    }
    }
}
