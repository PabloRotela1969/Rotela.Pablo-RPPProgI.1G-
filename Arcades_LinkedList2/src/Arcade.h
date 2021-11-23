/*
 * Arcade.h
 *
 *  Created on: 20 nov. 2021
 *      Author: MI COMPU
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "Input.h"
#include "LinkedList.h"

typedef struct {
  int idArcade;
  char nacionalidadArcade[30];
  int tipoSonido;
  int cantidadJugadores;
  int capacidadMaxFichas;
  char nombreJuego[64];
  char nombreSalon[30];
}eArcade;

/**
 * @brief instancia todos los campos a valores por defecto "" los string y 0 los numéricos
 *
 * @return un nuevo puntero a estructura listo para cargar
 */
eArcade* arcade_new_();

/**
 * @brief setter del ID de Arcade
 *
 * @param ear es el arcade
 * @param id el id que se e quiere asignar
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_id(eArcade* ear,int id);

/**
 * @brief getter del id
 *
 * @param ear es el arcade
 * @param id el id que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_id(eArcade* ear,int* id);

/**
 * @brief setter de la nacionalidad
 *
 * @param ear es el arcade
 * @param nombre  que se e quiere asignar
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_nacionalidad(eArcade* ear,char nombre[]);

/**
 * @brief getter de la nacionalidad
 *
 * @param ear es el arcade
 * @param nombre  que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_nacionalidad(eArcade* ear,char* nombre[]);

/**
 * @brief setter del tipo de sonido
 *
 * @param ear es el arcade
 * @param tipo  que se e quiere asignar
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_tipoSonido(eArcade* ear,int tipo);

/**
 * @brief getter del tipo de sonido
 *
 * @param ear es el arcade
 * @param tipo  que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_tipoSonido(eArcade* ear,int* tipo);

/**
 * @brief setter de cantidad de jugadores
 *
 * @param ear es el arcade
 * @param cantidad  que se e quiere establecer
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_cantidadJugadores(eArcade* ear,int cantidad);

/**
 * @brief getter de cantidad de jugadores
 *
 * @param ear es el arcade
 * @param cantidad  que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_cantidadJugadores(eArcade* ear,int* cantidad);

/**
 * @brief setter de cantidad máxima de fichas del arcade
 *
 * @param ear es el arcade
 * @param capacidad  que se e quiere establecer
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_capacidadMaxFichas(eArcade* ear,int capacidad);

/**
 * @brief getter de cantidad máxima de fichas del arcade
 *
 * @param ear es el arcade
 * @param capacidad  que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_capacidadMaxFichas(eArcade* ear,int* capacidad);

/**
 * @brief setter del nombre de juego
 *
 * @param ear es el arcade
 * @param nombre  que se e quiere establecer
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_nombreJuego(eArcade* ear,char nombre[]);

/**
 * @brief getter del nombre de juego
 *
 * @param ear es el arcade
 * @param nombre  que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_nombreJuego(eArcade* ear,char* nombre[]);

/**
 * @brief  setter del nombre del salón
 *
 * @param ear es el arcade
 * @param nombre  que se e quiere establecer
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_set_NombreSalon(eArcade* ear,char nombre[]);

/**
 * @brief  getter del nombre del salón
 *
 * @param ear es el arcade
 * @param nombre  que se e quiere obtener
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
int arcade_get_NombreSalon(eArcade* ear,char* nombre[]);

/**
 * @brief constructor de nuevo arcade, primero prepara el arcade con arcade_new_ , usando los setters, carga cada campo de la estructura
 *
 * @param id es por donde se individualiza a cada arcade
 * @param nacionalidad origen
 * @param tipoSonido tipo MONO o STEREO
 * @param cantidadJugadores cantidad máxima de jugadores
 * @param capacidadMaxFichas cantidad máxima de fichas
 * @param nombre nombre del juego
 * @param NombreSalon nombre del salon
 * @return 1 = operación exitosa, 0 = problema en los parámetros
 */
eArcade* arcade_new(int id, char nacionalidad[], int tipoSonido, int cantidadJugadores, int capacidadMaxFichas, char nombre[], char NombreSalon[]);

/**
 * @brief permite eliminar un arcade en memoria
 *
 * @param ear el arcade
 */
void arcade_delete(eArcade* ear );

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por nombre de juego
 * @param idd1 primer arcade
 * @param idd2 segundo arcade
 * @return 1 = si idd1 > idd2 , 0 = si idd1 = idd2 , -1 = si idd1 < idd2
 */
int arcade_sort_nombre(void* idd1 , void* idd2);

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por nacionalidad
 * @param idd1 primer arcade
 * @param idd2 segundo arcade
 * @return 1 = si idd1 > idd2 , 0 = si idd1 = idd2 , -1 = si idd1 < idd2
 */
int arcade_sort_nacionalidad(void* idd1 , void* idd2);

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por tipo de sonido
 * @param idd1 primer arcade
 * @param idd2 segundo arcade
 * @return 1 = si idd1 > idd2 , 0 = si idd1 = idd2 , -1 = si idd1 < idd2
 */
int arcade_sort_tipoSonido(void* idd1 , void* idd2);

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por nombre de salon
 * @param idd1 primer arcade
 * @param idd2 segundo arcade
 * @return 1 = si idd1 > idd2 , 0 = si idd1 = idd2 , -1 = si idd1 < idd2
 */
int arcade_sort_nombreSalon(void* idd1 , void* idd2);

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por id
 * @param d1 primer arcade
 * @param d2 segundo arcade
 * @return 1 = si d1 > d2 , 0 = si d1 = d2 , -1 = si d1 < d2
 */
int arcade_sort_id(void* d1 , void* d2);

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por cantidad de jugadores
 * @param d1 primer arcade
 * @param d2 segundo arcade
 * @return 1 = si d1 > d2 , 0 = si d1 = d2 , -1 = si d1 < d2
 */
int arcade_sort_jugadores(void* d1 , void* d2);

/**
 * @brief función que por puntero se usa para ordenar
 *        se usa comparando cada arcade por cantidad de fichas
 * @param d1 primer arcade
 * @param d2 segundo arcade
 * @return 1 = si d1 > d2 , 0 = si d1 = d2 , -1 = si d1 < d2
 */
int arcade_sort_fichaMax(void* d1 , void* d2);



/**
 * @brief función que se usa en puntero dentro de ll_filter
 *        recibe un arcade y lo hace eligible si tiene más de un jugador, PUNTO 7
 * @param arcade el arcade en cuestión
 * @return
 */
int arcade_multijugador(void* arcade);

/**
 * @brief función que se usa en puntero dentro de informes_generar_archivo_multijugador
 *        recibe un arcade y le duplica la cantidad de fichas PUNTO 8
 * @param arcade el arcade en cuestión
 */
void arcade_duplicar_fichas(void* arcade);

#endif /* ARCADE_H_ */
