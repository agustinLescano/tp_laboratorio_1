typedef struct
{
    char titulo[31];
    char genero[31];
    int duracion;
    char descripcion[81];
    int puntaje;
    char link_deimagen[81];
    short int estado;
}movie;


int getInt(char mensaje[]);
void agregar_pelicula(movie *pelicula, FILE *parch);
void borrar_pelicula(movie *pelicula, FILE *parch);
void modificar_pelicula(movie *pelicula,FILE*parch);
