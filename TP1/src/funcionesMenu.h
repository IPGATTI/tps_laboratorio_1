/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : FUNCIONES MENU. ARCHIVO .H
 ============================================================================
 */

#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que mustra el menu principal
/// @param acumuladorCostoHospedaje
/// @param acumuladorCostoComida
/// @param acumuladorCostoTransporte
/// @param contadorArqueros
/// @param contadorDefensores
/// @param contadorMediocampistas
/// @param contadorDelanteros
/// @return Valor de tipo entero con la opcion elegida
int menuPrincipal(float* acumuladorCostoHospedaje, float* acumuladorCostoComida, float* acumuladorCostoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que muestra el menu de opciones para la carga de jugadores
/// @return Valor de tipo entorno con la opcion elegida
int cargarJugadoresMenu();
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que muestra el menu de opciones para la carga de gastos de mantenimiento
/// @return Valor de tipo entorno con la opcion elegida
int cargarGastosMantenimientoMenu();
/*----------------------------------------------------------------------------------*/

#endif /* FUNCIONESMENU_H_ */
