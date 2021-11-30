/*
 * eEditorial.h
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define LONGITUD_NOMBRE_EDITORIAL 30

typedef struct{

	int idEditorial;
	char nombre[LONGITUD_NOMBRE_EDITORIAL];

}eEditorial;


/// @brief Constructor de eEditorial sin parametros
///
/// @return eEditorial* - (NULL)[Hubo un error] - (puntero a nuevo eEditorial)
eEditorial* editorial_crearNuevo();


/// @brief Constructor de eEditorial con parametros
///
/// @param idEditorial int - id de la editorial
/// @param nombre char* - nombre de la editorial
/// @return eEditorial* - (NULL)[parametros invalidos o Error] - (puntero a nuevo eEditorial)
eEditorial* editorial_crearNuevoConParametros(int idEditorial, char* nombre);


/// @brief Setea el idEditorial del eEditorial.
///
/// @param this eEditorial* - puntero al eEditorial a setear
/// @param id int - nueva idEditorial
/// @return int (0)[puntero a NULL o id invalido] - (1)[seteo correcto]
int editorial_setId(eEditorial* this, int id);


/// @brief Obtiene el idEditorial del eEditorial.
///
/// @param this eEditorial* - puntero al eEditorial obtener idEditorial
/// @param id int* - puntero para devolver el idEditorial
/// @return int (0)[puntero a NULL] - (1)[obtuvo correctamente]
int editorial_getId(eEditorial* this, int* id);


/// @brief Setea el nombre de un eEditorial
///
/// @param this eEditorial* - puntero al eEditorial a setear el nombre
/// @param nombre char* - nuevo nombre
/// @return int (0)[puntero a NULL o nombre invalido] - (1)[seteo correcto]
int editorial_setNombre(eEditorial* this, char* nombre);


/// @brief Obtiene el nombre de un eEditorial
///
/// @param this eEditorial* - puntero al eEditorial a obtener el nombre
/// @param nombre char* - puntero para devolver el nombre
/// @return int (0)[puntero a NULL] - (1)[obtuvo correctamente]
int editorial_getNombre(eEditorial* this, char* nombre);


/// @brief Recibe un puntero a eEditorial y lo muestra en pantalla
///
/// @param this eEditorial* - puntero al eEditorial a mostrar
/// @return int (0)[puntero a NULL] - (1)[se pudo mostrar]
int editorial_mostrarEnPantallaNombre(eEditorial* this);


/// @brief Recibe un puntero de tipo void a un eEditorial, lo desempaca
/// 		y compara su idEditorial al id recibido.
///
/// @param element void* - puntero de tipo void a un eEditorial
/// @param id int - id a comparar
/// @return int - (0)[puntero a NULL o id son diferentes] - (1)[id son iguales]
int editorial_compararId(void* element, int id);


/// @brief Recibe un puntero tipo void, lo desempaca y lo devuelve
///
/// @param element void* - puntero tipo void a desempacar.
/// @return eEditorial* - (NULL)[puntero a NULL] - (puntero eEditorial desempacado)
eEditorial* editorial_desempacar(void* element);


/// @brief Recibe una linked list de eEditorial e imprime en pantalla
/// 		la eEditorial con el id recibido por parametro
///
/// @param listaEditoriales LinkedList* - linked list de eEditorial
/// @param id int - id del eEditorial a imprimir
/// @return int (0)[puntero a NULL o id inexistente] - (1)[se pudo imprimir]
int editorial_imprimirAutorPorId(LinkedList* listaEditoriales, int id);


/// @brief Busca en una linked list de eEditorial segun el id recibido por parametro
/// 		y si lo encuentra devuelve un puntero a la misma.
///
/// @param listaEditoriales LinkedList* - linked list de eEditorial a buscar el id
/// @param id int - id de la eEditorial buscada
/// @return eEditorial* - (NULL)[puntero a NULL o no se encontro el id) - (puntero eEditorial encontrada)
eEditorial* editorial_buscarPorId(LinkedList* listaEditoriales, int id);



#endif /* EDITORIAL_H_ */
