/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : FUNCIONES MENU. ARCHIVO .C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------*/
int menuPrincipal(float* acumuladorCostoHospedaje, float* acumuladorCostoComida, float* acumuladorCostoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros){
	int opcion;

	system("cls");
	printf("****************      MENU DE OPCIONES      ****************\n");
	printf("1. Ingreso de los costos de mantenimiento\n");
	printf("Costo de Hospedaje -> $%.2f\n", *acumuladorCostoHospedaje);
	printf("Costo de Comida -> $%.2f\n", *acumuladorCostoComida);
	printf("Costo de Transporte -> $%.2f\n", *acumuladorCostoTransporte);
	printf("2. Carga de jugadores\n");
	printf("Arqueros -> %d\n", *contadorArqueros);
	printf("Defensores -> %d\n", *contadorDefensores);
	printf("Mediocampistas -> %d\n", *contadorMediocampistas);
	printf("Delanteros -> %d\n", *contadorDelanteros);
	printf("3. Realizar todos los calculos\n");
	printf("4. Informar todos los resultados\n");
	printf("5. Salir\n");
	printf("\nIndique una opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int cargarJugadoresMenu(){
	int opcion;

		system("cls");
	printf("1. Ingresar arqueros\n");
	printf("2. Ingresar defensores\n");
	printf("3. Ingresar mediocampistas\n");
	printf("4. Ingresar delanteros\n");
	printf("Ingrese una opcion o presione otro numero para volver al menu: ");
	scanf("%d", &opcion);
		system("cls");

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int cargarGastosMantenimientoMenu(){
	int opcion;

		system("cls");
	printf("1. Ingresar gastos de hospedaje\n");
	printf("2. Ingresar gastos de comida\n");
	printf("3. Ingresar gastos de transporte\n");
	printf("Ingrese una opcion o presione otro numero para volver al menu: ");
	scanf("%d", &opcion);
		system("cls");

	return opcion;
}
/*----------------------------------------------------------------------------------*/
