/*
 * nexoLinkedList.h
 *
 *  Created on: 27 nov. 2021
 *      Author: juanm
 */

#ifndef NEXOLINKEDLIST_H_
#define NEXOLINKEDLIST_H_

#include "Editorial.h"
#include "Libro.h"
#include "LinkedList.h"
#include "menu.h"


/// @brief Recibe una linked list de eLibro y otra de eEditorial
/// 		y muestra en pantalla todos los eLibro con el nombre de su respectiva editorial
///
/// @param listaLibros LinkedList* - lista de eLibro a mostrar
/// @param listaEditoriales LinkedList* - lista de eEditorial a mostrar
/// @return int (0)[puntero a NULL] - (1)[se mostro correctamente]
int MostrarTodosLosLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);


/// @brief Recibe un libro, imprime sus datos y el nombre de la editorial vinculada al mismo
///
/// @param libro eLibro* - eLibro a mostrar en pantalla
/// @param listaEditoriales LinkedList* - linked list con todas las eEditorial.
/// @return int (0)[puntero a NULL] - (1)[se imprimio correctamente]
int MostrarLibroConAutor(eLibro* libro, LinkedList* listaEditoriales);


/// @brief Recibe una linked list, le pide al usuario que ingrese un nombre de archivo con extension
/// 		y carga la linked list segun la funcion criterio del parametro.
///
/// @param lista LinkedList* - lista que se va a cargar
/// @param pFuncCargarLista *pFunc - puntero a funcion criterio para cargar la linked list
/// @return	int (-4)[No se quiso sobrescribir la lista] - (-3)[lista puntero a NULL] - (-2)[Supero limite de errores ingresando el nombre del archivo] - (-1)[Archivo no existe] - (0)[Se Cargo parcialmente la lista] - (1)[Se Cargo la Lista]
int CargarDesdeArchivoLinkedList(LinkedList* lista, int(*pFuncCargarLista)(char*, LinkedList*));



#endif /* NEXOLINKEDLIST_H_ */
