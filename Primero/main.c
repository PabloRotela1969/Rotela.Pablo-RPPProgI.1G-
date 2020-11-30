#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita
 ordenar un array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio.
  Hardcodear datos y mostrarlos desde el main. *
*/

typedef struct
{
    int id;
    char procesador[30];
    char marca[30];
    float precio;

}Notebook;

void ordenarNotebooksPorMarcaYPrecio(Notebook lista[], int cantidad);


float calcularIVA(float precioBruto);
int reemplazarCaracter(char cadena[], char buscar, char reemplazar);

int main()
{
    printf("El valor del impuesto para 22.5 es %f \n", calcularIVA(22.5));
    printf("Para la cadena %s \n se buscó %c para reemplazar por %c y se encontraron %d \n", "alfa beta",'a','b',reemplazarCaracter("alfa beta",'a','d'));

    Notebook listado[5];

    ordenarNotebooksPorMarcaYPrecio(listado, 5);

    return 0;
}


/*
 Crear una función llamada calcularIVA que reciba como parámetro el precio bruto de un producto y
 devuelva el valor del impuesto (el IVA es 21%). Realizar la llamada desde main. *
 */
float calcularIVA(float precioBruto)
{
    float respuesta = 0;
    respuesta  = precioBruto * 0.21;
    return respuesta;
}


/*2. Crear una función que se llame reemplazarCaracter que reciba una cadena de caracteres como primer parámetro,
como segundo parámetro el carácter a reemplazar y como tercero el nuevo carácter y devuelva la cantidad de veces
que se reemplazo el carácter. int reemplazarCaracter(char [], char, char); *
*/
int reemplazarCaracter(char cadena[], char buscar, char reemplazar)
{
    int cantidad = 0;
    int largo = strlen(cadena);
    for(int i = 0; i<largo; i++)
    {
        if( cadena[i] == buscar)
        {
            cantidad++;
        }
    }
    return cantidad;
}



/*
3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita
 ordenar un array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio.
  Hardcodear datos y mostrarlos desde el main. *

*/
void ordenarNotebooksPorMarcaYPrecio(Notebook lista[], int cantidad)
{
    Notebook aux;
    if( lista != NULL && cantidad > 0)
    {
        printf("Sin ordenar");
        for(int i = 0; i< cantidad ; i++)
        {
            printf("%d  %30s %30s %f \n", lista[i].id, lista[i].marca, lista[i].procesador, lista[i].precio);
        }
        for(int i = 0; i< cantidad - 1; i++)
        {
            for( int j = i + 1; j<cantidad ; j++)
            {
                if(strcmp(lista[i].marca, lista[j].marca) > 0)
                {
                    aux = lista[j];
                    lista[j] = lista[i];
                    lista[i] = aux;
                }
                else
                {
                    if(strcmp(lista[i].marca, lista[j].marca) == 0)
                    {
                        if(lista[i].precio > lista[j].precio)
                        {
                            aux = lista[j];
                            lista[j] = lista[i];
                            lista[i] = aux;
                        }
                    }
                }
            }
        }
        printf("Ordenada");
        for(int i = 0; i< cantidad ; i++)
        {
            printf("%d  %30s %30s %f \n", lista[i].id, lista[i].marca, lista[i].procesador, lista[i].precio);
        }

    }

}

void harcodeo(Notebook lista[], int tama)
{
    int ids[5] = { 1,2,3,4,5};
    char procesador[5] = {"alfa","beta","gamma","delta", "iotta"};
    char marca[5] = {"alfa","beta","gamma","delta"};
    float precio[5] = {2.1,2.2,3.3,4.4,5.5};
    for(int i = 0;i<5; i++)
    {
        lista[i].id = ids[i];
        strcpy(lista[i].procesador, procesador[i]);
        strcpy(lista[i].marca, marca[i]);
        lista[i].precio = precio[i];
    }
}



