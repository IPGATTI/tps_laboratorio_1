/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 25-09-2022
 University  : UTN-FRA
 Exercise    : TP1
 ============================================================================
 */

/*====================================================================
--------> LIBRARY ZONE
====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "entradaDatos.h"
#include "calculosMatematicos.h"
#include "validacionesPunteros.h"
#include "funcionesMenu.h"
/*====================================================================
--------> DEFINE ZONE
====================================================================*/
#define CANTARQ 2
#define CANTDEF 2
#define CANTMED 2
#define CANTDEL 2
#define PORCENTAJEAUMENTOUEFA 35
/*====================================================================
--------> BEGIN OF PROGRAM
====================================================================*/
int main(void) {
	setbuf(stdout,NULL);
/*====================================================================
--------> INITIALIZATION AND DECLARATION ZONE
====================================================================*/
	char seguir = 's';

	char confederacion;
	int numeroCamiseta;

	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	float acumuladorCostoHospedaje = 0;
	float acumuladorCostoComida = 0;
	float acumuladorCostoTransporte = 0;

	int contadorArqueros = 0;
	int contadorDefensores = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros = 0;

	float costoMantenimiento = 0;

	int contadorAFC = 0;
	int contadorCONMEBOL = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorUEFA = 0;
	int contadorOFC = 0;

	int totalConfederaciones = 0;

	float promedioUEFA;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioAFC;
	float promedioOFC;

	float costoMantenimientoAumentado;
	float costoMantenimientoAumentadoTotal;

	int flagCostoMantenimiento = 0;
	int flagCargaJugadores = 0;
	int flagCalculosRealizados = 0;
/*====================================================================
--------> MAIN PROGRAM
====================================================================*/
	do{
		switch(menuPrincipal(&acumuladorCostoHospedaje, &acumuladorCostoComida, &acumuladorCostoTransporte, &contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros)){
			case 1:
				switch(cargarGastosMantenimientoMenu()){
					case 1:
						if(utn_getNumeroFlotante(&costoHospedaje, "Ingrese el costo de hospedaje mayor a 0: ", "ERROR!! ", 0, 100000000000, 100)){
							printf("Costo ingresado: %.2f\n", costoHospedaje);
							acumuladorCostoHospedaje = acumuladorCostoHospedaje + costoHospedaje;
							flagCostoMantenimiento = 1;
						}
						else{
							printf("ERROR\n");
						}
					break;
					case 2:
						if(utn_getNumeroFlotante(&costoComida, "Ingrese el costo de comida mayor a 0: ", "ERROR!! ", 0, 100000000000, 100)){
							printf("Costo ingresado: %.2f\n", costoComida);
							acumuladorCostoComida = acumuladorCostoComida + costoComida;
							flagCostoMantenimiento = 1;
						}
						else{
							printf("ERROR\n");
						}
					break;
					case 3:
						if(utn_getNumeroFlotante(&costoTransporte, "Ingrese el costo de transporte mayor a 0: ", "ERROR!! ", 0, 100000000000, 100)){
							printf("Costo ingresado: %.2f\n", costoTransporte);
							acumuladorCostoTransporte = acumuladorCostoTransporte + costoTransporte;
							flagCostoMantenimiento = 1;
						}
						else{
							printf("ERROR\n");
						}
					break;
				}
				flagCalculosRealizados = 0;
			break;
			case 2:
				switch(cargarJugadoresMenu()){
					case 1:
						if(contadorArqueros < CANTARQ){
							if(utn_getNumeroEntero(&numeroCamiseta, "Ingrese el numero de la camiseta entre 1 y 22: ", "ERROR!! ", 1, 22, 100)){
								printf("Numero camiseta ingresado: %.2d\n", numeroCamiseta);
								flagCargaJugadores = 1;
							}
							else{
								printf("ERROR\n");
							}

							if(utn_getCaracterSeleccionados(&confederacion, "Ingrese la confederacion entre 'A' [AFC] - 'C' [CAF] - 'F' [CONCACAF] - 'B' [CONMEBOL] - 'U' [UEFA] - 'O' [OFC]: ", "ERROR!! ")){
								printf("Confederacion ingresda: %c\n", confederacion);
							}
							else{
								printf("ERROR\n");
							}
							contadorArqueros++;
						}
						else{
							printf("No puede ingresar mas arqueros\n");
						}
					break;
					case 2:
						if(contadorDefensores < CANTDEF){
							if(utn_getNumeroEntero(&numeroCamiseta, "Ingrese el numero de la camiseta entre 1 y 22: ", "ERROR!! ", 1, 22, 100)){
								printf("Numero camiseta ingresado: %.2d\n", numeroCamiseta);
								flagCargaJugadores = 1;
							}
							else{
								printf("ERROR\n");
							}

							if(utn_getCaracterSeleccionados(&confederacion, "Ingrese la confederacion entre 'A' [AFC] - 'C' [CAF] - 'F' [CONCACAF] - 'B' [CONMEBOL] - 'U' [UEFA] - 'O' [OFC]: ", "ERROR!! ")){
								printf("Confederacion ingresda: %c\n", confederacion);
							}
							else{
								printf("ERROR\n");
							}
							contadorDefensores++;
						}
						else{
							printf("No puede ingresar mas defensores\n");
						}
					break;
					case 3:
						if(contadorMediocampistas < CANTARQ){
							if(utn_getNumeroEntero(&numeroCamiseta, "Ingrese el numero de la camiseta entre 1 y 22: ", "ERROR!! ", 1, 22, 100)){
								printf("Numero camiseta ingresado: %.2d\n", numeroCamiseta);
								flagCargaJugadores = 1;
							}
							else{
								printf("ERROR\n");
							}

							if(utn_getCaracterSeleccionados(&confederacion, "Ingrese la confederacion entre 'A' [AFC] - 'C' [CAF] - 'F' [CONCACAF] - 'B' [CONMEBOL] - 'U' [UEFA] - 'O' [OFC]: ", "ERROR!! ")){
								printf("Confederacion ingresda: %c\n", confederacion);
							}
							else{
								printf("ERROR\n");
							}
							contadorMediocampistas++;
						}
						else{
							printf("No puede ingresar mas mediocampistas\n");
						}
					break;
					case 4:
						if(contadorDelanteros < CANTDEL){
							if(utn_getNumeroEntero(&numeroCamiseta, "Ingrese el numero de la camiseta entre 1 y 22: ", "ERROR!! ", 1, 22, 100)){
								printf("Numero camiseta ingresado: %.2d\n", numeroCamiseta);
								flagCargaJugadores = 1;
							}
							else{
								printf("ERROR\n");
							}

							if(utn_getCaracterSeleccionados(&confederacion, "Ingrese la confederacion entre 'A' [AFC] - 'C' [CAF] - 'F' [CONCACAF] - 'B' [CONMEBOL] - 'U' [UEFA] - 'O' [OFC]: ", "ERROR!! ")){
								printf("Confederacion ingresda: %c\n", confederacion);
							}
							else{
								printf("ERROR\n");
							}
							contadorDelanteros++;
						}
						else{
							printf("No puede ingresar mas delanteros\n");
						}
					break;
				}
				switch(confederacion){
					case 'A':
						contadorAFC++;
					break;
					case 'B':
						contadorCONMEBOL++;
					break;
					case 'C':
						contadorCAF++;
					break;
					case 'O':
						contadorOFC++;
					break;
					case 'U':
						contadorUEFA++;
					break;
					case 'F':
						contadorCONCACAF++;
					break;
				}
				flagCalculosRealizados = 0;
			break;
			case 3:
				if(flagCostoMantenimiento == 1 && flagCargaJugadores == 1){

					totalConfederaciones = contadorAFC + contadorCONMEBOL + contadorCAF + contadorOFC + contadorUEFA + contadorCONCACAF;

					dividir(&promedioUEFA, contadorUEFA, totalConfederaciones);
					dividir(&promedioAFC, contadorAFC, totalConfederaciones);
					dividir(&promedioOFC, contadorOFC, totalConfederaciones);
					dividir(&promedioCONMEBOL, contadorCONMEBOL, totalConfederaciones);
					dividir(&promedioCONCACAF, contadorCONCACAF, totalConfederaciones);
					dividir(&promedioCAF, contadorCAF, totalConfederaciones);

					costoMantenimiento = acumuladorCostoTransporte + acumuladorCostoComida + acumuladorCostoHospedaje;
					obtenerPorcentaje2(&costoMantenimientoAumentado, costoMantenimiento, PORCENTAJEAUMENTOUEFA);
					costoMantenimientoAumentadoTotal = costoMantenimientoAumentado + costoMantenimiento;

					printf("Los calculos fueron realizados\n");
					flagCalculosRealizados = 1;
				}
				else if(flagCostoMantenimiento == 1){
					printf("Falta cargar jugadores\n");
				}
				else if(flagCargaJugadores == 1){
					printf("Falta cargar costos de mantenimiento\n");
				}
				else{
					printf("Falta cargar jugadores y costos de mantenimiento\n");
				}
			break;
			case 4:
				if(flagCalculosRealizados == 1){
					printf("****************      RESULTADOS      ****************\n");
					printf("Promedio Uefa: %.2f\n", promedioUEFA);
					printf("Promedio Conmebol: %.2f\n", promedioCONMEBOL);
					printf("Promedio Concacaf: %.2f\n", promedioCONCACAF);
					printf("Promedio AFC: %.2f\n", promedioAFC);
					printf("Promedio OFC: %.2f\n", promedioOFC);
					printf("Promedio CAF: %.2f\n", promedioCAF);
					if(contadorUEFA > (totalConfederaciones/2) ){
						printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n", costoMantenimiento, costoMantenimientoAumentado, costoMantenimientoAumentadoTotal);
					}
					else{
						printf("Costo mantenimiento: $%.2f\n", costoMantenimiento);
					}
				}
				else{
					printf("Primero debe realizar todos los calculos\n");
				}
			break;
			case 5:
				seguir = 'n';
			break;
			default:
				printf("Opcion invalida\n");
		}
		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
/*====================================================================
--------> END OF PROGRAM
====================================================================*/
