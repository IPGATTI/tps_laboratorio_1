/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA ENTRADA DE DATOS. ARCHIVO .H
 ============================================================================
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo entero entre rangos y la valida. Permite entrar stings y caracteres
/// @param Puntero tipo int a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo int en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo short entre rangos y la valida. Permite entrar stings y caracteres
/// @param Puntero tipo int a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo int en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo flotante entre rangos y la valida
/// @param Puntero tipo float a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo float en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char*mensajeError, float minimo, float maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo char entre rangos y la valida
/// @param Puntero tipo char a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Guarda un valor tipo char en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getCaracter(char* pResultado, char* mensaje, char*mensajeError, char minimo, char maximo, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo char de determinado valor y la valida
/// @param Puntero tipo char a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @return Guarda un valor tipo char en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getCaracterSeleccionados(char* pResultado, char* mensaje, char* mensajeError);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Funcion que obtiene una variable de tipo char de determinado valor y la valida
/// @param Puntero tipo char a cargar el valor
/// @param mensaje
/// @param mensajeError
/// @return Guarda un valor tipo char en el puntero y retorna 0 o 1 dependiendo si la funcion salio bien
int utn_getCaracterSeleccionados(char* pResultado, char* mensaje, char* mensajeError);
int utn_getCaracterSeleccionadosConfirma(char* pResultado, char* mensaje, char* mensajeError);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
///brief Toma una cadena y evalua si es un texto valido
///param pTexto Recibe el texto ingresado en caso de exito
///param limite Es el tamano maximo del string
///param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
///param mensajeError Es el mensaje que se muestra en caso de error
///param reintentos Veces que el usuario podra volver a introducir el dato
///return En caso de exito retorna 0, si no -1
int utn_getTexto(   char *pTexto, int limite, char *mensaje, char *mensajeError, int reintentos);
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
///brief Toma una cadena y evalua si tiene solo letras
///param pAlfabetico Recibe el texto ingresado en caso de exito
///param limite Es el tamano maximo del string
///param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
///param mensajeError Es el mensaje que se muestra en caso de error
///param reintentos Veces que el usuario podra volver a introducir el dato
///return En caso de exito retorna 0, si no -1
int utn_getAlfabetico(  char *pAlfabetico, int limite, char *mensaje, char *mensajeError, int reintentos);
/*----------------------------------------------------------------------------------*/


///brief    Toma una cadena y evalua si es un nombre, solo puede tener un espacio y cada nombre
///           debe empezar por mayuscula y el resto minusculas (Jose)(Jose Maria)(Lopez)(Lopez Gomez)
///param pNombre Recibe el texto ingresado en caso de exito
///param limite Es el tamano maximo del string
///param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
///param mensajeError Es el mensaje que se muestra en caso de error
///param reintentos Veces que el usuario podra volver a introducir el dato
///return En caso de exito retorna 0, si no -1

int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
#endif /* VALIDACIONES_H_ */
