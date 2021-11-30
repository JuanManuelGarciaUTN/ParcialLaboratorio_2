/*
 * menu.c
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#include "menu.h"

void MostrarMenuPrincipal(void)
{
	printf("Menu Principal:\n\n"
			"1 -> CARGAR datos de Libros desde Archivo \n"
			"2 -> CARGAR datos de Editoriales desde Archivo \n"
			"3 -> ORDENAR Lista de Libros por Autor\n"
			"4 -> MOSTRAR Lista de Libros \n"
			"5 -> GUARDAR Libros de Editorial MINOTAURO en Archivo \n"
			"6 -> Salir del Programa \n\n");
}

void MostrarRespuestaCargarLibros(int respuestaController)
{
	system("cls");
	switch(respuestaController)
	{
		case -3:
			printf("Error, Lista Puntero a NULL\n\n");
			break;

		case -2:
			printf("Error, SUPERO Limite de Intentos de ingresar el NOMBRE de Archivo a Cargar\n\n");
			break;

		case -1:
			printf("Error, Archivo NO Existe\n\n");
			break;

		case 0:
			printf("Se Cargo PARCIALMENTE la Lista de Libros, Archivo con datos corruptos o invalidos\n\n");
			break;

		case 1:
			printf("Se Cargo CORRECTAMENTE la Lista de Libros\n\n");
			break;
	}
}

void MostrarRespuestaCargarEditoriales(int respuestaController)
{
	system("cls");
	switch(respuestaController)
	{
		case -3:
			printf("Error, Lista Puntero a NULL\n\n");
			break;

		case -2:
			printf("Error, SUPERO Limite de Intentos de ingresar el NOMBRE de Archivo a Cargar\n\n");
			break;

		case -1:
			printf("Error, Archivo NO Existe\n\n");
			break;

		case 0:
			printf("Se Cargo PARCIALMENTE la Lista de Editoriales, Archivo con datos corruptos o invalidos\n\n");
			break;

		case 1:
			printf("Se Cargo CORRECTAMENTE la Lista de Editoriales\n\n");
			break;
	}
}

void MostrarRespuestaOrdenarLista(int respuestaController)
{
	system("cls");
	switch(respuestaController)
	{
		case 0:
			printf("Error, La Lista Esta VACIA. Debe Cargarla previamente\n\n");
			break;

		case 1:
			printf("Se Ordeno CORRECTAMENTE la Lista \n\n");
			break;
	}
}

void MostrarRespuestaMostrarLista(int respuestaController)
{
	switch(respuestaController)
	{
		case 0:
			system("cls");
			printf("Error, La Lista Esta VACIA. Debe Cargarla previamente\n\n");
			break;

		case 1:
			PresioneEnterParaContinuar();
			system("cls");
			break;
	}
}


void MostrarRespuestaGuardarLibrosMinotauro(int respuestaController)
{
	system("cls");

	switch(respuestaController)
	{
		case -2:
			printf("Error, La Lista de Libros Esta VACIA. Debe Cargarla previamente\n\n");
			break;

		case -1:
			printf("NO hay Libros de Editorial Minotauro Para Guardar\n\n");
			break;

		case 0:
			printf("Error, SUPERO el Limite de Intentos para Ingresar el Nombre del Archivo\n\n");
			break;

		case 1:
			printf("Se Guardaron CORRECTAMENTE los Libros de Editorial Minotauro\n\n");
			break;
	}
}

void MostrarRespuestaSalirDelPrograma(void)
{
	system("cls");
	printf("Gracias, Vuelva Prontro\n\n");
}

int ConsultarSobrescribirLista(LinkedList* lista, char* mensaje)
{
	int crearDesdeCero;
	crearDesdeCero = -1;

	if(lista != NULL)
	{
		crearDesdeCero = 1;

		if(ll_len(lista) > 0)
		{
			printf("%s", mensaje);
			crearDesdeCero = PreguntarSiDeseaSobrescribir();
		}
	}

	return crearDesdeCero;
}


int PreguntarSiDeseaSobrescribir(void)
{
	int deseoSobrescribir;

	printf("¿Desea Sobrescribir?\n"
			"1 -> SI\n"
			"0 -> NO\n\n");

	PedirEnteroValidado("Respuesta: ", "Opcion inexistente\n", &deseoSobrescribir, 0, 1);

	return deseoSobrescribir;
}

void PresioneEnterParaContinuar(void)
{
	fflush(stdin);
	printf("\nPresione Enter para Continuar...\n");
	getchar();
}

int FormatearPathArchivo(char* path, int conExtensionCsv)
{
	int seFormateo;
	char pathCompleto[50]="archivos/";

	seFormateo = 0;

	if(path != NULL)
	{
		strcat(pathCompleto, path);

		if(conExtensionCsv == 1)
		{
			strcat(pathCompleto, ".csv");
		}

		strcpy(path, pathCompleto);
		seFormateo = 1;
	}

	return seFormateo;
}
