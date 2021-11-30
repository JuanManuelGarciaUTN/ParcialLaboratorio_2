/*
 * eLibro.h
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define LONGITUD_TITULO 80
#define LONGITUD_AUTOR 60

typedef struct
{
	int id;
	char titulo[LONGITUD_TITULO];
	char autor[LONGITUD_AUTOR];
	float precio;
	int idEditorial;

}eLibro;


/// @brief Contructor de eLibro sin parametros
///
/// @return eLibro* - (NULL)[No se pudo reservar memoria] - puntero al nuevo eLibro
eLibro* libro_crearNuevo();


/// @brief Contructor de eLibro con parametros.
/// 		Verifica que los parametros sean validos.
///
/// @param id int - id del libro
/// @param titulo char* - nombre del libro
/// @param autor char* - nombre del autor del libro
/// @param precio float - precio del libro
/// @param idEditorial int - id de la editorail del libro
/// @return eLibro* - (NULL)[No se pudo reservar memoria o paramatro invalido] - puntero al nuevo eLibro
eLibro* libro_crearNuevoConParametros(int id, char* titulo, char* autor, float precio, int idEditorial);


/// @brief Setea el id de un eLibro
///
/// @param this eLibro* - puntero a eLibro
/// @param id int - nueva id
/// @return int - (0)[puntero a NULL o id invalido] - (1)[seteo correctamente]
int libro_setId(eLibro* this, int id);


/// @brief Obtiene el id del eLibro y lo devuelve por puntero
///
/// @param this eLibro* - puntero a eLibro
/// @param id int* - puntero para devolver el id
/// @return int - (0)[puntero a NULL] - (1)[obtuvo correctamente]
int libro_getId(eLibro* this, int* id);


/// @brief Setea el titulo de un eLibro
///
/// @param this eLibro* - puntero a eLibro
/// @param titulo char* - nuevo titulo
/// @return int - (0)[puntero a NULL o titulo invalido] - (1)[seteo correctamente]
int libro_setTitulo(eLibro* this, char* titulo);


/// @brief Obtiene el titulo de un eLibro y lo devuelve por puntero
///
/// @param this eLibro* - puntero a eLibro
/// @param titulo char* - puntero para devolver el titulo
/// @return int - (0)[puntero a NULL] - (1)[obtuvo correctamente]
int libro_getTitulo(eLibro* this, char* titulo);


/// @brief setea el autor del eLibro
///
/// @param this eLibro* - puntero a eLibro
/// @param autor char* - nuevo autor
/// @return int - (0)[puntero a NULL o autor invalido] - (1)[seteo correctamente]
int libro_setAutor(eLibro* this, char* autor);


/// @brief Obtiene el autor del eLibro y lo devuelve por puntero
///
/// @param this eLibro* - puntero a eLibro
/// @param autor char* - puntero para devolver el autor
/// @return int - (0)[puntero a NULL] - (1)[obtuvo correctamente]
int libro_getAutor(eLibro* this, char* autor);


/// @brief Setea el precio de un eLibro
///
/// @param this eLibro* - puntero a eLibro
/// @param precio float - nuevo precio
/// @return int - (0)[puntero a NULL o precio invalido] - (1)[seteo correctamente]
int libro_setPrecio(eLibro* this, float precio);


/// @brief Obtiene el precio de un eLibro y lo devuelve por puntero
///
/// @param this eLibro* - puntero a eLibro
/// @param precio float - puntero para devolver precio
/// @return int - (0)[puntero a NULL] - (1)[obtuvo correctamente]
int libro_getPrecio(eLibro* this, float* precio);


/// @brief Setea el idEditorial de un eLibro
///
/// @param this eLibro* - puntero a eLibro
/// @param idEditorial int - nueva idEditorial
/// @return int - (0)[puntero a NULL o idEditorial invalido] - (1)[seteo correctamente]
int libro_setIdEditorial(eLibro* this, int idEditorial);


/// @brief Obtiene el idEditorial de un eLibro y lo devuelve por puntero
///
/// @param this eLibro* - puntero a eLibro
/// @param idEditorial int - puntero para devolver idEditorial
/// @return int - (0)[puntero a NULL] - (1)[obtuvo correctamente]
int libro_getIdEditorial(eLibro* this, int* idEditorial);


/// @brief Recibe dos punteros de tipo void, los desempaca a un puntero eLibro
/// 		y compara el order alfabetico de los autores de cada uno
///
/// @param pLibroUno void* - puntero tipo void del primer eLibro
/// @param pLibroDos void* - puntero tipo void del segundo eLibro
/// @return int - (-1)[autor pLibroDos mayor a pLibroUno] - (0)[son iguales] - (1)[autor pLibroUno mayor a pLibroDos]
int libro_determinarOrdenPorAutor(void* pLibroUno, void* pLibroDos);


/// @brief Recibe un puntero a eLibro y lo imprime en pantalla sin el autor
///
/// @param this eLibro* - puntero a eLibro que se va a imprimir
/// @return int (0)[puntero a NULL] - (1)[se pudo imprimir]
int libro_mostrarEnPantallaSinAutor(eLibro* this);


/// @brief Recibe un puntero de tipo void, lo desempaca en un puntero eLibro
/// 		y verifica si su editorial es "MINOTAURO"
///
/// @param element void* - puntero a elmento a verificar
/// @return int (-1)[puntero a NULL] - (0)[editorial NO es "MINOTAURO"] - (1)[editorial ES "MINOTAURO"]
int libro_filtrarEditorialMinotauro(void* element);


/// @brief Recibe un puntero de tipo void, lo desempaca y lo devuelve como puntero eLibro
///
/// @param element void* - puntero a elmento a desempacar
/// @return eLibro* - (NULL)[puntero a NULL] - (puntero a eLibro)
eLibro* libro_desempacar(void* element);


/// @brief Recibe un path a un archivo, una linked list de eLibro y la guarda en formato texto
///
/// @param path char* - path al archivo donde se guardara la linked list
/// @param listaLibros LinkedList* - linked list de eLibro
/// @return int (-1)[puntero a NULL o lista vacia] - (0)[archivo invalido] - (1)[se guardo correctamente]
int GuardarListaLibroEnArchivo(char* path, LinkedList* listaLibros);


/// @brief Recibe un puntero tipo void de un eLibro, lo desempaca y lo guarda
/// 		 en el archivo recibido en formato de texto.
///
/// @param element void* - puntero de tipo void al eLibro
/// @param pArchivo FILE* - puntero a Archivo
/// @return int (0)[puntero a NULL] - (1)[Se pudo guardar]
int libro_agregarEnArchivoCsv(void* element, FILE* pArchivo);

int libro_contarLibrosSegunEditorial(void* element);

#endif /* LIBRO_H_ */
