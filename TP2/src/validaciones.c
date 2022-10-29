/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 2022
 University  : UTN-FRA
 Exercise    : BIBLIOTECA ENTRADA DE DATOS. ARCHIVO .C
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

/*====================================================================
--------> STATIC FUNCTIONS
====================================================================*/

int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
void myFpurge();

void myFpurge()
{
    fflush(stdin);
}

/*----------------------------------------------------------------------------------*/
/// @brief obtiene un numero entero desde la termina
/// @param pResultado Puntero ale spacio de memoria donde se dejara el resultado dela funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) sino
int getInt(int* pResultado){
	int retorno = -1;
	char buffer[4096];//hago un buffer para guardar lo que me ingresa el usuario
	//El usuario puede guardar Pepe124, jo123js, etc
	if(	myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
		retorno = 0;
		*pResultado = atoi(buffer); //si el buffer solo tiene numeros
		//a traves dela funcion atoi lo convierto en un integer
	    //atoi convierte un array en un numero integer. Vos tenes como texto
		//10\0, ese texto 10, me lo pasaa int 10.
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief obtiene una variable tipo short desde la termina
/// @param pResultado Puntero ale spacio de memoria donde se dejara el resultado dela funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) sino
int getShort(short* pResultado){//BORRAR
	int retorno = -1;
	char buffer[4096];//hago un buffer para guardar lo que me ingresa el usuario
	//El usuario puede guardar Pepe124, jo123js, etc
	if(	myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
		retorno = 0;
		*pResultado = atoi(buffer); //si el buffer solo tiene numeros
		//a traves dela funcion atoi lo convierto en un integer
	    //atoi convierte un array en un numero integer. Vos tenes como texto
		//10\0, ese texto 10, me lo pasaa int 10.
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief obtiene una variable tipo short desde la termina
/// @param pResultado Puntero ale spacio de memoria donde se dejara el resultado dela funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) sino
int getFloat(float* pResultado){//BORRAR
	int retorno = -1;
	char buffer[4096];//hago un buffer para guardar lo que me ingresa el usuario
	//El usuario puede guardar Pepe124, jo123js, etc
	if(	myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
		retorno = 0;
		*pResultado = atoi(buffer); //si el buffer solo tiene numeros
		//a traves dela funcion atoi lo convierto en un integer
	    //atoi convierte un array en un numero integer. Vos tenes como texto
		//10\0, ese texto 10, me lo pasaa int 10.
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief  Lee de stind hasta que encuentra un'\n' o hasta que haya copiado
/// en cadena un maximo de longitud - 1 caracteres
/// @param Puntero ale spacio de memoria donde se dejara el resultado dela funcion
/// @param longitud define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) sino
int myGets(char* cadena, int longitud){
	fflush(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';

	return 0;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/// @brief Verifica si la cadena ingresada es numerica
/// @param cadena Cadena de caracteresa ser analizada
/// @return Retorna 1 ( verdadero) si la cadena es numerica y 0 (falso) si no lo es
int esNumerica(char* cadena){
	int retorno = 1;
	int i = 0;
	if(cadena[0] == '-'){//si estoy en la primera posicon tengo que analizar que hacer. Porque peudo tener un menos
		i = 1;
	}
	for( ; cadena[i] != '\0' ; i++){//recorro la cadena
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
///brief El usuario ingresa una cadena con fgets
///param pBuffer Recibe el texto ingresado en caso de exito
///param limite Es el tamano maximo del string
///return En caso de exito retorna 0, si no -1
int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
        myFpurge();
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
///brief Evalua si se trata de un texto valido(Letras numeros simbolos)
///param pBuffer Es la cadena que evaluamos
///param limite Es el tamano maximo del string
///return En caso de exito retorna 1, si no 0
int isValidTexto(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!(   (pBuffer[i] >= ' ' && pBuffer[i] <= '"') ||
                    pBuffer[i] == '(' || pBuffer[i] == ')' ||
                    (pBuffer[i] >= ',' && pBuffer[i] <= '.') ||
                    (pBuffer[i] >= '0' && pBuffer[i] <= ';') ||
                    (pBuffer[i] >= '?' && pBuffer[i] <= 'Z') ||
                    (pBuffer[i] >= 'a' && pBuffer[i] <= 'z')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
///brief Evalua si se trata de una cadena solo de letras
///param pBuffer Es la cadena que evaluamos
///param limite Es el tamano maximo del string
///return En caso de exito retorna 1, si no 0
int isValidAlfabetico(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!(tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


///brief   Evalua si es un nombre, solo puede tener un espacio y cada nombre
///        debe empezar por mayuscula y el resto minusculas (Jose)(Jose Maria)(Lopez)(Lopez Gomez)
///param pBuffer Es la cadena que evaluamos
///param limite Es el tamano maximo del string
///return En caso de exito retorna 1, si no 0
int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    /*int cantidadEspacios = 0;
    int i;*/
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
                ((pBuffer[0]>='A' && pBuffer[0]<='Z') || (pBuffer[0]>='a' && pBuffer[0]<='z')))

        {

        /*for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }*/
        retorno = 1;
    }
    return retorno;
}

/*----------------------------------------------------------------------------------*/

/*====================================================================
--------> FUNCTIONS
====================================================================*/

/*----------------------------------------------------------------------------------*/
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	int buffer;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			//el get int va a ser una funcion que reemplaza al scanf
			//La funcion pretende que le de un lugar donde dejarle el resultaod (buffer). Tambien ya me devuelve si salio bien o mal
			//get int si me devuelve un 0, es por que pudo obtener el entero
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo){//valido el numero
				*pResultado = buffer;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	short buffer;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			//el get int va a ser una funcion que reemplaza al scanf
			//La funcion pretende que le de un lugar donde dejarle el resultaod (buffer). Tambien ya me devuelve si salio bien o mal
			//get int si me devuelve un 0, es por que pudo obtener el entero
			if(getShort(&buffer) == 0 && buffer >= minimo && buffer <= maximo){//valido el numero
				*pResultado = buffer;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char*mensajeError, float minimo, float maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	float bufferInt;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			scanf("%f", &bufferInt);//guardo el msj en la variable internat
			if(bufferInt >= minimo && bufferInt <= maximo){//valido el numero
				*pResultado = bufferInt;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getCaracter(char* pResultado, char* mensaje, char*mensajeError, char minimo, char maximo, int reintentos){
	int retorno = 0;//inicio la variable en retorno en 0. En caso de qeu se cumpla retorno 1
	char bufferChar;//variabla transitoria que guarda lo que el usuario ingresa momentaneamente. Areas de intercambio
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){//valido los parametros qe recibo. El min y el max esta expresado en ascii. Por ejemplo, la A es 65 y la z 122
		do{//la primera vez se va a cumplr, incluso si reintento viene cargado con 0
			printf("%s", mensaje);//imprimo el msj
			fflush(stdin);//fflush
			scanf("%c", &bufferChar);//guardo el msj en la variable internat
			if(bufferChar >= minimo && bufferChar <= maximo){//valido el numero
				*pResultado = bufferChar;//paso el valor de la variable interna al punter
				retorno = 1;//operacion ok. retorno 1
				break; //si esta todo ok, rompo el bucle con un break
			}
			else{
				printf("%s", mensajeError);//si el numero no es correcto, imprimo el msj de error
				reintentos--;//disminucion de reintenos
			}
		}while(reintentos >= 0);//condicion
	}
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getCaracterSeleccionados(char* pResultado, char* mensaje, char* mensajeError){

	int retorno = 0;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &bufferChar);
		bufferChar = toupper(bufferChar);
		*pResultado = bufferChar;
		retorno = 1;
		while(bufferChar != 'M' && bufferChar != 'F' /*&& bufferChar != 'F' && bufferChar != 'B' && bufferChar != 'U' && bufferChar != 'O'*/){
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &bufferChar);
			bufferChar = toupper(bufferChar);
			*pResultado = bufferChar;
			retorno = 1;
	    }
    }
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getCaracterSeleccionadosConfirma(char* pResultado, char* mensaje, char* mensajeError){

	int retorno = 0;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &bufferChar);
		bufferChar = toupper(bufferChar);
		*pResultado = bufferChar;
		retorno = 1;
		while(bufferChar != 'S' && bufferChar != 'N' /*&& bufferChar != 'F' && bufferChar != 'B' && bufferChar != 'U' && bufferChar != 'O'*/){
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &bufferChar);
			bufferChar = toupper(bufferChar);
			*pResultado = bufferChar;
			retorno = 1;
	    }
    }
	return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getTexto(   char *pTexto, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pTexto != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidTexto(buffer, limite))
            {
                strncpy(pTexto, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getAlfabetico(  char *pAlfabetico, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferAlfabetico[4096];
    if( pAlfabetico != NULL && limite > 0 && mensaje != NULL &&
            mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);
            if( getString(bufferAlfabetico, limite) == 0 &&
                isValidAlfabetico(bufferAlfabetico, limite))
            {
                strncpy(pAlfabetico, bufferAlfabetico, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
int utn_getNombre(char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/*----------------------------------------------------------------------------------*/
