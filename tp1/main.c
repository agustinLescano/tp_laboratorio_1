#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
int main()
{
    char seguir='s';
    int opcion=0;
    float x=0;
    float y=0;

    while(seguir=='s')
    {
        printf("\t\t\tMENU CALCULADORA\n");
        printf("\n1- Ingresar 1er operando (A=%.2f)\n",x);
        printf("\n2- Ingresar 2do operando (B=%.2f)\n",y);
        printf("\n3- Calcular la suma (A+B)\n");
        printf("\n4- Calcular la resta (A-B)\n");
        printf("\n5- Calcular la division (A/B)\n");
        printf("\n6- Calcular la multiplicacion (A*B)\n");
        printf("\n7- Calcular el factorial (A!)\n");
        printf("\n8- Calcular todas las operaciones\n");
        printf("\n9- Salir\n");

        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                printf("\n Ingresar el valor del 1er operando:\n\n");
                scanf("%f",&x);
            break;

            case 2:
                printf("\n Ingresar el valor del 2er operando:\n\n");
                scanf("%f",&y);
            break;

            case 3:

                sumar (x,y);
            break;

            case 4:
                restar (x,y);
            break;

            case 5:
                dividir (x,y);
            break;

            case 6:
                multiplicar (x,y);
            break;

            case 7:
                factorial (x);
            break;

            case 8:
                sumar (x,y);
                restar (x,y);
                dividir (x,y);
                multiplicar (x,y);
                factorial (x);
            break;

            case 9:
                seguir = 'n';
                printf("Salir  \n");
            break;

        }



    }

    return 0;

}
