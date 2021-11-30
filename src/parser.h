/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: juanm
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "inputs.h"


/// @brief Recibe una path a archivo y una linked list.
/// 		Lee los datos del archivo y los guarda de ser posible como eLibro
/// 		en la linked list.
///
/// @param path	char* - path a un archivo
/// @param listaLibros - puntero a linked list
/// @return int (-1)[puntero a NULL o path no es valido] - (0)[se cargo parcialmente, datos invalidos o corruptos] - (1)[se cargo correctamente]
int parser_CagarLibros(char* path, LinkedList* listaLibros);


/// @brief Recibe una path a archivo en formato texto y una linked list.
/// 		Lee los datos del archivo y los guarda de ser posible como eLibro
/// 		en la linked list.
///
/// @param path	char* - path a un archivo de formato texto
/// @param listaLibros - puntero a linked list
/// @return int (-1)[puntero a NULL o path no es valido] - (0)[se cargo parcialmente, datos invalidos o corruptos] - (1)[se cargo correctamente]
int parser_CagarLibrosDesdeTexto(char* path, LinkedList* listaLibros);


/// @brief Recibe una path a archivo de formato binario y una linked list.
/// 		Lee los datos del archivo y los guarda de ser posible como eLibro
/// 		en la linked list.
///
/// @param path	char* - path a un archivo de formato binario
/// @param listaLibros - puntero a linked list
/// @return int (-1)[puntero a NULL o path no es valido] - (0)[se cargo parcialmente, datos invalidos o corruptos] - (1)[se cargo correctamente]
int parser_CagarLibrosDesdeBinario(char* path, LinkedList* listaLibros);


/// @brief Recibe una path a archivo y una linked list.
/// 		Lee los datos del archivo y los guarda de ser posible como eEditorial
/// 		en la linked list.
///
/// @param path	char* - path a un archivo
/// @param listaEditoriales - puntero a linked list
/// @return int (-1)[puntero a NULL o path no es valido] - (0)[se cargo parcialmente, datos invalidos o corruptos] - (1)[se cargo correctamente]
int parser_CagarEditoriales(char* path, LinkedList* listaEditoriales);


/// @brief Recibe una path a archivo en formato texto y una linked list.
/// 		Lee los datos del archivo y los guarda de ser posible como eEditorial
/// 		en la linked list.
///
/// @param path	char* - path a un archivo en formato texto
/// @param listaEditoriales - puntero a linked list
/// @return int (-1)[puntero a NULL o path no es valido] - (0)[se cargo parcialmente, datos invalidos o corruptos] - (1)[se cargo correctamente]
int parser_CagarEditorialesDesdeTexto(char* path, LinkedList* listaEditoriales);


/// @brief Recibe una path a archivo en formato binario y una linked list.
/// 		Lee los datos del archivo y los guarda de ser posible como eEditorial
/// 		en la linked list.
///
/// @param path	char* - path a un archivo en formato binario
/// @param listaEditoriales - puntero a linked list
/// @return int (-1)[puntero a NULL o path no es valido] - (0)[se cargo parcialmente, datos invalidos o corruptos] - (1)[se cargo correctamente]
int parser_CagarEditorialesDesdeBinario(char* path, LinkedList* listaEditoriales);


/// @brief Recibe un path a archivo, lo abre y analiza si tiene un header en formato texto
/// 		inicializado en id con el fin de determinar si esta en formato texto con header.
/// 		De no ser el caso se lo considera en formato binario
///
/// @param path char* - path al archivo a analizar
/// @return int (-1)[path invalido] - (0)[se considera formato binario] - (1)[se considera formato texto]
int DeterminarSiArchivoEsTexto(char* path);




#endif /* PARSER_H_ */
