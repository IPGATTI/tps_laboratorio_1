/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA FUNCIONES DE ESTRUCTURA CONFEDRACION. ARCHIVO .H
 ============================================================================
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_
#include "validaciones.h"

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que 1. Verifica que haya espacio en la estructura (isEmpty = 1).
/// 2. Si encontro espacio, aumenta el ID+1.
/// 3. Pide al usuario ingresar los datos
/// @param vector de estructuras a ingresar
/// @param Puntero de la variable id a autoincrementar
/// @param tamaño del vector de estructuras
/// @return  valor 0 si salio mal y valor1 se funcion correctamente
int altaConfederacion(eConfederacion confederaciones[], int* pId, int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief 1. Pide al usuario el ID del usuario a dar de baja.
/// 2. Llama a la funcion buscarPersonaPorId.
/// 3. Si la persona esta, muestra los datos y pregunta al usuario si realmente desea darlo de baja
/// 4. Si la baja se confirma, la estructura si bien conserva los datos, el isEmpty lo pone en 1 para que se puedan volver
/// a pedir datos al usuario y sobreescribirlos.
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return valor 0 si salio mal y valor1 se funcion correctamente
int bajaConfederacion(eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que busca el ID de una de las confederaciones ingresadas en una estructura
/// para asi poder modificar alguno de los datos cargados.
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return valro 0 si la funcion rompio o 1 si salio ok
int modificarConfederacion(eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief  Funcion de menu de opciones
/// @return  Devuelve una valor tipo entero de la opcion que se eligio
int menuModificarConf();
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recorre el vector en busca de una estructura que se encuentre sin datos cargados
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return -1 si salio mal la funcion o si salio bien el valor del indice donde no hay ningun dato cargado
int buscarLibreConf(eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recorre el vector de estructuras en busca del id
/// que buscar el usuario sea uno de los que se encuentran cargados.
/// @param vector de estructuras a ingresar
/// @param id que el usuario desea buscar
/// @param tamaño del vector de estructuras
/// @return -1 si salio mal la funcion o si salio bien el valor del indice donde se encuentra la funcion
int buscarConfederacionId(eConfederacion confederaciones[],int Id, int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief 	Es similar buscar persona por id, es exacamente lo mismo
/// le voy a pasar el array de localidades, el tamaño, le paso el id de la localidad a buscar y
/// el char donde quiero guardar la descripcion
///esta funcion va a buscar en el array si hay alguna localidad con ese id y si la encuentra
///le copia en el vector de caracteres (al ser un array el pasaje lo hace por referencia y usando strcpy)
///de esta forma el vector de caracteres quede cargado
/// @param vector de estructuras a ingresar
/// @param Vector de estructuras de tipo eConfederacion
/// @param id del dato el cual quiero buscar
/// @param vector de caracteres donde cargo el dato relacionado con el id y necesito
/// @return valor 0 si la funcion rompio o 1 si salio ok
int cargarDescripcionConfederacion(eConfederacion confederaciones[], int size,int idConfederacion, char descripcion[]);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que hace un printf de todos los datos cargados en una estructura
/// @param Eestructura de tipo eConfederacion
void mostrarConfederacion(eConfederacion confederacion);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que hace un printfde todos los datos cargados en un vector de estructuras
/// @param vector de estructuras a ingresar
/// @param Vector de estructuras de tipo eConfederacion
/// @return valor 0 si la funcion rompio o 1 si salio ok
int mostrarConfederaciones(eConfederacion confederaciones[], int size);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que valida que el id ingresado corresponda a un id de la entidad
/// @param id tipo entero a verificar
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return 0 si existe el id o 1 si existe el id
int validarIdConfederacion(int id, eConfederacion confederaciones[], int size);
/*----------------------------------------------------------------------------------*/

#endif /* CONFEDERACION_H_ */
