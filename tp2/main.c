#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define M 20



int main()
{
    int i,opc=0;
    struct personas persona[M];
     for(i=0;i<M;i++)
         {
             persona[i].estado=0;
         }

            while(opc!=5)
                {
                    Menu();
                     scanf("%d",&opc);
                    switch (opc)
                        {

                            case 1:
                                IngresoDatos(persona);
                                break;

                            case 2:
                                BajaDatos(persona);
                                break;

                            case 3:
                                ordenar(persona);

                                break;

                            case 4:
                                grafico(persona);

                                break;
                            case 5:
                                system("cls");
                                printf("Fin del programa\n");
                                system("pause>>null");
                                break;
                            default:
                                printf("Opcion incorrecta");
                                system("pause>>null");
                                break;
                        }
                }
    return 0;
    }





