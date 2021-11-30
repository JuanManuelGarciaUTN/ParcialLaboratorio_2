/*
 * inputs.h
 *
 *  Created on: 17 oct. 2021
 *      Author: juanm
 */

#ifndef INPUTS_H_
#define INPUTS_H_


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TAMANIO_BUFFER 100 //tamaño del buffer para los inputs

/// @brief Le pide al usuario que ingrese un string y verifica que solo tenga letras o espacios
/// 		Si es valido lo devuelve a traves de un puntero y si no le vuelve a pedir al usuario que ingrese un valor hasta que sea valido
///
/// @param mensaje[] char - el mensaje que se le muestra al usuario
/// @param mensajeError[] char - el mensaje que se le muestra al usuario si ingresa un dato invalido
/// @param cadena[] char - el vector char donde se guardara lo que ingreso el usuario
/// @param longitud - la longitud del vector donde se guardara el ingreso
/// @return 1[si no hubo algun error]  0[si hubo un error]
int PedirSustantivoPropio(char mensaje[], char mensajeError[], char cadena[], int longitud);


/// @brief Le pide al usuario que ingrese el nombre de un archivo con su extension y verifica
/// 		que no sea un nombre invalido.
///
/// @param mensaje[] char - el mensaje que se le muestra al usuario
/// @param mensajeError[] char - el mensaje que se le muestra al usuario si ingresa nombre invalido
/// @param cadena[] char - el vector char donde se guardara el nombre que ingreso el usuario
/// @param longitud - la longitud del vector donde se guardara el ingreso
/// @return 1[si no hubo algun error]  0[si hubo un error]
int PedirNombreArchivo(char mensaje[], char mensajeError[], char cadena[], int longitud);


/// @brief Le pide al usuario que ingrese el nombre de un archivo SIN su extension y verifica
/// 		que no sea un nombre invalido.
///
/// @param mensaje[] char - el mensaje que se le muestra al usuario
/// @param mensajeError[] char - el mensaje que se le muestra al usuario si ingresa nombre invalido
/// @param cadena[] char - el vector char donde se guardara el nombre que ingreso el usuario
/// @param longitud - la longitud del vector donde se guardara el ingreso
/// @return 1[si no hubo algun error]  0[si hubo un error]
int PedirNombreArchivoSinExtension(char mensaje[], char mensajeError[], char cadena[], int longitud);


/// @brief Le pide al usuario que ingrese un Entero y valida que se encuentre dentro de un rango.
/// 		Si es valido lo devuelve a traves de un puntero y si no le vuelve a pedir al usuario que ingrese un valor hasta que sea valido
///
/// @param mensaje[] char - el mensaje que se le muestra al usuario
/// @param mensajeError[] char - el mensaje que se le muestra al usuario si ingresa un dato invalido
/// @param pEntero int* - puntero a la variable  donde se guardara el dato una vez validado
/// @param minimo int- rango minimo de validacion
/// @param maximo int - rango maximo de validacion
/// @return 1[se devolvio un dato validado] 0[si hubo algun error]
int PedirEnteroValidado(char mensaje[], char mensajeError[], int* pEntero, int minimo, int maximo);


/// @brief Le pide al usuario que ingrese un Entero y valida que sea mayor a (mayorQue)
/// 		Si es valido lo devuelve a traves de un puntero y si no le vuelve a pedir al usuario que ingrese un valor hasta que sea valido
///
/// @param mensaje[] char - el mensaje que se le muestra al usuario
/// @param mensajeError[] char - el mensaje que se le muestra al usuario si ingresa un dato invalido
/// @param pEntero int* - puntero a la variable  donde se guardara el dato una vez validado
/// @param mayorQue int- se validara que el ingreso sea mayor a este valor
/// @return 1[se devolvio un dato validado] 0[si hubo algun error]
int PedirEnteroMayorQue(char mensaje[], char mensajeError[], int* pEntero, int mayorQue);


/// @brief Le pide al usuario que ingrese un Entero.
/// 		Si es valido lo devuelve a traves de un puntero y si no le vuelve a pedir al usuario que ingrese un valor hasta que sea valido.
///
/// @param mensaje[] char - el mensaje que se le muestra al usuario
/// @param mensajeError[] char - el mensaje que se le muestra al usuario si ingresa un dato invalido
/// @param pEntero int* - puntero a la variable  donde se guardara el dato una vez validado
/// @return 1[se devolvio un entero] 0[si hubo algun error]
int PedirEntero(char mensaje[], char mensajeError[], int* pEntero);


/// @brief Permite ingresar una cadena de caracteres y verifica si es un numero entero. De ser así,
/// 		la devuelve como un int a través del puntero int* pEntero
///
/// @param pEntero int* puntero a una variable tipo int para devolver el valor ingresado por el usuario
/// @return (1) [si se ingreso un numero tipo entero] - (0) [si NO se ingreso un numero tipo entero]
int MiGetInt(int* pEntero);


/// @brief Permite al usuario ingresar una cadena de char
///
/// @param cadena - vector tipo char donde se guarda la cadena ingresada
/// @param longitud - la longitud del vector donde se guarda la cadena ingresada
/// @return (1) [se pudo ingresar una cadena] - (0) [si hubo un error]
int MiGets(char cadena[], int longitud);


/// @brief Recibe una cadena tipo char y verifica que sea un numero entero
///
/// @param cadena[] char - cadena a verificar si es entero o no
/// @return (1) [si cadena es un numero entero] - (0) [si cadena NO es un numero entero]
int EsEntero(char cadena[]);


/// @brief Recibe una cadena de tipo char y verifica que sea un sustantivo
/// 		Es decir, solo contenga letras o espacios
///
/// @param cadena[] char - cadena a verificar si es float o no
/// @return int - (1) [si cadena es un sustantivo] - (0) [si cadena NO es un sustantivo]
int EsSustantivo(char cadena[]);


int EsArchivo(char cadena[]);

int EsArchivoSinExtension(char cadena[]);


/// @brief Recibe una cadena de char y la formatea para que cada palabra empieze en mayuscula y el resto sea minuscula
///
/// @param cadena[] char - cadena que va a ser formateada
void FormatearSustantivoPropio(char cadena[]);


#endif /* INPUTS_H_ */
