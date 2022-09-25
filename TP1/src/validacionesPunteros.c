/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA VALIDACIONES CON PUNTEROS. ARCHIVO .C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------*/
int validarEdadLaboral(int* pEdad, int valor){
	int todoOk = 0;
	if(pEdad != NULL && (valor >= 18 && valor <= 65 )){
		*pEdad = valor;
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int validarRangoEntero(int* pEdad, int valor, int min, int max){
	int todoOk = 0;
	if(pEdad != NULL && (valor >= min && valor <= max )){
		*pEdad = valor;
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/
