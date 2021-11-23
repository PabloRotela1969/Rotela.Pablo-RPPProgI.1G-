/*
 * parser.h
 *
 *  Created on: 21 nov. 2021
 *      Author: MI COMPU
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Arcade.h"

/**
 * @brief permite cargar un LinkedList con el contenido de un archivo
 *
 * @param pFile ruta completa y nombre de archivo que contiene datos a cargar
 * @param pArrayList lista a llenar
 * @return 1 = operación terminada exitosamente, 0 = operación terminada con errores
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList);

#endif /* PARSER_H_ */
