/*
 ============================================================================
 Name        : Arcades_LinkedList.c
 Author      : Pablo F. Rotela
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : gestión e informes de Arcades
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include"Controller_Arcades.h"


int main(void) {
	setbuf(stdout, NULL);

    LinkedList* listaArcades = ll_newLinkedList();
    controller_menu_arcades(listaArcades);

	return EXIT_SUCCESS;
}
