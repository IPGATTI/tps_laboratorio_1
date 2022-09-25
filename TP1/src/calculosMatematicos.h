/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA CALCULOS MATEMATICOS. ARCHIVO .H
 ============================================================================
 */

#ifndef CALCULOSMATEMATICOS_H_
#define CALCULOSMATEMATICOS_H_

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que muestra un flotante
/// @param Recibe como parametro un valor de tipo flotante
void mostrarFlotante(float numeroFlotante);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que determina si un numero entero es par o impar
/// @param Recibe como parametro un valor de tipo entero
/// @return Retorna 1 en el caso de que sea par y retorna 0 en el caso que sea impar
int determinarParidad(int numero);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que solicita el ingreso de un entero al usuario y lo retorna
/// @return Retorna el entero introducido por el usuario
int ingresarRetornarEntero(void);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recibe como parametro un valor de tipo entero y lo duplica
/// @param Recibe como parametro un valor de tipo entero
/// @return Retorna el valor del entero duplicado
int duplicar(int valor);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recibe como parametro un puntero de tipo entero y lo duplica
/// @param Recibe como parametro un puntero de tipo entero
/// @return Valor duplicado del valor pasado por puntero
int duplicarRef(int* pValor);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que divide un numero
/// @param Puntero tipo flotante donde se va guardar el resultado de la operacion
/// @param dividendo tipo entero
/// @param divisor tipo entero
/// @return Valor tipo flotante como resultado de la division
int dividir(float* p, int dividendo, int divisor);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Calcula el porcentaje un numero
/// @param Puntero tipo flotante
/// @param Variable tipo flotante del valor a aumentar
/// @param porcentaje
/// @return Valor tipo flotante guardado en el puntero
int obtenerPorcentaje2(float* pValor, float valorParaCalcular, int porcentaje);
/*----------------------------------------------------------------------------------*/

#endif /* CALCULOSMATEMATICOS_H_ */
