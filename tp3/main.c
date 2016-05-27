#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
int main()

    {
        movie pelicula;
        int opc1,bandera=0;
        FILE*parch;
        parch=fopen("movie.dat","rb+");
        if(parch==NULL)
        {
            parch=fopen("movie.dat","wb+");
        }


        while (opc1!=5)
                {
                    system("cls");
                    printf("\t\t\t\tMENU PRINCIPAL\n");
                    printf("\t\t\t\t***************");
                    opc1=getInt("\n 1-Agregar pelicula\n 2-Borrar pelicula\n 3-Modificar pelicula\n 4-Generar pagina web\n 5-Salir\n");
                    switch (opc1)
                    {
                        case 1:
                               bandera=1;
                               agregar_pelicula(&pelicula,parch);

                                break;
                        case 2:
                                borrar_pelicula(&pelicula,parch);

                                break;
                        case 3:
                            if (bandera==1)
                                {
                                Modificar_pelicula(&pelicula,parch);

                                    break;
                                }
                                else
                                {
                                    printf("No hay peliculas cargadas\n");
                                    system("pause");
                                }


                                break;

                        case 4: if(cantMovie>0)
                generateHtml (Movie, cantMovie, "LISTA DE PELICULAS.html");
                                    break;

                        case 5:printf("SALIO DEL PROGRAMA\n");

                                break;


                }
             }
        fclose(parch);
        return 0;
        }
