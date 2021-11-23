/*
 * Informes.c
 *
 *  Created on: 22 nov. 2021
 *      Author: MI COMPU
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"



int informes_generar_archivo_multijugador( LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL && !ll_isEmpty(pArrayListArcades))
	{
		ok = controller_saveAsText("multijugador.csv",ll_filter(pArrayListArcades,arcade_multijugador));
	}
	return ok;
}


int informes_duplicar_fichas( LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL && !ll_isEmpty(pArrayListArcades))
	{
		ok = ll_map(pArrayListArcades,arcade_duplicar_fichas);
	}
	return !ok;
}




int informes_menu_informes( LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL)
	{
		int seleccion;
		int tope = 3;


		do
		{
			printf("\nMENU INFORMES \n");
			printf(" 1 - generar y salvar archivo multijugador \n");
			printf(" 2 - Duplicar fichas a toda la lista \n");
			printf(" 3 - Salir \n");
			seleccion = inputIntDesdeHasta("Ingrese el numero : ", 1, tope);
			switch(seleccion)
			{
			case 1:

				ok = informes_generar_archivo_multijugador(pArrayListArcades);
				break;
			case 2:
				ok = informes_duplicar_fichas(pArrayListArcades);
				break;

			}


			switch(ok)
			{
			case 0:
				printf("\n¡¡ERROR!!!");
				break;
			case 1:
				printf("\nOK");
				break;
			case 2:
				printf("\nCANCELADO POR USUARIO");
				break;
			}


		}while(seleccion != tope);
		ok = 1;
	}

	return ok;
}
