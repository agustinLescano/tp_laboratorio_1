struct personas
 {
     char nombre[30];
     long int dni;
     int edad;
     short int estado;
 };

 void Menu();
 void IngresoDatos(struct personas  []);
 void ValidarNombre(char[]);
 void BajaDatos(struct personas persona[]);
 void ValidarDni(struct personas persona[]);
 void ordenar(struct personas persona[]);
 void grafico(struct personas persona[]);


