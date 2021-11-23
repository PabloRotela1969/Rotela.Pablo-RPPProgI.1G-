/*
 * Arcade.c
 *
 *  Created on: 20 nov. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"


eArcade* arcade_new_()
{
	eArcade* nuevoArcade = (eArcade*) malloc(sizeof(eArcade));
	if(nuevoArcade != NULL)
	{
		nuevoArcade->idArcade = 0;
		strcpy(nuevoArcade->nacionalidadArcade,"");
		nuevoArcade->tipoSonido = 0;
		nuevoArcade->cantidadJugadores = 0;
		nuevoArcade->capacidadMaxFichas = 0;
		strcpy(nuevoArcade->nombreJuego,"");
		strcpy(nuevoArcade->nombreSalon , "");

	}
	return nuevoArcade;
}

eArcade* arcade_new(int id, char nacionalidad[], int tipoSonido, int cantidadJugadores, int capacidadMaxFichas, char nombre[], char NombreSalon[])
{
	eArcade* nuevoArcade = arcade_new_();

	if(nuevoArcade != NULL)
	{

		if(!arcade_set_id(nuevoArcade, id))
		{
			printf("\n FALLA AL CARGAR ID DURANTE CREACION \n");
		}
		if(!arcade_set_nacionalidad(nuevoArcade, nacionalidad))
		{
			printf("\n FALLA AL CARGAR NACIONALIDAD DURANTE CREACION \n");
		}
		if(!arcade_set_tipoSonido(nuevoArcade, tipoSonido))
		{
			printf("\n FALLA AL CARGAR TIPO DE SONIDO DURANTE CREACION \n");
		}
		if(!arcade_set_cantidadJugadores(nuevoArcade, cantidadJugadores))
		{
			printf("\n FALLA AL CARGAR CANTIDAD DE JUGADORES DURANTE CREACION \n");
		}
		if(!arcade_set_capacidadMaxFichas(nuevoArcade, capacidadMaxFichas))
		{
			printf("\n FALLA AL CARGAR CAPACIDAD MAXIMA DE FICHAS DURANTE CREACION \n");
		}
		if(!arcade_set_nombreJuego(nuevoArcade, nombre))
		{
			printf("\n FALLA AL CARGAR NOMBRE DE JUEGO DURANTE CREACION \n");
		}
		if(!arcade_set_NombreSalon(nuevoArcade, NombreSalon))
		{
			printf("\n FALLA AL CARGAR ID SALON DURANTE CREACION \n");
		}

	}
	return nuevoArcade;
}

void arcade_delete(eArcade* ear)
{
	if(ear != NULL)
	{
		free(ear);
	}
}


int arcade_set_id(eArcade* ear,int id)
{
	int ok = 0;
	if(ear != NULL && id > -1)
	{
		ear->idArcade = id;
		ok = 1;
	}
	return ok;
}

int arcade_get_id(eArcade* ear,int* id)
{
	int ok = 0;
	if(ear != NULL && id != NULL)
	{
		*id = ear->idArcade;
		ok = 1;
	}
	return ok;
}

int arcade_set_nacionalidad(eArcade* ear,char nombre[])
{
	int ok = 0;
	if(ear != NULL && strlen(nombre) > 0)
	{
		strcpy(ear->nacionalidadArcade,nombre);
		ok = 1;
	}
	return ok;
}

int arcade_get_nacionalidad(eArcade* ear,char* nombre[])
{
	int ok = 0;
	if(ear != NULL && nombre != NULL)
	{
		strcpy(*nombre,ear->nacionalidadArcade);

		ok = 1;
	}
	return ok;
}


int arcade_set_tipoSonido(eArcade* ear,int tipo)
{
	int ok = 0;
	if(ear != NULL && tipo > -1)
	{
		ear->tipoSonido = tipo;
		ok = 1;
	}
	return ok;
}

int arcade_get_tipoSonido(eArcade* ear,int* tipo)
{
	int ok = 0;
	if(ear != NULL && tipo != NULL)
	{
		*tipo = ear->tipoSonido;
		ok = 1;
	}
	return ok;
}


int arcade_set_cantidadJugadores(eArcade* ear,int cantidad)
{
	int ok = 0;
	if(ear != NULL && cantidad > -1)
	{
		ear->cantidadJugadores = cantidad;
		ok = 1;
	}
	return ok;
}

int arcade_get_cantidadJugadores(eArcade* ear,int* cantidad)
{
	int ok = 0;
	if(ear != NULL && cantidad != NULL)
	{
		*cantidad = ear->cantidadJugadores;
		ok = 1;
	}
	return ok;
}

int arcade_set_capacidadMaxFichas(eArcade* ear,int capacidad)
{
	int ok = 0;
	if(ear != NULL && capacidad > -1)
	{
		ear->capacidadMaxFichas = capacidad;
		ok = 1;
	}
	return ok;
}

int arcade_get_capacidadMaxFichas(eArcade* ear,int* capacidad)
{
	int ok = 0;
	if(ear != NULL && capacidad != NULL)
	{
		*capacidad = ear->capacidadMaxFichas;
		ok = 1;
	}
	return ok;
}


int arcade_set_nombreJuego(eArcade* ear,char nombre[])
{
	int ok = 0;
	if(ear != NULL && strlen(nombre) > 0)
	{
		strcpy(ear->nombreJuego,nombre);
		ok = 1;
	}
	return ok;
}

int arcade_get_nombreJuego(eArcade* ear,char* nombre[])
{
	int ok = 0;
	if(ear != NULL && nombre != NULL)
	{
		strcpy(*nombre,ear->nombreJuego);
		ok = 1;
	}
	return ok;
}


int arcade_set_NombreSalon(eArcade* ear,char nombre[])
{
	int ok = 0;
	if(ear != NULL && nombre != NULL)
	{
		strcpy(ear->nombreSalon , nombre);
		ok = 1;
	}
	return ok;
}

int arcade_get_NombreSalon(eArcade* ear,char* nombre[])
{
	int ok = 0;
	if(ear != NULL && nombre != NULL)
	{
		strcpy(*nombre, ear->nombreSalon);
		ok = 1;
	}
	return ok;
}




int arcade_sort_nombre(void* idd1 , void* idd2)
{
	int resultado = 0;
	if(idd1 != NULL && idd2 != NULL)
	{
		eArcade* d1 = idd1;
	    eArcade* d2 = idd2;
	    resultado = strcmp(d1->nombreJuego,d2->nombreJuego);
	}
    return resultado;
}

int arcade_sort_nacionalidad(void* idd1 , void* idd2)
{

	int resultado = 0;
	if(idd1 != NULL && idd2 != NULL)
	{
		eArcade* d1 = idd1;
	    eArcade* d2 = idd2;
	    resultado = strcmp(d1->nacionalidadArcade,d2->nacionalidadArcade);
	}
    return resultado;
}

int arcade_sort_tipoSonido(void* d1 , void* d2)
{
    eArcade* dd1 = d1;
    eArcade* dd2 = d2;
    int id1 = dd1->tipoSonido;
    int id2 = dd2->tipoSonido;
    int retorno = 0;
    if(id1 > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id1 < id2)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int arcade_sort_nombreSalon(void* idd1 , void* idd2)
{
	int resultado = 0;
	if(idd1 != NULL && idd2 != NULL)
	{
		eArcade* d1 = idd1;
	    eArcade* d2 = idd2;
	    resultado = strcmp(d1->nombreSalon,d2->nombreSalon);
	}
    return resultado;
}


int arcade_sort_id(void* d1 , void* d2)
{
    eArcade* dd1 = d1;
    eArcade* dd2 = d2;
    int id1 = dd1->idArcade;
    int id2 = dd2->idArcade;
    int retorno = 0;
    if(id1 > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id1 < id2)
        {
            retorno = -1;
        }
    }
    return retorno;
}


int arcade_sort_jugadores(void* d1 , void* d2)
{
    eArcade* dd1 = d1;
    eArcade* dd2 = d2;
    int id1 = dd1->cantidadJugadores;
    int id2 = dd2->cantidadJugadores;
    int retorno = 0;
    if(id1 > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id1 < id2)
        {
            retorno = -1;
        }
    }
    return retorno;
}



int arcade_sort_fichaMax(void* d1 , void* d2)
{
    eArcade* dd1 = d1;
    eArcade* dd2 = d2;
    int id1 = dd1->capacidadMaxFichas;
    int id2 = dd2->capacidadMaxFichas;
    int retorno = 0;
    if(id1 > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id1 < id2)
        {
            retorno = -1;
        }
    }
    return retorno;
}





int arcade_multijugador(void* arcade)
{
	int respuesta = 0;
	if(arcade != NULL)
	{
		eArcade* e = (eArcade*) arcade;
		if(e->cantidadJugadores > 1)
		{
			respuesta = 1;
		}

	}
	return respuesta;
}




void arcade_duplicar_fichas(void* arcade)
{
	if(arcade != NULL)
	{
		eArcade* e = (eArcade*) arcade;
		e->capacidadMaxFichas *= 2;
	}
}













