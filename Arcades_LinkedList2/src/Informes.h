/*
 * Informes.h
 *
 *  Created on: 22 nov. 2021
 *      Author: MI COMPU
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "LinkedList.h"
#include "Input.h"
#include "Arcade.h"
#include "parser.h"
#include"Controller_Arcades.h"

/**
 * @brief permite generar un archivo a disco con todos los archivos que tienen más de 1 jugador PUNTO 7
 *
 * @param pArrayListArcades lista de arcades
 * @return lo que devuelve el controller_saveAsText
 */
int informes_generar_archivo_multijugador( LinkedList* pArrayListArcades);

/**
 * @brief duplica la cantidad de fichas de cada arcade en la lista en memoria PUNTO 8
 *
 * @param pArrayListArcades listado con los arcades cargados
 * @return invierte lo que devuelve el ll_map
 */
int informes_duplicar_fichas( LinkedList* pArrayListArcades);

/**
 * @brief SUBMENÚ con los puntos que asumo son de informes
 *
 * @param pArrayListArcades listado con los arcades cargados
 * @return 1 = operación terminada exitosamente, 0 = errores
 */
int informes_menu_informes( LinkedList* pArrayListArcades);


#endif /* INFORMES_H_ */
