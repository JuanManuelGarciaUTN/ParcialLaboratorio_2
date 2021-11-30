
#include "parser.h"

int parser_CagarLibros(char* path, LinkedList* listaLibros)
{
	int sePudoCargar;
	int tipoDeArchivo;
	sePudoCargar = -1;

	tipoDeArchivo = DeterminarSiArchivoEsTexto(path);

	switch(tipoDeArchivo)
	{
		case 0:
			sePudoCargar = parser_CagarLibrosDesdeBinario(path, listaLibros);
			break;

		case 1:
			sePudoCargar = parser_CagarLibrosDesdeTexto(path, listaLibros);
			break;
	}

	return sePudoCargar;
}

int parser_CagarLibrosDesdeTexto(char* path, LinkedList* listaLibros)
{
	int sePudoCargar;
	int id;
	char titulo[LONGITUD_TITULO];
	char autor[LONGITUD_AUTOR];
	float precio;
	int idEditorial;
	FILE* pArchivo = NULL;
	eLibro* auxLibro;

	sePudoCargar = -1;

	if(listaLibros != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			fscanf(pArchivo, "%*[^,], %*[^,], %*[^,], %*[^\n]\n");

			while(!feof(pArchivo))
			{
				sePudoCargar = 1 && sePudoCargar != 0;

				fscanf(pArchivo, "%d,%[^,],%[^,],%f,%d\n", &id, titulo, autor, &precio, &idEditorial);

				auxLibro = libro_crearNuevoConParametros(id, titulo, autor, precio, idEditorial);

				if(auxLibro != NULL)
				{
					ll_add(listaLibros, auxLibro);
				}
				else
				{
					sePudoCargar = 0;
				}
			}
			fclose(pArchivo);
		}
	}

	return sePudoCargar;
}

int parser_CagarLibrosDesdeBinario(char* path, LinkedList* listaLibros)
{
	int sePudoCargar;
	FILE* pArchivo = NULL;
	eLibro auxLibro;
	eLibro* nuevoLibro;

	sePudoCargar = -1;

	if(listaLibros != NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
		{
			while(!feof(pArchivo))
			{
				sePudoCargar = 1 && sePudoCargar != 0;

				fread(&auxLibro, sizeof(eLibro), 1, pArchivo);

				nuevoLibro = libro_crearNuevoConParametros(auxLibro.id, auxLibro.titulo, auxLibro.autor, auxLibro.precio, auxLibro.idEditorial);

				if(nuevoLibro != NULL)
				{
					ll_add(listaLibros, nuevoLibro);
				}
				else
				{
					sePudoCargar = 0;
				}
			}
			fclose(pArchivo);
		}
	}

	return sePudoCargar;
}


int parser_CagarEditoriales(char* path, LinkedList* listaEditoriales)
{
	int sePudoCargar;
	int tipoDeArchivo;
	sePudoCargar = -1;

	tipoDeArchivo = DeterminarSiArchivoEsTexto(path);

	switch(tipoDeArchivo)
	{
		case 0:
			sePudoCargar = parser_CagarEditorialesDesdeBinario(path, listaEditoriales);
			break;

		case 1:
			sePudoCargar = parser_CagarEditorialesDesdeTexto(path, listaEditoriales);
			break;
	}

	return sePudoCargar;
}

int parser_CagarEditorialesDesdeTexto(char* path, LinkedList* listaEditoriales)
{
	int sePudoCargar;
	char nombre[LONGITUD_NOMBRE_EDITORIAL];
	int idEditorial;
	FILE* pArchivo = NULL;
	eEditorial* auxEditorial;

	sePudoCargar = -1;

	if(listaEditoriales != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			fscanf(pArchivo, "%*[^,], %*[^\n]\n");

			while(!feof(pArchivo))
			{
				sePudoCargar = 1 && sePudoCargar != 0;
				fscanf(pArchivo, "%d,%[^\n]\n", &idEditorial, nombre);

				auxEditorial = editorial_crearNuevoConParametros(idEditorial, nombre);

				if(auxEditorial != NULL)
				{
					ll_add(listaEditoriales, auxEditorial);
				}
				else
				{
					sePudoCargar = 0;
				}
			}
			fclose(pArchivo);
		}
	}

	return sePudoCargar;
}

int parser_CagarEditorialesDesdeBinario(char* path, LinkedList* listaEditoriales)
{
	int sePudoCargar;
	FILE* pArchivo = NULL;
	eEditorial auxEditorial;
	eEditorial* nuevaEditorial;

	sePudoCargar = -1;

	if(listaEditoriales != NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
		{
			while(!feof(pArchivo))
			{
				sePudoCargar = 1 && sePudoCargar != 0;

				fread(&auxEditorial, sizeof(eLibro), 1, pArchivo);

				nuevaEditorial = editorial_crearNuevoConParametros(auxEditorial.idEditorial, auxEditorial.nombre);

				if(nuevaEditorial != NULL)
				{
					ll_add(listaEditoriales, nuevaEditorial);
				}
				else
				{
					sePudoCargar = 0;
				}
			}
			fclose(pArchivo);
		}
	}

	return sePudoCargar;
}

int DeterminarSiArchivoEsTexto(char* path)
{
	int esTexto;
	char cadenaHeader[15];
	FILE* pArchivo;
	esTexto = -1;

	pArchivo = fopen(path, "r");

	if(pArchivo != NULL)
	{
		esTexto = 0;
		fscanf(pArchivo, "%[^,]\n", cadenaHeader);

		if(cadenaHeader[0]== 'i' && cadenaHeader[1] == 'd')
		{
			esTexto = 1;
		}

		fclose(pArchivo);
	}

	return esTexto;
}


