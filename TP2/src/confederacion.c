/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA FUNCIONES DE ESTRUCTURA CONFEDRACION. ARCHIVO .C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"

/*----------------------------------------------------------------------------------*/
int altaConfederacion(eConfederacion confederaciones[], int* pId, int size_conf){
	int todoOk = 0;
	int indice;
	eConfederacion auxConfederacion;
	if(confederaciones != NULL && size_conf){
		system("cls");
		printf("      *** Alta Confederacion ***\n\n");
		indice = buscarLibreConf(confederaciones, size_conf);//llamamos a la funcion buscar libre, que nos garantiza que la estructura esta vacia
		if(indice == -1){
			printf("No hay lugar\n");
		}
		else{
			auxConfederacion.id = *pId;//aca agarramos el valo del id en el main y se lo designamos a la persona
			*pId = *pId + 1;//lo incrementamos +1, haciendo el id autoincrementable

			utn_getNombre(auxConfederacion.nombre, 20, "Ingrese nombre: ", "ERROR. ", 100000);

			utn_getNombre(auxConfederacion.region, 20, "Ingrese nombre: ", "ERROR. ", 100000);

			utn_getNumeroInt( &auxConfederacion.anioCreacion, "Ingrese año confederacion entre 1900 y 2022: ", "ERROR. ", 1900, 2022, 100000);

			auxConfederacion.isEmpty = 0;//cambiamos el estado del isEmpey, ya que ya hemos cargado los datos.

			confederaciones[indice] = auxConfederacion;//cargamos todos los datos en el indice de la estructura

			todoOk = 1;
		}
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int bajaConfederacion(eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	if(confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("   *** Baja Jugador ***\n"); //pedimos al usuario que el ingresa el id que quiere dar de bajo
		mostrarConfederaciones(confederaciones, size_conf);
		printf("Ingrese id: ");
		scanf("%d", &id);//lo guardamos en una variable

		indice = buscarConfederacionId(confederaciones, id, size_conf);//llamos a la funcion que nos devuelve el valor del indice en caso de que haya
		//encontrado el id
		if(indice == -1){
			printf("ID incorrecto. No existe el ID %d\n", id);
		}
		else{
			mostrarConfederacion(confederaciones[indice]);
			utn_getCaracterSeleccionadosConfirma(&confirma, "¿Confirma baja? S/N: ", "ERROR. ¿Confirma baja?: S/N: ");
			if(confirma == 'S'){//en caso de confirme, pongo el isEmpty en 1, como diciendo que esta vacio que en caso de consultas
				//no me muestra datos, pero si quiero ingresar un nuevo usuario me lo pise
				confederaciones[indice].isEmpty = 1;
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
int modificarConfederacion(eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int indice;
	int id;
	int flag = 0;
	char confirma;
	char auxNombre[50];
	char auxRegion[50];
	int auxAnioCreacion;
	if(confederaciones != NULL && size_conf > 0 ){
		system("cls");
		printf("   *** Modificar Confederacion ***\n");
		mostrarConfederaciones(confederaciones, size_conf);
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarConfederacionId(confederaciones, id, size_conf);//Llama a la funcion buscar persona id

		if(indice == -1){
			printf("ID incorrecto. No existe el ID %d\n", id);
		}
		else{
			printf("         ***** Datos de la confederacion ingresada: *****             \n");
			printf("======================================================================\n");
			printf("│  ID  │         NOMBRE           │       REGION     │ ANIO CREACION │\n");
			printf("----------------------------------------------------------------------\n");
			mostrarConfederacion(confederaciones[indice]);//llamo a la funcion para mostrar la persona a modificar ls odatos

			utn_getCaracterSeleccionadosConfirma(&confirma, "¿Confirma modificacion? S/N: ", "ERROR. ¿Confirma modificacion?: S/N: ");

			if(confirma == 'S'){
				switch(menuModificarConf()){
					case 1:
						utn_getNombre(auxNombre, 20, "Ingrese nombre: ", "ERROR. ", 100000);
						strcpy(confederaciones[indice].nombre, auxNombre);
						break;
					case 2:
						utn_getNombre(auxRegion, 20, "Ingrese nombre: ", "ERROR. ", 100000);
						strcpy(confederaciones[indice].region, auxRegion);
						break;
						break;
					case 3:
						utn_getNumeroInt( &auxAnioCreacion, "Ingrese año confederacion entre 1900 y 2022: ", "ERROR. ", 1900, 2022, 100000);
						confederaciones[indice].anioCreacion = auxAnioCreacion;
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

/*----------------------------------------------------------------------------------*/
int menuModificarConf(){
	int opcion;
	printf("Ingrese el dato que desea modificar: \n");
	printf("1- Nombre\n");
	printf("2- Region\n");
	printf("3- Año\n");
	printf("4- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int buscarLibreConf(eConfederacion confederaciones[], int size_conf){
	int indice = -1;
	if(confederaciones != NULL && size_conf > 0){
		for(int i = 0; i < size_conf; i++){
			if(confederaciones[i].isEmpty == 1){
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/*----------------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------*/
int buscarConfederacionId(eConfederacion confederaciones[],int Id, int size_conf){
	int indice = -1;
	if(confederaciones != NULL && size_conf > 0){
		for(int i = 0; i < size_conf; i++){
			if(!confederaciones[i].isEmpty && confederaciones[i].id == Id){
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int cargarDescripcionConfederacion(eConfederacion confederaciones[], int size,int idConfederacion, char descripcion[]){
	int todoOk = 0;
	int flag = 1;
	if(confederaciones != NULL && size > 0 && descripcion != NULL){
		/*a mosotros nos llega el vector de confederaciones con el tamaño par qu lo recorramos
		 * el id de la confederacion que tenemos que buscar y una cadena de caracteres
		 * para que le copiemos a la cadena el campo descripcion de la confederacion que tenga ese id
		 * Es como a esa funcion le paso el vector de confederaciones
		 */
		todoOk = 1;
		for(int i = 0; i < size; i++){
			if(confederaciones[i].id == idConfederacion){
				strcpy(descripcion, confederaciones[i].nombre);
				flag = 0;
				break;
			}
		}
		if(flag){
			todoOk = -1;
		}
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
void mostrarConfederacion(eConfederacion confederacion){
	printf("│   %d │ %9s    │   %23s  │     %d     │\n",
			confederacion.id,
			confederacion.nombre,
			confederacion.region,
			confederacion.anioCreacion
		   );
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int mostrarConfederaciones(eConfederacion confederaciones[], int size){
	int todoOk = 0;
	if(confederaciones != NULL && size > 0){
		printf("                  ***** Confederaciones *****     \n");
		printf("====================================================================\n");
		printf("│  ID   │     NOMBRE   │         REGION             │ AÑO CREACION │\n");
		printf("--------------------------------------------------------------------\n");
		for(int i = 0; i < size; i++){
				mostrarConfederacion(confederaciones[i]);
		}
		printf("====================================================================\n");
		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int validarIdConfederacion(int id, eConfederacion confederaciones[], int size){
	int todoOk = 0;
	if(confederaciones != NULL && size > 0){
		for(int i = 0; i < size; i++){
			if(confederaciones[i].id == id){
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/


