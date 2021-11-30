/*
 * nexoLinkedList.c
 *
 *  Created on: 27 nov. 2021
 *      Author: juanm
 */

#include "nexoLinkedList.h"

int MostrarTodosLosLibros(LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	int existeAlMenosUno;
	int longitudLibros;
	Node* nodoIterarLibros;
	eLibro* libroImprimir;
	existeAlMenosUno = 0;

	if(listaLibros != NULL && listaEditoriales != NULL && ll_len(listaLibros)>0 && ll_len(listaEditoriales)>0)
	{
		existeAlMenosUno = 1;
		longitudLibros = ll_len(listaLibros);
		printf("Id    Titulo                                             Autor                          Precio   Editorial\n\n");

		nodoIterarLibros = listaLibros->pFirstNode;
		for(int i=0; i<longitudLibros; i++)
		{
			libroImprimir = libro_desempacar(nodoIterarLibros->pElement);
			MostrarLibroConAutor(libroImprimir, listaEditoriales);

			nodoIterarLibros = nodoIterarLibros->pNextNode;
		}
	}

	return existeAlMenosUno;
}

int MostrarLibroConAutor(eLibro* libro, LinkedList* listaEditoriales)
{
	int seImprimio;
	seImprimio = 0;

	if(libro != NULL && listaEditoriales != NULL)
	{
		libro_mostrarEnPantallaSinAutor(libro);
		editorial_imprimirAutorPorId(listaEditoriales, libro->idEditorial);
		printf("\n");
		seImprimio = 1;
	}
	return seImprimio;
}

int CargarDesdeArchivoLinkedList(LinkedList* lista, int(*pFuncCargarLista)(char*, LinkedList*))
{
	char path[50];
	int esUnNombreValido;
	int sePudoCargar;
	int crearDesdeCero;

	sePudoCargar = -3;

	if(lista != NULL)
	{
		sePudoCargar = -2;
		esUnNombreValido = PedirNombreArchivo("Ingrese el nombre del archivo a leer con su extension: ", "ERROR, no es un nombre de archivo valido\n", path, 50);

		crearDesdeCero = ConsultarSobrescribirLista(lista, "La lista ya se encuentra cargada\n\n");

		if(esUnNombreValido)
		{
			sePudoCargar = -4;
			if(crearDesdeCero)
			{
				FormatearPathArchivo(path, 0);
				ll_clear(lista);
				sePudoCargar = pFuncCargarLista(path, lista);
			}
		}
	}

	return sePudoCargar;
}




