/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA FUNCIONES PARA HARDCODEO DE DATOS. ARCHIVO .H
 ============================================================================
 */

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_
#include "jugador.h"

/*----------------------------------------------------------------------------------*/
/// @brief Hardcodeo de datos
/// @param Vector de estructura jugadores
/// @param Tamaño del array
/// @param Cantidad de datos que quiero cargar en el array.
/// Supongamos que tengo el array de 10, pero quiero cargar 4 datos
/// @param La id que va autoincrementadose. Le entrego la ID que corresponda
/// y me suma + 1.
/// @return Me devuelve -1 si rompio la funcion o la cantidad de personas que harcodeo
int hardcodearJugadores(eJugador lista[], int tam, int cant, int* pId);
/*----------------------------------------------------------------------------------*/

#endif /* DATAWAREHOUSE_H_ */

