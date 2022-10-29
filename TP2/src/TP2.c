/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 29-10-2022
 University  : UTN-FRA
 Exercise    : TP2
 ============================================================================
 */

/*====================================================================
--------> LIBRARY ZONE
====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "dataWarehouse.h"
#include "confederacion.h"
#include "validaciones.h"
/*====================================================================
--------> DEFINE ZONE
====================================================================*/
#define TAM 20
#define TAM_CONF 6
/*====================================================================
--------> BEGIN OF PROGRAM
====================================================================*/
int main(void) {
	setbuf(stdout,NULL);
/*====================================================================
--------> INITIALIZATION AND DECLARATION ZONE
====================================================================*/
	char seguir = 's';
	int nextId = 1;
	int contAltas = 0;
	eJugador lista[TAM];

	eConfederacion confederaciones[TAM_CONF] = {
			{100, "CONMEBOL", "SUDAMERICA", 1916},
			{101, "UEFA", "EUROPA", 1954},
			{102, "AFC", "ASIA", 1954},
			{103, "CAF", "AFRICA", 1957},
			{104, "CONCACAF", "NORTE Y CENTROAMERICA", 1961},
			{105, "OFC", "OCEANIA", 1966}
	};
/*====================================================================
--------> MAIN PROGRAM
====================================================================*/
	if(!inicializarPersonas(lista, TAM)){
		printf("Problema al inicilizar");
	}

	hardcodearJugadores(lista, TAM, 10, &nextId);
	contAltas++;

	do{
		switch(menu()){
		case 1:
			if(!altaPersona(lista, &nextId, TAM, confederaciones, TAM_CONF)){
				printf("No se pudo realizar el alta\n");
			}
			else{
				printf("Alta exitosa\n");
			}
			break;
		case 2:
			if(contAltas != 0){
				if(!bajaPersona(lista, TAM, confederaciones, TAM_CONF)){
					printf("No se pudo realizar la baja\n");
				}
				else{
					printf("Baja exitosa\n");
				}
			}
			else{
				printf("Primero debe cargar jugadores\n");
			}
			break;
		case 3:
			if(contAltas != 0){
				if(!modificarPersona(lista, TAM, confederaciones, TAM_CONF)){
					printf("No se pudo realizar la modificacion\n");
				}
				else{
					printf("Modificacion exitosa\n");
				}
			}
			else{
				printf("Primero debe cargar jugadores\n");
			}
			break;
		case 4:
			if(contAltas != 0){
				mostrarInformes(lista, TAM, confederaciones, TAM_CONF);
			}
			else{
				printf("Primero debe cargar jugadores\n");
			}
			break;
		case 5:
			utn_getCaracterSeleccionadosConfirma(&seguir, "¿Confirma salir? S/N: ", "ERROR. ¿Confirma salir?: S/N: ");
			if(seguir == 'S'){
				seguir = 'n';
			}
			else{
				seguir = 's';
			}
			break;
		default:
			printf("Opcion Invalida!!!\n");
		}
		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
/*====================================================================
--------> END OF PROGRAM
====================================================================*/
