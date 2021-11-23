/*
 * Controller_Arcades.c
 *
 *  Created on: 21 nov. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Controller_Arcades.h"
#define STEREO 1
#define MONO 2


void controller_arcade_list(eArcade* uno )
{
	char tipo[10] = "STEREO";
	if(uno->tipoSonido == MONO)
	{
		strcpy(tipo, "MONO");
	}
	printf(" %3d %30s %30s %12d %12d %30s %30s \n",uno->idArcade, uno->nacionalidadArcade, tipo, uno->cantidadJugadores, uno->capacidadMaxFichas, uno->nombreSalon, uno->nombreJuego);
}



int controller_arcades_list(LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL)
	{
		eArcade* uno;
		printf(" %3s %30s %30s %12s %12s %30s %30s \n","ID","NACIONALIDAD", "TIPO SONIDO", "JUGADORES", "FICHAS MAX.", "NOMBRE SALON", "NOMBRE JUEGO");
		for(int i = 0; i < ll_len(pArrayListArcades); i ++)
		{
			uno = (eArcade*) ll_get(pArrayListArcades, i);
			controller_arcade_list(uno);
		}
		ok = 1;
	}
	return ok;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* el path completo al archivo origen de los datos, ruta , nombre y extensión si la tuviera
 * \param pArrayListEmployee LinkedList* la lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcades)
{
    int ok = 0;
    FILE* pArchivo;
    if((pArchivo = fopen(path,"r")) == NULL)
    {
        printf("\nARCHIVO NO ENCONTRADO\n");
    }
    else
    {
        printf("\nCARGANDO DATOS A MEMORIA..\n");
        ok = parser_FromText(pArchivo, pArrayListArcades);
    }
    printf("\nTODO CARGADO.\n");
    fclose(pArchivo);

    return ok;
}

int controller_arcade_max_id(LinkedList* pArrayListArcades)
{
	int max = 0;
	if(pArrayListArcades != NULL)
	{

		for(int i = 0; i<ll_len(pArrayListArcades); i++)
		{
			eArcade* uno = ll_get(pArrayListArcades,i);
			if(i == 0 || uno->idArcade > max)
			{
				max = uno->idArcade;
			}
		}

	}
	return max;
}



int controller_arcade_add(LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL)
	{
		printf(" ALTA DE ARCADE \n");
		eArcade* aux = arcade_new_();
		aux->idArcade = controller_arcade_max_id(pArrayListArcades) + 1;
		inputString("Ingrese la nacionalidad : " ,aux->nacionalidadArcade, 30);
		inputString("Ingrese Nombre del juego : " ,aux->nombreJuego, 64);
		inputString("Ingrese Nombre del SALON : " ,aux->nombreSalon, 30);
		aux->tipoSonido = inputIntDesdeHasta("Ingrese tipo de sonido 1 = STEREO, 2 = MONO ", 1, 2);
		aux->cantidadJugadores = inputInt("Ingrese cantidad de jugadores: ");
		aux->capacidadMaxFichas = inputInt("Ingrese cantidad MAX de fichas: ");
		if(inputInt("Ingrese 1 para confirmar, cualquier otro para cancelar ") == 1)
		{
			ll_add(pArrayListArcades,aux);
			aux = NULL;
			ok = 1;
		}
		else
		{
			ok = 2;
		}


	}
	return ok;
}

LinkedList* controller_arcade_mostrar_juegos_cargados_sin_repetir(LinkedList* pArrayListArcades)
{
	LinkedList* pListaFinal   = ll_newLinkedList();
	if(pArrayListArcades != NULL)
	{
		LinkedList* pListaSinJuegosRepetidos = ll_clone(pArrayListArcades);


		ll_sort(pListaSinJuegosRepetidos,arcade_sort_nombre,1);
		eArcade* pivot;
		eArcade* elemento;
		for(int i = 0; i< ll_len(pListaSinJuegosRepetidos); i++)
		{
			elemento =  ll_get(pListaSinJuegosRepetidos,i);

			if(i == 0 )
			{
				pivot = elemento;
			}
			else
			{
				if( strcmp(pivot->nombreJuego , elemento->nombreJuego ) != 0 )
				{
					pivot = elemento;
					ll_add( pListaFinal,elemento);
				}
			}
		}
		for(int i = 0; i < ll_len(pListaFinal); i++)
		{
			printf(" %64s \n", ((eArcade*) ll_get(pListaFinal,i))->nombreJuego);
		}

	}
	return pListaFinal;
}




int controller_arcade_edit(LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL && ll_len(pArrayListArcades) > 0)
	{
		int seleccion = 0;
		int id = 0;
		int encontrado = 0;
		eArcade* aux = arcade_new_();
		char campoString30[30];
		char campoString64[64];
		int campoInt;
		int campo;

		printf(" EDITAR UN ARCADE \n");
		controller_arcades_list(pArrayListArcades);
		do
		{
			seleccion = inputInt("Ingrese el ID a editar : ");
			for(int i = 0;i<ll_len(pArrayListArcades); i++)
			{
				aux =  ll_get(pArrayListArcades,i);
				id = aux->idArcade;
				if(id == seleccion)
				{
					encontrado = 1;
					break;
				}
			}
			if(encontrado == 0)
			{
				printf("\n NO ENCUENTRO EL ID TIPEADO, VUELVA A INGRESARLO ");
			}
		}while(encontrado == 0);

		printf("ELIJA EL CAMPO A EDITAR POR NÚMERO \n");
		printf(" 1 - nombre de juego\n");
		printf(" 2 - nacionalidad\n");
		printf(" 3 - nombre de SALON\n");
		printf(" 4 - tipo de sonido\n");
		printf(" 5 - cantidad de jugadores\n");
		printf(" 6 - cantidad maxima de fichas\n");
		campo = inputIntDesdeHasta("Ingrese numero : ", 1, 6);
		switch(campo)
		{
		case 1:
			controller_arcade_mostrar_juegos_cargados_sin_repetir(pArrayListArcades);
			inputString("\nIngrese Nombre del juego : " ,campoString64, 64);
			if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
			{
				arcade_set_nombreJuego(aux, campoString64);
				ok = 1;
			}
			else
			{
				ok = 2;
			}

			break;
		case 2:
			inputString("Ingrese la nacionalidad : " ,campoString30, 30);
			if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
			{
				arcade_set_nacionalidad(aux, campoString30);
				ok = 1;
			}
			else
			{
				ok = 2;
			}
			break;
		case 3:
			inputString("Ingrese Nombre del SALON : " ,campoString30, 30);
			if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
			{
				arcade_set_NombreSalon(aux, campoString30);
				ok = 1;
			}
			else
			{
				ok = 2;
			}
			break;
		case 4:
			if(inputIntDesdeHasta("Ingrese tipo de sonido 1 = STEREO, 2 = MONO ", 1, 2) == 1)
			{

				if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
				{
					arcade_set_tipoSonido(aux, STEREO);
					ok = 1;

				}
				else
				{

					ok = 2;
				}

			}
			else
			{

				if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
				{
					arcade_set_tipoSonido(aux, MONO);
					ok = 1;

				}
				else
				{

					ok = 2;
				}

			}
			break;
		case 5:
			campoInt = inputInt("Ingrese cantidad de jugadores: ");
			if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
			{
				arcade_set_cantidadJugadores(aux, campoInt);
				ok = 1;

			}
			else
			{

				ok = 2;
			}
			break;
		case 6:
			campoInt = inputInt("Ingrese cantidad MAXIMA de fichas: ");
			if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
			{
				arcade_set_capacidadMaxFichas(aux, campoInt);
				ok = 1;

			}
			else
			{

				ok = 2;
			}
			break;

		}



	}
	return ok;
}

int controller_arcade_delete(LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL && ll_len(pArrayListArcades) > 0)
	{
		int seleccion = 0;
		int id = 0;
		int encontrado = -1;
		eArcade* aux = arcade_new_();

		printf(" EDITAR UN ARCADE \n");
		controller_arcades_list(pArrayListArcades);
		do
		{
			seleccion = inputInt("Ingrese el ID a editar : ");
			for(int i = 0;i<ll_len(pArrayListArcades); i++)
			{
				aux =  ll_get(pArrayListArcades,i);
				id = aux->idArcade;
				if(id == seleccion)
				{
					encontrado = i;
					break;
				}
			}
			if(encontrado == -1)
			{
				printf("\n NO ENCUENTRO EL ID TIPEADO, VUELVA A INGRESARLO ");
			}
		}while(encontrado == -1);

		if(inputIntDesdeHasta("Ingrese 1 para confirmar , 2 para cancelar : ", 1, 2) == 1)
		{
			ll_remove(pArrayListArcades, encontrado);
			ok = 1;
		}
		else
		{
			ok = 2;
		}

	}
	return ok;
}






/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_arcades_sort(LinkedList* pArrayListArcades)
{
    int ok = 1;
    int campoAmodificar = 0;
    int sentido = 0;

    if(!ll_isEmpty(pArrayListArcades))
    {
        printf("\nSELECCIONE EL CAMPO POR NUMERO\n");
        printf(" 1 - id \n");
        printf(" 2 - nacionalidad\n");
        printf(" 3 - tipo de sonido \n");
        printf(" 4 - jugadores \n");
        printf(" 5 - cantidad maxima de fichas \n");
        printf(" 6 - salon \n");
        printf(" 7 - nombre de Juego \n");
        campoAmodificar = inputIntDesdeHasta(" Ingrese valor del 1 al 7 : ",1,7);

        printf("\nSELECCIONE EL SENTIDO\n");
        printf(" 1 - ascendente \n");
        printf(" 2 - descendente \n");

        sentido = inputIntDesdeHasta(" Ingrese valor del 1 al 2 : ",1,2);
        if(sentido == 2)
        {
            sentido = 0;
        }

        switch(campoAmodificar)
        {
        case 1:
            ll_sort(pArrayListArcades,arcade_sort_id,sentido);

            break;
        case 2:
            ll_sort(pArrayListArcades,arcade_sort_nacionalidad,sentido);

            break;
        case 3:
            ll_sort(pArrayListArcades,arcade_sort_tipoSonido,sentido);
            break;
        case 4:
            ll_sort(pArrayListArcades,arcade_sort_jugadores,sentido);
            break;
        case 5:
            ll_sort(pArrayListArcades,arcade_sort_fichaMax,sentido);
            break;
        case 6:
            ll_sort(pArrayListArcades,arcade_sort_nombreSalon,sentido);
            break;
        case 7:
            ll_sort(pArrayListArcades,arcade_sort_nombre,sentido);
            break;
        }


    }
    else
    {
        printf("\nNO HAY DATOS PARA PROCESAR\n");
        ok = 0;
    }
    return ok;
}





int controller_menu_arcades( LinkedList* pArrayListArcades)
{
	int ok = 0;
	if(pArrayListArcades != NULL)
	{
		int seleccion;
		int tope = 10;
		int cargadaListaDesdeArchivo = 0;


		do
		{
			printf("\nMENU ARCADES \n");
			printf(" 1 - carga Arcades desde archivo \n");
			printf(" 2 - Listar Arcades \n");
			printf(" 3 - Alta de Arcades\n");
			printf(" 4 - Modifica de Arcades\n");
			printf(" 5 - Baja de Arcades \n");
			printf(" 6 - Ordenar por distintos criterios \n");
			printf(" 7 - salvar Arcades a archivo \n");
			printf(" 8 - salvar archivo de nombres de juegos \n");
			printf(" 9 - MENU INFORMES \n");
			printf(" 10 - Salir \n");
			seleccion = inputIntDesdeHasta("Ingrese el numero : ", 1, tope);
			switch(seleccion)
			{
			case 1:
				ok = controller_loadFromText("arcades.csv",pArrayListArcades);
				cargadaListaDesdeArchivo = 1;
				break;
			case 2:
				ok = controller_arcades_list(pArrayListArcades);
				break;
			case 3:
				if(!cargadaListaDesdeArchivo)
				{
					printf("\n¡¡ADVERTENCIA!! : tenga en cuenta que al cargar la lista se pueden borrar registros, sírvase ir al menú 1 y luego ingresar nuevos registros\n");
					if( inputIntDesdeHasta("ingrese 1 para continuar, 2 para cancelar : ", 1, 2) == 1)
					{
						ok = controller_arcade_add(pArrayListArcades);
					}
					else
					{
						ok = 2;
					}
				}
				else
				{
					ok = controller_arcade_add(pArrayListArcades);
				}

				break;
			case 4:
				ok = controller_arcade_edit(pArrayListArcades);
				break;
			case 5:
				ok = controller_arcade_delete(pArrayListArcades);
				break;
			case 6:
				ok = controller_arcades_sort(pArrayListArcades);
				break;
			case 7:
				ok = controller_saveAsText("arcades.csv",pArrayListArcades);
				break;
			case 8:
				ok = controller_save_Lista_juegosAsText("lista_juegos.csv", controller_arcade_mostrar_juegos_cargados_sin_repetir(pArrayListArcades));
				break;
			case 9:
				ok = informes_menu_informes(pArrayListArcades);
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



int controller_saveAsText(char* path , LinkedList* pArrayListArcades)
{
    int ok = 0;
    FILE* pArchivo;
    eArcade* aux = NULL;
    char tipo[10] = "STEREO";

    if((pArchivo = fopen(path,"w")) == NULL)
    {
        printf("\nARCHIVO NO ENCONTRADO\n");
    }
    else
    {
    	if(!ll_isEmpty(pArrayListArcades))
    	{
			printf("\nSALVANDO DATOS A ARCHIVO DE TEXTO..\n");
			fprintf(pArchivo, "%s,%s,%s,%s,%s,%s,%s\n","id","nacionalidad","tipo_sonido","cant_jug","fichas_max","salon","game" );
			for(int i = 0;i < ll_len(pArrayListArcades); i++)
			{
				aux = ll_get(pArrayListArcades,i);
				if(aux->tipoSonido == 1)
				{
					strcpy(tipo, "STEREO");
				}
				else
				{
					strcpy(tipo, "MONO");
				}

				fprintf(pArchivo, "%d,%s,%s,%d,%d,%s,%s\n", aux->idArcade,aux->nacionalidadArcade,tipo,aux->cantidadJugadores, aux->capacidadMaxFichas, aux->nombreSalon, aux->nombreJuego);
			}
			ok = 1;
			printf("\nFIN DE PROCESO.\n");
			fclose(pArchivo);
    	}
    }


    return ok;
}


int controller_save_Lista_juegosAsText(char* path , LinkedList* lista)
{
    int ok = 0;
    FILE* pArchivo;


    if((pArchivo = fopen(path,"w+")) == NULL)
    {
        printf("\nARCHIVO NO ENCONTRADO\n");
    }
    else
    {
    	if(!ll_isEmpty(lista))
    	{
			printf("\nSALVANDO DATOS A ARCHIVO DE TEXTO..\n");
			fprintf(pArchivo, "%s\n","lista de juegos" );
			for(int i = 0; i< ll_len(lista); i++)
			{
				fprintf(pArchivo, "%s\n", ((eArcade*) ll_get(lista,i))->nombreJuego);
			}
			ok = 1;

			printf("\nFIN DE PROCESO.\n");
			fclose(pArchivo);
    	}
    }


    return ok;
}
