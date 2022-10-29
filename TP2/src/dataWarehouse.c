/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA FUNCIONES PARA HARDCODEO DE DATOS. ARCHIVO .C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"

char nombresJugadores[10][20] = {
		"Didier Drogba",
		"Frank Lampard",
		"Hernan Crespo",
		"Roberto Carlos",
		"Zinedine Zidane",
		"Schweinsteiger",
		"Son Heung min",
		"Radamel Falcao",
		"Gianluigi Buffon",
		"Fabio Cannavaro"
};

char posiciones[10][20] = {
		"DELANTERO",
		"MEDIOCAMPISTA",
		"DELANTERO",
		"DEFENSOR",
		"MEDIOCAMPISTA",
		"MEDIOCAMPISTA",
		"MEDIOCAMPISTA",
		"DELANTERO",
		"ARQUERO",
		"DEFENSOR"
};

short numerosCamiseta[10] = {9,15,11,4,8,7,16,18,1,2};

int idConfederaciones[10] = {100,102,101,102,101,101,101,104,102,105};

float salarios[10] = {8000.56,10000.27,17258.15,24124.71,15000,19000,10141.71, 10452,20030, 38152.92};

short aniosContratos[10] = {2,6,3,5,1,3,1,5,7,5};

/*----------------------------------------------------------------------------------*/
int hardcodearJugadores(eJugador lista[], int tam, int cant, int* pId){
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){
		/*valido tambien que el tamaño de los datos a pedir sea mayor a 0
		y menor o igual al tamaño del vector. Si a mi me pasan un vector de 50
		y cargo 60 datos, lo estoy desbordando. Y tambien valido el puntero pId
		!= a null*/
		contador = 0;
		for(int i = 0; i < cant; i++){
			lista[i].id = *pId;//con astericos accedo al valor del ID
			*pId = *pId + 1; //luego le sumo + 1
			strcpy(lista[i].nombre, nombresJugadores[i]);
			strcpy(lista[i].posicion, posiciones[i]);
			lista[i].numeroCamiseta = numerosCamiseta[i];
			lista[i].idConfederacion = idConfederaciones[i];
			lista[i].salario = salarios[i];
			lista[i].aniosContrato = aniosContratos[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
/*----------------------------------------------------------------------------------*/
