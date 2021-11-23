/*
 * parser.c
 *
 *  Created on: 21 nov. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo abierto listo para ser leído en modo texto
 * \param pArrayListEmployee LinkedList* lista de empleados a cargar
 * \return int resultado de la operación
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
    int ok = 1;
    int itemsLeidos;
    int intId, intCantidadJugadores,intFichasMax;
    char charNacionalidad[128];
    char charTipoSonido[128];
    char charNombreJuego[128];
    char charSalon[128];
    int intTipo;
    int total = 0;
    itemsLeidos = fscanf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",charNacionalidad,charNacionalidad, charNacionalidad, charNacionalidad ,charNacionalidad,charNacionalidad,charNacionalidad);
        do
        {
            itemsLeidos = fscanf(pFile,"%d,%[^,],%[^,],%d,%d,%[^,],%[^\n]\n",&intId,charNacionalidad, charTipoSonido, &intFichasMax, &intCantidadJugadores, charSalon,charNombreJuego);
            if(itemsLeidos == 7)
            {
            	if( strcmp(charTipoSonido, "STEREO" ) == 0)
            	{
            		intTipo = 1;
            	}
            	else
            	{
            		intTipo = 2;
            	}
                ll_add(pArrayList, arcade_new(intId, charNacionalidad, intTipo, intFichasMax,intCantidadJugadores,charSalon,charNombreJuego));
                total ++;
            }
            else
            {
                ok = 0;

                break;
            }
        }
        while(!feof(pFile));

    return ok;
}

