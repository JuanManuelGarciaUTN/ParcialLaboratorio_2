/*
 * controller.c
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#include "controller.h"

int controller_menuPrincipal(void)
{
	int opcionElejida;

	MostrarMenuPrincipal();
	PedirEnteroValidado("Ingrese Opcion a realizar: ", "ERROR, opcion inexistente \n", &opcionElejida, 1, 7);

	return opcionElejida;
}


int controller_cargarLibros(LinkedList* listaLibros)
{
	int sePudoCargar;
	sePudoCargar = -3;

	if(listaLibros != NULL)
	{
		sePudoCargar = CargarDesdeArchivoLinkedList(listaLibros, parser_CagarLibros);
	}

	return sePudoCargar;
}

int controller_cargarEditoriales(LinkedList* listaEditoriales)
{
	int sePudoCargar;
	sePudoCargar = -3;

	if(listaEditoriales != NULL)
	{
		sePudoCargar = CargarDesdeArchivoLinkedList(listaEditoriales, parser_CagarEditoriales);
	}

	return sePudoCargar;
}

int controller_ordenarListaPorAutor(LinkedList* listaLibros)
{
	int sePudoOrdenar;
	sePudoOrdenar = 0;

	if(listaLibros != NULL && ll_len(listaLibros) > 0)
	{
		if(ll_sort(listaLibros, libro_determinarOrdenPorAutor, 1) == 0)
		{
			sePudoOrdenar = 1;
		}
	}

	return sePudoOrdenar;
}

int controller_mostrarListaLibros(LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	int sePudoMostrar;
	sePudoMostrar = 0;

	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		sePudoMostrar = MostrarTodosLosLibros(listaLibros, listaEditoriales);
	}

	return sePudoMostrar;
}

int controller_guardarListaLibrosEditorialMinotauro(LinkedList* listaLibros)
{
	int sePudoGuardar;
	char path[50];
	int esUnNombreValido;
	LinkedList* listaLibrosMinotauro = NULL;
	sePudoGuardar = -2;

	if(listaLibros != NULL && ll_len(listaLibros) > 0)
	{
		sePudoGuardar = -1;
		listaLibrosMinotauro = ll_filter(listaLibros, libro_filtrarEditorialMinotauro);

		if(listaLibrosMinotauro != NULL && ll_len(listaLibrosMinotauro) > 0)
		{
			sePudoGuardar = 0;
			esUnNombreValido = PedirNombreArchivoSinExtension("Ingrese el nombre del archivo SIN su extension: ", "ERROR, no es un nombre de archivo valido\n", path, 50);

			if(esUnNombreValido)
			{
				FormatearPathArchivo(path, 1);
				sePudoGuardar = GuardarListaLibroEnArchivo(path, listaLibrosMinotauro);
			}
		}
		free(listaLibrosMinotauro);
	}

	return sePudoGuardar;
}

int controller_mapeoListaLibros(LinkedList* listaLibros)
{
	int seMapeo;
	LinkedList* copiaListaLibros = NULL;

	seMapeo = -1;

	if(listaLibros != NULL)
	{
		copiaListaLibros = ll_clone(listaLibros);
		ll_map(copiaListaLibros, libro_mapearLibroSegunEditorial);
		seMapeo = GuardarListaLibroEnArchivo("archivos/mapeado.csv", copiaListaLibros);
		ll_deleteLinkedList(copiaListaLibros);
	}
	return seMapeo;
}

int controller_salirDelPrograma(void)
{
	return 1;
}

void controller_respuestaParaUsuario(int opcionElejida, int respuestaController)
{
	switch(opcionElejida)
	{
		case 1:
			MostrarRespuestaCargarLibros(respuestaController);
			break;

		case 2:
			MostrarRespuestaCargarEditoriales(respuestaController);
			break;

		case 3:
			MostrarRespuestaOrdenarLista(respuestaController);
			break;

		case 4:
			MostrarRespuestaMostrarLista(respuestaController);
			break;

		case 5:
			MostrarRespuestaGuardarLibrosMinotauro(respuestaController);
			break;

		case 6:
			MostrarRespuestaMapeo(respuestaController);
			break;

		case 7:
			MostrarRespuestaSalirDelPrograma();
			break;
	}
}
