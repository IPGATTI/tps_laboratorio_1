/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA FUNCIONES DE ESTRUCTURA JUGADOR. ARCHIVO .C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "confederacion.h"
#include "validaciones.h"

/*----------------------------------------------------------------------------------*/
int altaPersona(eJugador lista[], int* pId, int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int indice;
	eJugador auxPersona;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("      *** Alta Jugador ***\n\n");
		indice = buscarLibre(lista, size);//llamamos a la funcion buscar libre, que nos garantiza que la estructura esta vacia
		if(indice == -1){
			printf("No hay lugar\n");
		}
		else{
			auxPersona.id = *pId;//aca agarramos el valo del id en el main y se lo designamos a la persona
			*pId = *pId + 1;//lo incrementamos +1, haciendo el id autoincrementable

			utn_getNombre(auxPersona.nombre, 20, "Ingrese nombre: ", "ERROR. ", 100000);

			switch(menuPosicion()){
				case 1:
					strcpy(auxPersona.posicion, "ARQUERO");
					break;
				case 2:
					strcpy(auxPersona.posicion, "DEFENSOR");
					break;
				case 3:
					strcpy(auxPersona.posicion, "MEDIOCAMPISTA");
					break;
				case 4:
					strcpy(auxPersona.posicion, "DELANTERO");
					break;
				default:
					printf("Opcion invalida");
					break;
			}

			utn_getNumeroShort(&auxPersona.numeroCamiseta, "Ingrese numero camiseta entre 1 y 30: ", "ERROR. ",1, 30, 100000);

			mostrarConfederaciones(confederaciones, size_conf);
			utn_getNumeroInt( &auxPersona.idConfederacion, "Ingrese id confederacion entre 100 y 105: ", "ERROR. ", 100, 105, 100000);

			utn_getNumeroFlotante(&auxPersona.salario, "Ingrese salario entre USD 10.000 y 50.000: ", "ERROR. ", 10000, 50000, 100000);

			utn_getNumeroShort(&auxPersona.aniosContrato, "Ingrese años de contrato entre 1 y 10: ", "ERROR. ",1, 10, 100000);

			auxPersona.isEmpty = 0;//cambiamos el estado del isEmpey, ya que ya hemos cargado los datos.

			lista[indice] = auxPersona;//cargamos todos los datos en el indice de la estructura

			todoOk = 1;
		}
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int bajaPersona(eJugador lista[],int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("   *** Baja Jugador ***\n"); //pedimos al usuario que el ingresa el id que quiere dar de bajo
		mostrarPersonas(lista, size, confederaciones, size_conf);
		printf("Ingrese id: ");
		scanf("%d", &id);//lo guardamos en una variable

		indice = buscarPersonaId(lista, id, size);//llamos a la funcion que nos devuelve el valor del indice en caso de que haya
		//encontrado el id
		if(indice == -1){
			printf("ID incorrecto. No existe el ID %d\n", id);
		}
		else{
			mostrarPersona(lista[indice], confederaciones, size_conf);
			utn_getCaracterSeleccionadosConfirma(&confirma, "¿Confirma baja? S/N: ", "ERROR. ¿Confirma baja?: S/N: ");
			if(confirma == 'S'){//en caso de confirme, pongo el isEmpty en 1, como diciendo que esta vacio que en caso de consultas
				//no me muestra datos, pero si quiero ingresar un nuevo usuario me lo pise
				lista[indice].isEmpty = 1;
				todoOk = 1;
			}
			else{
				printf("Baja cancelada por el usuario\n");
			}
		}
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int buscarLibre(eJugador lista[], int size){
	int indice = -1;
	if(lista != NULL && size > 0){
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == 1){
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int buscarPersonaId(eJugador lista[],int Id, int size){
	int indice = -1;
	if(lista != NULL && size > 0){
		for(int i = 0; i < size; i++){
			if(!lista[i].isEmpty && lista[i].id == Id){
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int inicializarPersonas(eJugador lista[], int size){
	int todoOk = 0;
	if(lista != NULL && size > 0){
		for(int i = 0; i < size; i++){
			lista[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int menu(){
	int opcion;

	system("cls");
	printf("         *** ABM Jugadores ***     \n");
	printf("1- Alta jugador\n");
	printf("2- Baja jugador\n");
	printf("3- Modificacion del jugador\n");
	printf("4- Informes\n");
	printf("5- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
void mostrarPersona(eJugador p, eConfederacion confederaciones[], int size_conf){
	char descConfederacion[20];

	if(cargarDescripcionConfederacion(confederaciones, size_conf, p.idConfederacion, descConfederacion) == 1){
	//Es buscar persona por id, es exacamente lo mismo
	// le voy a pasar el array de localidades, el tamaño, le paso el id de la localidad
	//esta funcion va a buscar en el array si hay alguna localidad con ese id y si la encuentra
	//le copia en el vector de caracteres (al ser un array el pasaje lo hace por referencia)
	//de esta forma el vector descLocalidad quede cargado
	printf("│  %2d  │  %20s    │   %15s   │    %2d      │  %8.2f  │  %13s │      %2d        │\n",
			p.id,
			p.nombre,
			p.posicion,
			p.numeroCamiseta,
			p.salario,
			descConfederacion,//y aca yo mustro el vector cargado con la funcoin cargar descripcion
			//en vez de mostrar 1001, va voy a mostrar Lanus por ejemplo
			p.aniosContrato
		   );
	}
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int mostrarPersonas(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 1;
	int flag = 1;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		/*system("cls");*/
		printf("                                               ***** Lista de jugadores *****     \n");
		printf("=====================================================================================================================\n");
		printf("│  ID  │         NOMBRE           │       POSICION      │ N°CAMISETA │   SUELDO   │ CONFEDERACION  │ ANIOS CONTRATO │\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == 0){
				mostrarPersona(lista[i], confederaciones, size_conf);
				flag = 0;
			}
		}
		if(flag == 1){
			printf("No hay jugadores para mostrar\n");
		}
		printf("======================================================================================================================\n");
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int menuModificar(){
	int opcion;
	printf("Ingrese el dato que desea modificar: \n");
	printf("1- Nombre\n");
	printf("2- Posicion\n");
	printf("3- Numero Camiseta\n");
	printf("4- Confederacion\n");
	printf("5- Salario\n");
	printf("6- Anios contrato\n");
	printf("7- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int menuPosicion(){
	int opcion;
	printf("Ingrese el dato que desea modificar: \n");
	printf("1- ARQUERO\n");
	printf("2- DEFENSOR\n");
	printf("3- MEDIOCAMPISTA\n");
	printf("4- DELANTERO\n");
	utn_getNumeroInt(&opcion, "Ingrese numero entre 1 y 4: ", "ERROR. ", 1, 4, 100000);

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int modificarPersona(eJugador lista[],int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int indice;
	int id;
	int flag = 0;
	char confirma;
	char auxNombre[50];
	char auxPosicion[50];
	short auxNumeroCamiseta;
	int auxConfederacion;
	float auxSalario;
	short auxAniosContrato;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("   *** Modificar Jugador ***\n");
		mostrarPersonas(lista, size, confederaciones, size_conf);
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarPersonaId(lista, id, size);//Llama a la funcion buscar persona id

		if(indice == -1){
			printf("ID incorrecto. No existe el ID %d\n", id);
		}
		else{
			printf("                                     ***** Datos del jugador ingresado: *****                                      \n");
			printf("=====================================================================================================================\n");
			printf("│  ID  │         NOMBRE           │       POSICION      │ N°CAMISETA │   SUELDO   │ CONFEDERACION  │ ANIOS CONTRATO │\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			mostrarPersona(lista[indice], confederaciones, size_conf);//llamo a la funcion para mostrar la persona a modificar ls odatos

			utn_getCaracterSeleccionadosConfirma(&confirma, "¿Confirma modificacion? S/N: ", "ERROR. ¿Confirma modificacion?: S/N: ");

			if(confirma == 'S'){
				switch(menuModificar()){
					case 1:
						utn_getNombre(auxNombre, 20, "Ingrese nombre: ", "ERROR. ", 100000);
						strcpy(lista[indice].nombre, auxNombre);
						break;
					case 2:
						switch(menuPosicion()){
							case 1:
								strcpy(auxPosicion, "ARQUERO");
								break;
							case 2:
								strcpy(auxPosicion, "DEFENSOR");
								break;
							case 3:
								strcpy(auxPosicion, "MEDIOCAMPISTA");
								break;
							case 4:
								strcpy(auxPosicion, "DELANTERO");
								break;
							default:
								printf("Opcion invalida");
								break;
						}
						strcpy(lista[indice].posicion, auxPosicion);
						break;
					case 3:
						utn_getNumeroShort(&auxNumeroCamiseta, "Ingrese numero camiseta entre 1 y 30: ", "ERROR. ",1, 30, 100000);
						lista[indice].numeroCamiseta = auxNumeroCamiseta;
						break;
					case 4:
						mostrarConfederaciones(confederaciones, size_conf);
						utn_getNumeroInt( &auxConfederacion, "Ingrese id confederacion entre 100 y 105: ", "ERROR. ", 100, 105, 100000);
						lista[indice].idConfederacion = auxConfederacion;
						break;
					case 5:
						utn_getNumeroFlotante(&auxSalario, "Ingrese salario entre USD 10.000 y 50.000: ", "ERROR. ", 10000, 50000, 100000);
						lista[indice].salario = auxSalario;
						break;
					case 6:
						utn_getNumeroShort(&auxAniosContrato, "Ingrese años de contrato entre 1 y 10: ", "ERROR. ",1, 10, 100000);
						lista[indice].salario = auxAniosContrato;
						break;
					default:
						printf("Opcion Invalida!!!\n");
						flag = 1;
					}
					todoOk = 1;
					if(flag == 1){
						todoOk = 0;
					}
			}
			else{
				printf("Se ha cancelado la modificacion\n");
			}
		}
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*====================================================================
--------> INFORMES
====================================================================*/

/*----------------------------------------------------------------------------------*/
int menuInformes(){
	int opcion;
	printf("    ***** INFORMES *****   \n");
	printf("1- Listado jugadores\n");
	printf("2- Listado confederaciones\n");
	printf("3- Salarios\n");
	printf("4- Confederacion con mayor cantidad de anios de contrato \n");
	printf("5- Porcentaje jugadores por region\n");
	printf("6- Region con mas jugadores\n");
	printf("7- Volver al menu\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int mostrarInformes(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		switch(menuInformes()){
			case 1:
				//OPCION 1:Listado jugadores ordenados alfabeticamente por nombre confederacion y nombre jugador
				ordenarPersonasConfederacionNombreAlfabeticamente(lista, size, confederaciones, size_conf);
				mostrarPersonas(lista, size, confederaciones, size_conf);
				break;
			case 2:
				//OPCION 2: Listado de confederaciones con sus jugadores
				informarConfederacionesConJugadores(lista, size, confederaciones, size_conf);
				break;
			case 3:
				//OPCION 3: Total y promedio de salarios y listado de jugadores que superan ese salario.
				informarTotalPromedioSalarios(lista, size);
				break;
			case 4:
				//OPCION 4: INFORMAR CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL
				informarConfederacionMayorCantidadAniosContratoTotal(lista, size, confederaciones, size_conf);
				break;
			case 5:
				//OPCION 5: INFORMAR PORCENTAJE DE JUGADORES POR CADA CONFEDERACION
				informarPorcentajeJugadoresPorConfederacion(lista, size, confederaciones, size_conf);
				break;
			case 6:
				//OPCION 6: INFORMAR REGION CON MAS JUGADORES Y LISTADOS DE LOS MISMOS
				informarRegionConMasJugadoresListar(lista, size, confederaciones, size_conf);
				break;
			case 7:
				//OPCION 7: SALIR
				printf("Volvio al menu\n");
				break;
			default:
				printf("Opcion Invalida!!!\n");
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 1:Listado jugadores ordenados alfabeticamente por nombre confederacion y nombre jugador
int ordenarPersonasConfederacionNombreAlfabeticamente(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	eJugador auxJugador;
	char descConfederacionI[20];//variable para la funcion cargarDescripcionConfederacion
	char descConfederacionJ[20];//variable para la funcion cargarDescripcionConfederacion
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		for(int i = 0; i < size-1; i++){
			for(int j = i+1; j < size; j++){
				cargarDescripcionConfederacion(confederaciones, size_conf, lista[i].idConfederacion, descConfederacionI);//llamo a la funcion para que me cargue segun la id la descripcion
				cargarDescripcionConfederacion(confederaciones, size_conf, lista[j].idConfederacion, descConfederacionJ);//llamo a la funcion para que me cargue segun la id la descripcion
				if( strcmp(descConfederacionI, descConfederacionJ) > 0//ordeno por doble criterio
				 || (strcmp(descConfederacionI, descConfederacionJ) == 0
				 && strcmp(lista[i].nombre, lista[j].nombre) > 0)	){
				   	auxJugador = lista[i];
					lista[i] = lista[j];
					lista[j] = auxJugador;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 2:Listado de confederaciones con sus jugadores
int mostrarPersonasIdConfederacion(int idConfederacion, eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	char descConfederacion[20];
	int flag = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		printf("=====================================================================================================================\n");
		printf("│  ID  │         NOMBRE           │       POSICION      │ N°CAMISETA │   SUELDO   │ CONFEDERACION  │ ANIOS CONTRATO │\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == 0 && lista[i].idConfederacion == idConfederacion){//verificamos que el vector este cargado y el sexo
				mostrarPersona(lista[i], confederaciones, size_conf);//llamamamos ala funcio nmostrar persona
				flag = 1;
			}
		}
		if(flag == 0){
			cargarDescripcionConfederacion(confederaciones, size_conf, idConfederacion, descConfederacion);
			printf("No hay personas en %s\n", descConfederacion);
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 2:Listado de confederaciones con sus jugadores
int informarConfederacionesConJugadores(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                                            ***** Jugadores por cada confederacion *****   \n");
		for(int i = 0; i < size_conf; i++){//recorro el vector localidad
				printf("\n");//imprimo el nombre de cada localidad
				printf("CONFEDERACION: %s\n", confederaciones[i].nombre);//imprimo el nombre de cada localidad
				mostrarPersonasIdConfederacion(confederaciones[i].id, lista, size, confederaciones, size_conf);//llamo a esta funcion
				printf("=====================================================================================================================\n");
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/
//OPCION 3: Total y promedio de salarios y listado de jugadores que superan ese salario.
int informarTotalPromedioSalarios(eJugador lista[], int size){
	int todoOk = 0;
	int contador = 0;
	float acumulador = 0;
	float promedio;
	if(lista != NULL && size > 0){
		for(int i = 0; i < size; i++){//recorro solamente el vector de jugadores
			if(lista[i].isEmpty == 0){//verifico que este cargado y el sexo
				acumulador = acumulador + lista[i].salario;//acumulo el monto de los salarios
				contador++;//sumo en un contador cuantas personas se van cargando
			}
		}
		printf("       *** Total y promedio de todos los salarios y jugadores que cobran mas que el salario promedio ***     \n\n");
		promedio = acumulador / contador;
		printf("Total sueldos: %.2f\n", acumulador);
		printf("Promedio sueldos: %.2f\n", promedio);
		printf("Nombre jugadores salario mas alto que el promedio: \n");
		for(int i = 0; i < size; i++){//recorro el vector nuevamente para ver que personas superan el salario promedio
			if(lista[i].isEmpty == 0 && lista[i].salario > promedio ){//verifico que este cargado y el sexo
				printf("%s\n", lista[i].nombre);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 4: INFORMAR CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL
int informarConfederacionMayorCantidadAniosContratoTotal(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int acumuladores[] = {0,0,0,0,0,0};//declaro un vector paralelo para ir guardando los datos. Voy a ir acumulando los años
	int maximo;
	int flag = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                *** Confederacion con mayor cantidad de anios de contratos total ***            \n");
		for(int i = 0; i < size_conf; i++){
			for(int j = 0; j < size; j++){
				if(lista[j].isEmpty == 0 && confederaciones[i].id == lista[j].idConfederacion){//me fijo donde los id son iguales
					acumuladores[i] = acumuladores[i] + lista[j].aniosContrato;//En el vector paraleleo, voy a ir guardando los anios acumulados de cada confederacion
				}
			}
		}
		//Ahora ya se el acumulado de años  que tengo por localidad
		//Recorro el vector paralelo y busco el maximo
		for(int i = 0; i < size_conf; i++){
			if(flag == 0 || acumuladores[i] > maximo){
				maximo = acumuladores[i];
				flag = 1;
			}
		}
		//Ya conozco el numero maximo de anios en el vector paralelo
		//Recorro el vecctor paralelo donde estan los acumuladores de los anios y en aquellos lugares donde tengo el numero maximo
		//voy a imprimir el nombre de la confederacion. Esto se logra ya que los indices van a coincidir.
		for(int i = 0; i < size_conf; i++){
			if(acumuladores[i] == maximo){
				printf("%s\n", confederaciones[i].nombre);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 5: INFORMAR PORCENTAJE DE JUGADORES POR CADA CONFEDERACION
int informarPorcentajeJugadoresPorConfederacion(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int contadores[] = {0,0,0,0,0,0};//declaro un vector paralelo para ir guardando los datos. Voy a ir acumulando los años
	int contadorTotalJugadores = 0;//declaro un contador donde voy a ir contando el total de jugadores cargados
	float porcentajePorConfederacion;

	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                *** Porcentaje de jugadores por cada Confederacion ***            \n");
		for(int i = 0; i < size_conf; i++){
			for(int j = 0; j < size; j++){
				if(lista[j].isEmpty == 0 && confederaciones[i].id == lista[j].idConfederacion){//me fijo donde los id son iguales
					contadores[i] = contadores[i] + 1;//En el vector paraleleo, hago un contador para ir acumulando los jugadores por confederacion
					contadorTotalJugadores++; //hago un acumulador del total de jugadores cargados
				}
			}
		}
		for(int i = 0; i < size_conf; i++){
			porcentajePorConfederacion = (float)contadores[i] * 100 / contadorTotalJugadores; //hago la cuenta del porcentaje que tengo por region
			printf("%s: %.2f\n", confederaciones[i].nombre, porcentajePorConfederacion); //lo informo
		}

		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/
//OPCION 6: INFORMAR REGION CON MAS JUGADORES Y LISTADOS DE LOS MISMOS
int informarRegionConMasJugadoresListar(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int contadores[] = {0,0,0,0,0,0};//declaro un vector paralelo para ir guardando los datos. Voy a ir acumulando los años
	int maximo;
	int flag = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                                             *** Region con mas jugadores ***                       \n");
		for(int i = 0; i < size_conf; i++){
			for(int j = 0; j < size; j++){
				if(lista[j].isEmpty == 0 && confederaciones[i].id == lista[j].idConfederacion){//me fijo donde los id son iguales
					contadores[i]++;//acumulo en el vector paralelo los jugadores que tengo por region
				}
			}
		}
		//Ahora ya se el los jugadores que tengo por region
		//Recorro el vector paralelo y busco el maximo
		for(int i = 0; i < size_conf; i++){
			if(flag == 0 || contadores[i] > maximo){
				maximo = contadores[i];
				flag = 1;
			}
		}
		//Ya conozco el numero maximo de jugadores en el vector paralelo
		//Recorro el vecctor paralelo donde estan los contadores de los jugadores y en aquellos lugares donde tengo el numero maximo
		//voy a imprimir el nombre de la confederacion y todos sus jugadores. Esto se logra ya que los indices van a coincidir.
		for(int i = 0; i < size_conf; i++){
			if(contadores[i] == maximo){
				printf("%s\n", confederaciones[i].region);
				mostrarPersonasIdConfederacion(confederaciones[i].id, lista, size, confederaciones, size_conf);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
