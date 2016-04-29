#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define M 20
void Menu()
    {
        system("cls");
        printf("Menu principal\n");
        printf("--------------\n");
        printf("1 - ingrese nombre\n");
        printf("2 - Baja\n");
        printf("3 - imprimir lista ordenada por nombre\n");
        printf("4 - imprimir grafico\n");
        printf("5 - Salir\n");
        printf("Elija opcion: ");
    }
void IngresoDatos(struct personas persona[])
{
    int i;

    system("cls");
    printf("ingrese datos\n");
    printf("-----------------\n");

    for(i=0;i<M;i++)
        {
            if(persona[i].estado==0)
                {
                    printf("Ingrese nombre: ");
                    ValidarNombre(persona[i].nombre);

                    printf("Ingrese DNI: ");
                        scanf("%ld",&persona[i].dni);

                    printf("Ingrese edad: ");
                    scanf("%d", & persona[i].edad);
                }

        }



        if(i==M)
                {
                    printf("No queda memoria suficiente para seguir guardar datos\n");
                }
            else
                {
                    printf("\nEl dato fue guardado exitosamente");
                    printf("\nPresione ENTER para continuar...");
                    system("pause>>null");
                    return 0;
                 }
                 getch();
}

    void ValidarNombre(char nombre[])
    {
        char aux [50];

        scanf("%s", aux);
    while (strlen(aux)>20)
        {
            printf("Reingrese nombre :(maximo 20 caracteres ");
            scanf("%s", aux);
        }
    strcpy(nombre, aux);
    }

    void ordenar(struct personas persona[])
    {
        struct personas  auxN;
        int i,j;
        system("cls");
        for(i=0;i<M-1;i++)
                {
                    for(j=i+1;j<M;j++)
                    {
                        if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                        {
                            auxN=persona[i];
                            persona[i]=persona[j];
                            persona[j]=auxN;
                         }
                    }
                }
                printf("nombre\t\tdni\t\t\tedad");
                 for(i=0;i<M;i++)
                 {
                     if(persona[i].estado=1)
                     {
                         printf("\n%s\t\t%ld\t\t%d",persona[i].nombre,persona[i].dni,persona[i].edad);
                     }
                 }

              getch();
    }
    void BajaDatos(struct personas persona[])
    {
        int i=0;
        long int aux;
        system("cls");
        printf("BAJA \n");
        printf("-----------------\n");

        printf("Ingrese dni qe qiere dar de baja: ");
        scanf("%ld",&aux);
    for(i=0;i<M;i++)
        {
            if(aux==persona[i].dni)
                {
                    persona[i].estado=0;
                    printf("borrado");
                }
            if (aux=!persona[i].dni)
                {

                    persona[i].estado=1;
                    printf("\ndni no encontrado.");
                    system("PAUSE");
                }


        }

    printf("\nPresione ENTER para continuar...");
    system("pause>>null");
    return ;
}
void grafico(struct personas persona[])
{
   int i, rango1=0, rango2=0, rango3=0, flag1=0, flag2=0, mayor;
    for(i=0;i<M;i++)
    {
        if(persona[i].estado==0)
            {
                if(persona[i].edad<18)
                   {
                        rango1++;
                   }
                if(persona[i].edad>19&&persona[i].edad<35)
                    {
                        rango2++;
                    }

                if(persona[i].edad>=35)
                    {
                         rango3++;
                    }
            }
    }
    if(rango1 >= rango2 && rango1 >= rango3)
        {
            mayor = rango1;
        }
    else
        {
        if(rango2 >= rango1 && rango2 >= rango3)
            {
                mayor = rango2;
            }
        else
            {
                mayor = rango3;
            }
    }

    for(i=mayor; i>0; i--)
        {
            if(i<= rango1)
                {
                    printf("*");
                    flag1=1;
                }
            if(i<= rango2)
                {
                    flag2=1;
                    printf("\t*");
                }
            if(i<= rango3)
                {
                    if(flag2==0)
                        printf("\t\t*");
                    if(flag2==1)
                        printf("\t*");
                }

        printf("\n");
    }
    printf("<18\t19-35\t>35");
    getch();

    return 0;

}

