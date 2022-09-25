/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA ENTRADA DE DATOS. ARCHIVO .C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*----------------------------------------------------------------------------------*/
int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	int bufferInt;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			scanf("%d", &bufferInt);//guardo el msj en la variable internat
			if(bufferInt >= minimo && bufferInt <= maximo){//valido el numero
				*pResultado = bufferInt;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char*mensajeError, float minimo, float maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	float bufferInt;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			scanf("%f", &bufferInt);//guardo el msj en la variable internat
			if(bufferInt >= minimo && bufferInt <= maximo){//valido el numero
				*pResultado = bufferInt;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getCaracter(char* pResultado, char* mensaje, char*mensajeError, char minimo, char maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	char bufferChar;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo. El min y el max esta expresado en ascii. Por ejemplo, la A es 65 y la z 122
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			fflush(stdin);//fflush
			scanf("%c", &bufferChar);//guardo el msj en la variable internat
			if(bufferChar >= minimo && bufferChar <= maximo){//valido el numero
				*pResultado = bufferChar;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getCaracterSeleccionados(char* pResultado, char* mensaje, char* mensajeError){

	int retorno = 0;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &bufferChar);
		bufferChar = toupper(bufferChar);
		*pResultado = bufferChar;
		retorno = 1;
		while(bufferChar != 'A' && bufferChar != 'C' && bufferChar != 'F' && bufferChar != 'B' && bufferChar != 'U' && bufferChar != 'O'){
			printf("ERROR! Ingrese la confederacion entre 'A' [AFC] - 'C' [CAF] - 'F' [CONCACAF] - 'B' [CONMEBOL] - 'U' [UEFA] - 'O' [OFC]: ");
			fflush(stdin);
			scanf("%c", &bufferChar);
			bufferChar = toupper(bufferChar);
			*pResultado = bufferChar;
			retorno = 1;
	    }
    }
	return retorno;
}
/*----------------------------------------------------------------------------------*/



