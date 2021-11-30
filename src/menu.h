/*
 * menu.h
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "LinkedList.h"


/// @brief Muestra en pantalla el menu principal de opciones
///
void MostrarMenuPrincipal(void);


/// @brief Muestra la respuesta correspondiente al retorno del controller cargar libros
///
/// @param respuestaController int - retorno del controller cargar libros
void MostrarRespuestaCargarLibros(int respuestaController);


/// @brief Muestra la respuesta correspondiente al retorno del controller cargar editoriales
///
/// @param respuestaController int - retorno del controller cargar editoriales
void MostrarRespuestaCargarEditoriales(int respuestaController);


/// @brief Muestra la respuesta correspondiente al retorno del controller ordenar lista
///
/// @param respuestaController int - retorno del controller ordenar lista
void MostrarRespuestaOrdenarLista(int respuestaController);


/// @brief Muestra la respuesta correspondiente al retorno del controller mostrar lista
///
/// @param respuestaController int - retorno del controller mostrar lista
void MostrarRespuestaMostrarLista(int respuestaController);


/// @brief Muestra la respuesta correspondiente al retorno del controller guardar libros minotauro
///
/// @param respuestaController int - retorno del controller guardar libros minotauro
void MostrarRespuestaGuardarLibrosMinotauro(int respuestaController);


/// @brief Despide gentilmente al usuario
///
void MostrarRespuestaSalirDelPrograma(void);


/// @brief Le pregunta al usuario si desea sobrescribir y pide que ingrese 1 o 0 segun corresponda
///
/// @return int (0)[No desea sobrescribir] - (1)[si desea sobrescribir]
int PreguntarSiDeseaSobrescribir(void);


/// @brief Si la linked list no esta vacia, pregunta al usuario si desea sobrescribirla
///
/// @param lista LinkedList* - linked list a consultar si desea sobrescribir
/// @param mensaje - el mensaje que se le muestra al usuario.
/// @return int (-1)[puntero a NULL] - (0)[usuario no desea sobrescribir] - (1)[linked list ya esta vacia o el usuario desea sobrescribirla]
int ConsultarSobrescribirLista(LinkedList* lista, char* mensaje);


/// @brief Espera que el usuario presione enter para continuar la ejecucion del programa
///
void PresioneEnterParaContinuar(void);

/// @brief Dado un string de path, lo formatea para que inicie en "archivos/path" y se le agrega
/// 		la extension .csv de ser deseado
///
/// @param path char* - path a formatear para que inicie en "archivos/"
/// @param conExtensionCsv int - flag para determinar si agregar o no la extension .csv al final
/// @return int (0)[puntero a NULL] - (1)[formateo correcto]
int FormatearPathArchivo(char* path, int conExtensionCsv);

#endif /* MENU_H_ */
