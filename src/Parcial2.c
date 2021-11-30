/*
 ============================================================================
 Name        : Parcial2.c
 Author      : Juan Manuel Garcia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*ENUNCIADO:
 * Desarrollar en ANSI C:
 * Un programa que realice lo siguiente:
 *
 * 1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
 * eLibro.
 * ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
 *
 * 2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
 * eEditorial.
 * ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
 *
 * 3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
 * ordenamiento “Autor” de manera ascendente.
 *
 * 4. Imprimir por pantalla todos los datos de los libros.
 * ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
 *
 * 5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
 * función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "controller.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcionEligida;
	int respuestaController;
	LinkedList* listaLibros = NULL;
	LinkedList* listaEditoriales = NULL;

	listaLibros = ll_newLinkedList();
	listaEditoriales = ll_newLinkedList();

	do
	{
		opcionEligida = controller_menuPrincipal();

		switch(opcionEligida)
		{
			case 1:
				respuestaController = controller_cargarLibros(listaLibros);
				break;

			case 2:
				respuestaController = controller_cargarEditoriales(listaEditoriales);
				break;

			case 3:
				respuestaController = controller_ordenarListaPorAutor(listaLibros);
				break;

			case 4:
				respuestaController = controller_mostrarListaLibros(listaLibros, listaEditoriales);
				break;

			case 5:
				respuestaController = controller_guardarListaLibrosEditorialMinotauro(listaLibros);
				break;

			case 6:
				respuestaController = controller_salirDelPrograma();
				break;
		}

		controller_respuestaParaUsuario(opcionEligida, respuestaController);

	} while(opcionEligida != 6);

	return EXIT_SUCCESS;
}
