/*
 * Controller_Arcades.h
 *
 *  Created on: 21 nov. 2021
 *      Author: MI COMPU
 */

#ifndef CONTROLLER_ARCADES_H_
#define CONTROLLER_ARCADES_H_
#include "LinkedList.h"
#include "Input.h"
#include "Arcade.h"
#include "parser.h"
#include "Informes.h"

/**
 * @brief permite mostrar un solo arcade con todos sus campos espaciados en pantalla
 *
 * @param uno el el puntero a estructura con el arcade
 */
void controller_arcade_list(eArcade* uno );

/**
 * @brief permite mostrar la lista de arcades
 *
 * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_arcades_list(LinkedList* pArrayListArcades);

/**
 * @brief permite cargar un archivo a la linkedlist
 *
 * @param path ruta y nombre completo del archivo a cargar
 * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcades);

/**
 * @brief todo el programa transcurre dentro de este menú interactivo
 *
 * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_menu_arcades( LinkedList* pArrayListArcades);

/**
 * @brief permite agregar una nueva estructura de arcade a la lista, el id se calcula a partir de controller_arcade_max_id
 *        se le da la opción al usuario de confirmar o cancelar el proceso
 * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null, 2 = operación cancelada por el usuario
 */
int controller_arcade_add(LinkedList* pArrayListArcades);

/**
 * @brief permite editar un item seleccionándolo por su ID, luego se pregunta qué campo se necesita cambiar
 *        si lo que se cambia es el nombre del juego, se muestra una lista sin repeticiones de los juegos ya existentes
 *        se le da la opción al usuario de confirmar o cancelar el proceso
  * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null, 2 = operación cancelada por el usuario
 */
int controller_arcade_edit(LinkedList* pArrayListArcades);

/**
 * @brief permite borrar un item seleccionándolo por su ID,
 *        se le da la opción al usuario de confirmar o cancelar el proceso
 *
  * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null, 2 = operación cancelada por el usuario
 */
int controller_arcade_delete(LinkedList* pArrayListArcades);

/**
 * @brief toma la lista actual e iterando por los ID de los arcades, calcula el máximo y le suma 1
 *
  * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_arcade_max_id(LinkedList* pArrayListArcades);

/**
 * @brief entrega una lista de juevos sin repeticiones, se clona la lista principal y se ordena por nombre de juego
 *        luego de hace un corte de control guardando en la lista de salida, cada nombre distinto que se vaya leyendo
 *
  * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
LinkedList* controller_arcade_mostrar_juegos_cargados_sin_repetir(LinkedList* pArrayListArcades);

/**
 * @brief permite salvar la lista principal a archivo .csv
 *
 * @param path ruta y nombre completo del archivo a cargar
 * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_saveAsText(char* path , LinkedList* pArrayListArcades);

/**
 * @brief usando punteros a funciones, permite ordenar por cada campo y el sentido que el usuario ingrese por submenú
 *        los punteros a función están en la biblioteca arcade
* @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_arcades_sort(LinkedList* pArrayListArcades);

/**
 * @brief función especializada en salvar el archivo resultado de extraer la lista sin repeticiones de juegos de arcades
 *
 * @param h ruta y nombre completo del archivo a cargar
 * @param pArrayListArcades linkedlist de arcades
 * @return 1 = si fue exitoso, 0 = con problemas como la lista en null
 */
int controller_save_Lista_juegosAsText(char* path , LinkedList* lista);



#endif /* CONTROLLER_ARCADES_H_ */
