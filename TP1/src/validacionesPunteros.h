/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA VALIDACIONES CON PUNTEROS. ARCHIVO .H
 ============================================================================
 */

#ifndef VALIDACIONESPUNTEROS_H_
#define VALIDACIONESPUNTEROS_H_

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que valida un entero entre dos rangos
/// @param Recibe como parametro un puntero de tipo entero
/// @param Recibe como parametro un valor de tipo entero
/// @return Retorna un valor de tipo entero
int validarEdadLaboral(int* pEdad, int valor);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que valida un entero entre rangos
/// @param Puntero de tipo entero
/// @param Valor de tipo entero a validar
/// @param Minimo del rango de tipo entero
/// @param Maximo del rango de tipo entero
/// @return Valor validado de tipo entero
int validarRangoEntero(int* pEdad, int valor, int min, int max);
/*----------------------------------------------------------------------------------*/


#endif /* VALIDACIONESPUNTEROS_H_ */
