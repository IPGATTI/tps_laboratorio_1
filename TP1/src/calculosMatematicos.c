/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA CALCULOS MATEMATICOS. ARCHIVO .C
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------*/
void mostrarFlotante(float numeroFlotante){

	printf("El numero flotante es: %.2f", numeroFlotante);
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int determinarParidad(int numero){

	int resultado;

	if(numero %2 == 0){
		resultado = 1;
	}
	else{
		resultado = 0;
	}

	return resultado;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int ingresarRetornarEntero(void){

	int resultado;

	printf("Ingrese un numero entero: ");
	scanf("%d", &resultado);

	return resultado;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int duplicar(int valor){
	int resultado;

	resultado = valor * 2;

	return resultado;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int duplicarRef(int* pValor){
	 int todoOk = 0;
	 if(pValor != NULL){
		 *pValor = *pValor * 2;
		 todoOk = 1;
	 }
	 return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int dividir(float* p, int dividendo, int divisor)
{
	 int todoOk = 0;//esta me retorna si esta mal

	 if(p != NULL && divisor != 0){
		 *p =(float) dividendo / divisor;//el resultado de la division lo escribo en la direccion de la variable
		 todoOk = 1;//esto me retorno si esta todo ok
	 }
	 return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int obtenerPorcentaje2(float* pValor, float valorParaCalcular, int porcentaje){
	int todoOk = 0;
	if(pValor != NULL){
		*pValor = valorParaCalcular * porcentaje / 100;
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/


