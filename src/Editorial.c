/*
 * eEditorial.c
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#include "Editorial.h"


eEditorial* editorial_crearNuevo()
{
	eEditorial* nuevaEditorial = NULL;

	nuevaEditorial = (eEditorial*)malloc(sizeof(eEditorial));

	return nuevaEditorial;
}

eEditorial* editorial_crearNuevoConParametros(int idEditorial, char* nombre)
{
	eEditorial* nuevaEditorial = NULL;

	nuevaEditorial = editorial_crearNuevo();

	if(nuevaEditorial != NULL && nombre != NULL)
	{
		if(editorial_setId(nuevaEditorial, idEditorial) != 1 || editorial_setNombre(nuevaEditorial, nombre) != 1)
		{
			free(nuevaEditorial);
			nuevaEditorial = NULL;
		}
	}

	return nuevaEditorial;
}

int editorial_setId(eEditorial* this, int id)
{
	int seSeteo;
	seSeteo = 0;

	if(this != NULL && id > 0)
	{
		this->idEditorial = id;
		seSeteo = 1;
	}

	return seSeteo;
}

int editorial_getId(eEditorial* this, int* id)
{
	int seObtuvoId;
	seObtuvoId = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->idEditorial;
		seObtuvoId = 1;
	}

	return seObtuvoId;
}

int editorial_setNombre(eEditorial* this, char* nombre)
{
	int seSeteo;
	seSeteo = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		seSeteo = 1;
	}

	return seSeteo;
}

int editorial_getNombre(eEditorial* this, char* nombre)
{
	int seObtuvoNombre;
	seObtuvoNombre = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		seObtuvoNombre = 1;
	}

	return seObtuvoNombre;
}

int editorial_mostrarEnPantallaNombre(eEditorial* this)
{
	int seImprimio;
	seImprimio = 0;

	if(this != NULL)
	{
		printf("%s", this->nombre);
	}

	return seImprimio;
}

int editorial_compararId(void* element, int id)
{
	int sonIguales;
	eEditorial* editorialUnboxed;
	sonIguales = 0;

	if(element != NULL)
	{
		editorialUnboxed = editorial_desempacar(element);

		if(id == editorialUnboxed->idEditorial)
		{
			sonIguales = 1;
		}
	}

	return sonIguales;
}

eEditorial* editorial_desempacar(void* element)
{
	eEditorial* editorialDesempacada = NULL;

	if(element != NULL)
	{
		editorialDesempacada = (eEditorial*)element;
	}

	return editorialDesempacada;
}

int editorial_imprimirAutorPorId(LinkedList* listaEditoriales, int id)
{
	int sePudoImprimir;
	eEditorial* editorial;
	sePudoImprimir = 0;

	if(listaEditoriales != NULL)
	{
		editorial = editorial_buscarPorId(listaEditoriales, id);
		sePudoImprimir = editorial_mostrarEnPantallaNombre(editorial);
	}

	return sePudoImprimir;
}

eEditorial* editorial_buscarPorId(LinkedList* listaEditoriales, int id)
{
	eEditorial* editorialEncontrada = NULL;
	Node* nodoIteradorEditoriales = NULL;
	void* element = NULL;
	int longitud;

	if(listaEditoriales != NULL && id > 0)
	{
		longitud = ll_len(listaEditoriales);

		nodoIteradorEditoriales = listaEditoriales->pFirstNode;
		for(int i=0; i<longitud; i++)
		{
			element = nodoIteradorEditoriales->pElement;

			if(editorial_compararId(element, id) == 1)
			{
				editorialEncontrada = editorial_desempacar(element);
				break;
			}
			nodoIteradorEditoriales = nodoIteradorEditoriales->pNextNode;
		}
	}

	return editorialEncontrada;
}

