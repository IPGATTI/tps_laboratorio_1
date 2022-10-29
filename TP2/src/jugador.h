/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA FUNCIONES DE ESTRUCTURA JUGADOR. ARCHIVO .H
 ============================================================================
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;   // 1 esta vacio, 0 esta lleno
}eJugador;

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que 1. Verifica que haya espacio en la estructura (isEmpty = 1).
/// 2. Si encontro espacio, aumenta el ID+1.
/// 3. Pide al usuario ingresar los datos
/// @param vector de estructuras a ingresar
/// @param Puntero de la variable id a autoincrementar
/// @param tamaño del vector de estructuras
/// @return  valor 0 si salio mal y valor1 se funcion correctamente
int altaPersona(eJugador lista[], int* pId, int size, eConfederacion confederaciones[], int size_conf);
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
int bajaPersona(eJugador lista[],int size, eConfederacion localidades[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recorre el vector de estructuras en busca del id
/// que buscar el usuario sea uno de los que se encuentran cargados.
/// @param vector de estructuras a ingresar
/// @param id que el usuario desea buscar
/// @param tamaño del vector de estructuras
/// @return -1 si salio mal la funcion o si salio bien el valor del indice donde se encuentra la funcion
int buscarPersonaId(eJugador lista[],int Id, int size);//devuelve el indice dond esta ubicado o -1
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recorre el vector en busca de una estructura que se encuentre sin datos cargados
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return -1 si salio mal la funcion o si salio bien el valor del indice donde no hay ningun dato cargado
int buscarLibre(eJugador lista[], int size);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que recorre el vector de estructuras e inicializa cada una de ellas.
/// Esto lo hace mediante una bandera denominad isEmpty. Va cargando este valor en 0,
/// lo que significa que la estructura se encuentra sin datos cargados.
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return valor 0 si la funcion se rompio o 1 si salio ok
int inicializarPersonas(eJugador lista[], int size);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief  Funcion de menu de opciones
/// @return  Devuelve una valor tipo entero de la opcion que se eligio
int menu();
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief  Funcion de menu de opciones
/// @return  Devuelve una valor tipo entero de la opcion que se eligio
int menuModificar();
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief  Funcion de menu de opciones para elegir posicion
/// @return  Devuelve una valor tipo entero de la opcion que se eligio
int menuPosicion();
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que hace un printfde todos los datos cargados en una estructura
/// @param vector de estructuras a ingresar
void mostrarPersona(eJugador p, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que hace un printfde todos los datos cargados en un vector de estructuras
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return valor 0 si la funcion rompio o 1 si salio ok
int mostrarPersonas(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que busca el ID de una de las personas ingresadas en una estructura
/// para asi poder modificar alguno de los datos cargados.
/// @param vector de estructuras a ingresar
/// @param tamaño del vector de estructuras
/// @return valro 0 si la funcion rompio o 1 si salio ok
int modificarPersona(eJugador lista[],int size, eConfederacion confederaciones[], int size_loc);
/*----------------------------------------------------------------------------------*/

/*====================================================================
--------> INFORMES
====================================================================*/

/*----------------------------------------------------------------------------------*/
/// @brief  Funcion de menu de opciones
/// @return  Devuelve una valor tipo entero de la opcion que se eligio
int menuInformes();
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcione que muestra el menu de los informes
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int mostrarInformes(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 1:Listado jugadores ordenados alfabeticamente por nombre confederacion y nombre jugador
/// @brief Funcion que orden por doble criterio. Trabaja tambien con la funcion cargarDescripcionConfederacion
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int ordenarPersonasConfederacionNombreAlfabeticamente(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 2:Listado de confederaciones con sus jugadores
/// @brief Funcion que muestra el Listado de confederaciones con sus jugadores
/// @param idLocalidad Dato tipo entero correspondiente a la localidad a buscar
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int mostrarPersonasIdConfederacion(int idConfederacion, eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);//OPCION 2
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 2:Listado de confederaciones con sus jugadores
/// @brief Funcion que muestra el listado de confederaciones con sus jugadores
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int informarConfederacionesConJugadores(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);//OPCION 2
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 3: Total y promedio de salarios y listado de jugadores que superan ese salario.
/// @brief Funcion que informa el total y promedio de salarios y listado de jugadores que superan ese salario.
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int informarTotalPromedioSalarios(eJugador lista[], int size);//OPCION 3
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 4: Informar la confederacion con mayor cantidad de años de contratos total
/// @brief Funcion que informa la confederacion con mayor cantidad de años de contratos total
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int informarConfederacionMayorCantidadAniosContratoTotal(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 5: INFORMAR PORCENTAJE DE JUGADORES POR CADA CONFEDERACION
/// @brief Funcoin que informa el porcentaje de jugadores por cada confederacion
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int informarPorcentajeJugadoresPorConfederacion(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
//OPCION 6: INFORMAR REGION CON MAS JUGADORES Y LISTADOS DE LOS MISMOS
/// @brief Funcion que informa la region con mas jugadores y el listado de los mismos
/// @param Vector de estructuras de tipo eJugador
/// @param Tamaño del vector de estructuras eJugador
/// @param Vector de estructuras de tipo eConfederacion
/// @param Tamaño del vector de estructuras eConfederacion
/// @return Valor tipo entero. Devuelve 1 si la funciona correctamente y 0 en el caso contrario
int informarRegionConMasJugadoresListar(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);
/*----------------------------------------------------------------------------------*/

#endif /* JUGADOR_H_ */
