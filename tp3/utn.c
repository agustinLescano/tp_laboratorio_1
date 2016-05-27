#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


void agregar_pelicula(movie *pelicula, FILE *parch)
{
   int flag=0;

   int aux_duracion, aux_Puntaje;

            printf("\t\t\tAGREGAR PELICULA\n\n");
           printf("\t\t\t----\n\n");

           printf("Ingrese Titulo:\n");
           fflush(stdin);
           gets(pelicula->titulo);
           strupr(pelicula->titulo);

           printf("Ingrese Genero:\n");
           fflush(stdin);
           gets(pelicula->genero);
           strupr(pelicula->genero);

           printf("Ingrese Descripcion:\n");
           fflush(stdin);
           gets(pelicula->descripcion);
           strupr(pelicula->descripcion);

           printf("Ingrese Puntaje:\n");
           scanf("%d",&aux_Puntaje);

           printf("Ingrese Link de Imagen:\n");
           fflush(stdin);
           gets(pelicula->link_deimagen);
           strupr(pelicula->link_deimagen);

           printf("Ingrese Duracion:\n");
           scanf("%d",&aux_duracion);

           fseek(parch, 0L, SEEK_END);
           fflush(parch);
           fwrite(&pelicula, sizeof(movie), 1, parch );

           flag=1;

    if(flag==0)
    {
        printf("No lo encontro\n");
        system("pause");
    }
    else
    {
        printf("La pelicula se guardo con exito\n");
        system("pause");
    }
}


void borrar_pelicula(movie *pelicula, FILE *parch)
{
    char tituloAux[256];
    //int i;
    printf("\t\tBORRAR PELICULA\n");
    printf("\t\t----------------\n\n");

    printf("\n Ingrese titulo de la pelicula que desea borrar: \n");
    fflush(stdin);
    gets(tituloAux);

    if(stricmp(tituloAux,pelicula->titulo)==0)
        {


        printf("\nPELICULA BORRADA\n");
        system("pause");
        }
        else
    {
        printf("no se encontro\n");
        system("pause");
       }
}

void Modificar_pelicula(movie *pelicula, FILE *parch)
{
    int opcMdu;
    char auxChar[30];
    int auxInt;
    char aux[30];
    printf("\t\tMODIFICAR PELICULA\n");
    printf("\t\t------------------\n\n");
    printf ("Ingrese titulo:");
    fflush(stdin);
    gets(aux);
            if(stricmp(aux, pelicula->titulo)==0)
        {
            printf("Modificar\n");
            printf("\n1-Titulo");
            printf("\n2-Descripcion");
            printf("\n3-Duracion");
            printf("\n4-Genero");
            printf("\n5-Puntaje");
            printf("\n6-Volver al menu principal");
            printf("\nElija opcion:");
            scanf("%d",&opcMdu);


            switch(opcMdu)
            {
            case 1:
                printf("\nTitulo a modificar:");
                fflush(stdin);
                gets(auxChar);
                strcpy(pelicula->titulo,auxChar);
                break;
            case 2:
                printf("\nDescripcion a modificar:");
                fflush(stdin);
                gets(auxChar);
               strcpy (pelicula->descripcion,auxChar);
            case 3:
                printf("\nDuracion a modificar:");
                fflush(stdin);
                scanf("%d",&auxInt);
                pelicula->duracion = auxInt;
            case 4:
                printf("\nGenero a modificar:");
                fflush(stdin);
                gets(auxChar);
                strcpy(pelicula->genero,auxChar);
            case 5:
                printf("\nPuntaje a modificar:");
                fflush(stdin);
                gets(auxInt);
                pelicula->puntaje = auxInt;
            case 6:
                break;
            default:
                break;



            }
        }
    }
    void generateHtml (Movie * array, int length)
{

     int i;
     FILE *fp;
     fp=fopen(nameFile, "w");

     if(fp == NULL)
          printf("No se pudo abrir el archivo\n");
     else
     {
        fprintf(fp, "<!DOCTYPE html>\n");
        fprintf(fp,"<html lang='en'>\n");
        fprintf(fp,"<head>\n");
        fprintf(fp,"\t<meta charset='utf-8'>\n");
        fprintf(fp,"\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(fp,"\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(fp,"\t<title>Lista peliculas</title>\n");
        fprintf(fp,"\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(fp,"\t<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(fp,"</head>\n");
        fprintf(fp,"<body>\n");
        fprintf(fp,"\t<div class='container'>\n");
        fprintf(fp,"\t\t<div class='row'>\n");
        for(i=0; i<length; i++)
        {
            fprintf(fp,"\t\t\t<article class='col-md-4 article-intro'>\n");
            fprintf(fp,"\t\t\t\t<a href='#'>\n");
            fprintf(fp,"\t\t\t\t\t<img class='img-responsive img-rounded image-size' src='%s' alt=''>\n",(array+i)->linkImage);
            fprintf(fp,"\t\t\t\t</a>\n");
            fprintf(fp,"\t\t\t\t<h3>\n");
            fprintf(fp,"\t\t\t\t\t<a href='#'>%s</a>\n",(array+i)->title);
            fprintf(fp,"\t\t\t\t</h3>\n");
            fprintf(fp,"\t\t\t\t<ul>\n");
            fprintf(fp,"\t\t\t\t\t<li>Genero:%s</li>\n",(array+i)->genere);
            fprintf(fp,"\t\t\t\t\t<li>Puntaje:%d</li>\n",(array+i)->score);
            fprintf(fp,"\t\t\t\t\t<li>Duracion:%d min.</li>\n",(array+i)->duration);
            fprintf(fp,"\t\t\t\t</ul>\n");
            fprintf(fp,"\t\t\t\t<div class='custom'>%s</div>\n",(array+i)->description);
            fprintf(fp,"\t\t\t</article>\n");
        }
        fprintf(fp,"\t\t</div>\n");
        fprintf(fp,"\t</div>\n");
        fprintf(fp,"\t<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(fp,"\t<script src='js/bootstrap.min.js'></script>\n");
        fprintf(fp,"\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(fp,"\t<script src='js/holder.min.js'></script>\n");
        fprintf(fp,"</body>\n");
        fprintf(fp,"</html>\n");
      }
      fclose(fp);
      printf("PAGINA WEB ACTUALIZADA.\n");
}


/** \brief GUARDA LOS DATOS DE LAS PELICULAS Y LA CANTIDAD DE PELICULAS
 *
 * \param array eMovie Array de peliculas a guardar.
 * \param length int Cantidad de peliculas a guardar.
 * \return void
 *
 */
void saveBin (eMovie * array, int length)
{
    FILE * f;
    f=fopen("listMovie.dat","wb");
    if(f==NULL)
        printf("NO SE PUDO CARGAR EL ARCHIVO\n");
    else
    {
       fwrite(array,sizeof(eMovie),length,f);
       printf("DATOS MOVIE GUARDADOS.\n");
    }
    f=fopen("cantMovie.dat","wb");
    if(f==NULL)
        printf("NO SE PUDO CARGAR EL ACHIVO MOVIE \n");
    else
    {
        printf("CANTIDAD DE PELICULAS %d\n",length);
        fwrite(&length,sizeof(int),1,f);
        printf("DATOS CANTMOVIE GUARDADOS.\n");
        fclose(f);
    }
}

