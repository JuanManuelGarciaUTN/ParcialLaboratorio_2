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
 * 1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades
 * eLibro.
 * ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de comandos.
 *
 * 2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades
 * eEditorial.
 * ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de comandos.
 *
 * 3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de
 * ordenamiento �Autor� de manera ascendente.
 *
 * 4. Imprimir por pantalla todos los datos de los libros.
 * ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.
 *
 * 5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la
 * funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
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
