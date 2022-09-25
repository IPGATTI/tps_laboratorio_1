/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA ENTRADA DE DATOS. ARCHIVO .H
 ============================================================================
 */

#ifndef ENTRADADATOS_H_
#define ENTRADADATOS_H_

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo entero entre rangos y la valida
/// @param Puntero tipo int a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo int en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo flotante entre rangos y la valida
/// @param Puntero tipo float a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo float en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char*mensajeError, float minimo, float maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo char entre rangos y la valida
/// @param Puntero tipo char a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo char en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getCaracter(char* pResultado, char* mensaje, char*mensajeError, char minimo, char maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo char de determinado valor y la valida
/// @param Puntero tipo char a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @return Guarda un valor tipo char en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getCaracterSeleccionados(char* pResultado, char* mensaje, char* mensajeError);
/*----------------------------------------------------------------------------------*/

#endif /* ENTRADADATOS_H_ */
