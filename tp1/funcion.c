float sumar (float x, float y)
    {
        float respuesta;
            respuesta=(x+y);
            printf("la suma es: %.2f\n",respuesta);

        return 0;
    }


float restar (float x, float y)
    {
        float respuesta;
            respuesta=(x-y);
            printf("la resta es: %.2f\n",respuesta);
        return 0;
    }

float dividir (float x, float y)
    {
        float respuesta = -1;


        if (y==0)
            {
                printf("\n no se puede dividir por Cero \n");

            }
        else
            {
               respuesta=(x/y);
               printf("la divicion es :%.2f\n",respuesta);
                return 0;
            }
    }

float multiplicar (float x, float y)
    {
       float respuesta;
            respuesta=(x*y);
            printf("la multiplicacion es: %.2f\n",respuesta);
            return 0;

    }


int factorial (int x)
    {
        int ERROR = -1;
        int iFor;
        float factorial;

        if (x < 0)
            {
                printf("\n ERROR: Numero menor a Uno\n");
                return ERROR;
            }
        else if (x == 0)
            {
                printf("\n El factorial de %d es: 1\n", x);
                return 0;
            }
        else
            {
                factorial = 1;

                for (iFor = 1; iFor <= x; iFor++)
                    {
                        factorial = factorial * iFor;
                    }

                printf("\n El factorial de %d es: %.2f\n", x, factorial);

                return 0;
            }
    }

