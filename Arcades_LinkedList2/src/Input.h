/*
 * Input.h
 *
 *  Created on: 20 nov. 2021
 *      Author: MI COMPU
 */

#ifndef INPUT_H_
#define INPUT_H_

/**
 * @brief permite ingresar por teclado sólo enteros
 *
 * @param mensaje cartel indicador de para que se ingresa
 * @return numeros enteros
 */
int inputInt(char mensaje[]);

/**
 * @brief permite ingresar por teclado un solo carácter
 *
* @param mensaje cartel indicador de para que se ingresa
 * @return un caracter
 */
char inputChar(char mensaje[]);

/**
 * @brief permite ingresar por teclado caracteres pero validando que estén dentro de un rango determinado
 *
 * @param mensaje cartel indicador de para que se ingresa
 * @param posibles rango de caracteres aceptados
 * @return un caracter validado
 */
char inputCharPosibles(char mensaje[], char posibles[]);

/**
 * @brief permite ingresar una cadena de caracteres
 *
* @param mensaje cartel indicador de para que se ingresa
 * @param salida la cadena de caracteres ingresada
 * @param tam la cantidad de caracteres que contiene la cadena
 */
void inputString(char mensaje[], char salida[], int tam);

/**
 * @brief permite ingresar un numero por teclado y validarlo contra un rango de numeros
 *
 * @param mensaje cartel indicador de para que se ingresa
 * @param desde inicio del rango
 * @param hasta fin del rango
 * @return numero validado
 */
int inputIntDesdeHasta(char mensaje[], int desde,int hasta);


#endif /* INPUT_H_ */
