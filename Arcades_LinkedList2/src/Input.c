/*
 * Input.c
 *
 *  Created on: 20 nov. 2021
 *      Author: MI COMPU
 */


#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"


char inputChar(char mensaje[])
{
    char respuesta;
    printf("%s",mensaje);
    fflush(stdin);
    //__fpurge(stdin);
    scanf("%c", &respuesta);
    return respuesta;
}



char inputCharPosibles(char mensaje[], char posibles[])
{
    char respuesta;
    int mal = 1;
    do
    {

        printf("%s",mensaje);
        fflush(stdin);
        //__fpurge(stdin);
        scanf("%c", &respuesta);
        for(int i = 0; i<strlen(posibles); i++)
        {
            if(respuesta == posibles[i])
            {
                mal = 0;
                break;
            }
        }
        if(mal)
        {
            printf("\nPOR FAVOR, INGRESE UN VALOR PERMITIDO\n");
        }

    }
    while(mal);


    return respuesta;
}




void inputString(char mensaje[], char salida[], int tam)
{
    printf("%s",mensaje);
    fflush(stdin);
    //__fpurge(stdin);
    fgets(salida,tam,stdin);
    salida[strlen(salida)-1]='\0';
    fflush(stdin);
    //__fpurge(stdin);
}





int inputInt(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        //__fpurge(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);

    return atoi(salida);

}


int inputIntDesdeHasta(char mensaje[], int desde,int hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    int retorno;

    do
    {
        printf("%s ",mensaje);
        fflush(stdin);
        //__fpurge(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

        retorno = atoi(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %d y %d, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;

}


