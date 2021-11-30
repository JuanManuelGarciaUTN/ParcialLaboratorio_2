/*
 * controller.h
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "menu.h"
#include "inputs.h"
#include "parser.h"
#include "nexoLinkedList.h"


/// @brief Muestra en menu principal con las opciones disponibles,
/// 		le pide al usuario que ingrese la opcion deseada
/// 		y devuelve el valor ingresado.
///
/// @return int - opcion ingresada por el usuario
int controller_menuPrincipal(void);


/// @brief Pide al usuario que ingrese el nombre del archivo para
/// 		cargar la LinkedList de eLibro.
///
/// @param listaLibros LinkedList* - puntero a linked list para guardar eLibro.
/// @return	int (-4)[No se quiso sobrescribir la lista] - (-3)[listaLibros puntero a NULL] - (-2)[Supero limite de errores ingresando el nombre del archivo] - (-1)[Archivo no existe] - (0)[Se Cargo parcialmente la lista] - (1)[Se Cargo la Lista]
int controller_cargarLibros(LinkedList* listaLibros);


/// @brief Pide al usuario que ingrese el nombre del archivo para
/// 		cargar la LinkedList de eEditorial.
///
/// @param listaEditoriales LinkedList* - puntero a linked list para guardar eEdidorial
/// @return	int (-4)[No se quiso sobrescribir la lista] - (-3)[listaLibros puntero a NULL] - (-2)[Supero limite de errores ingresando el nombre del archivo] - (-1)[Archivo no existe] - (0)[Se Cargo parcialmente la lista] - (1)[Se Cargo la Lista]
int controller_cargarEditoriales(LinkedList* listaEditoriales);


/// @brief Ordena la lista de libros segun el nombre del autor
///
/// @param listaLibros LinkedList* - puntero a  linked list de eLibro a ordenar
/// @return int (0)[Lista puntero NULL] - (1)[Se Ordeno la lista]
int controller_ordenarListaPorAutor(LinkedList* listaLibros);


/// @brief Imprime en pantalla todos los libros de la lista con el nombre de su editorial
///
/// @param listaLibros LinkedList* - puntero a  linked list de eLibro
/// @param listaEditoriales LinkedList* - puntero a  linked list de eEditorial
/// @return int - (0)[lista puntero a NULL] - (1)[Se mostro la lista correctamente]
int controller_mostrarListaLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);


/// @brief Guarda todos los eLibro con editorial "MINOTAURO" en un archivo .csv que
/// 		ingreso el usuario. Si el archivo no existe lo crea y si existe lo sobrescribeS
///
/// @param listaLibros LinkedList* - puntero a  linked list de eLibro
/// @return int - (-2)[lista vacia o puntero a NULL] - (-1)[No hay eLibro de editorial "MINOTAURO"] - (0)[Supero limite de ingresos de nombre de archivo] - (1)[Se guardo correctamente]
int controller_guardarListaLibrosEditorialMinotauro(LinkedList* listaLibros);


/// @brief Saluda al usuario antes que se termine el programa
///
/// @return void
int controller_salirDelPrograma(void);


/// @brief Recibe el retorno de las demas funciones controller para mostrar un mensaje al usuario
/// 		informandole sobre la ejecucion de la opcion ingresada previamente.
///
/// @param opcionElejida int - la opcion que ingreso el usuario previamente.
/// @param respuestaController int - el retorno de la opcion ingresada.
void controller_respuestaParaUsuario(int opcionElejida, int respuestaController);

#endif /* CONTROLLER_H_ */
