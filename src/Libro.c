/*
 * eLibro.c
 *
 *  Created on: 26 nov. 2021
 *      Author: juanm
 */

#include "Libro.h"

eLibro* libro_crearNuevo()
{
	eLibro* nuevoLibro = NULL;

	nuevoLibro = (eLibro*)malloc(sizeof(eLibro));

	return nuevoLibro;
}

eLibro* libro_crearNuevoConParametros(int id, char* titulo, char* autor, float precio, int idEditorial)
{
	eLibro* nuevoLibro = NULL;

	nuevoLibro = libro_crearNuevo();

	if(nuevoLibro != NULL && titulo != NULL && autor != NULL)
	{
		if(libro_setId(nuevoLibro, id) != 1 || libro_setTitulo(nuevoLibro, titulo) != 1 || libro_setAutor(nuevoLibro, autor) != 1 || libro_setPrecio(nuevoLibro, precio) != 1 || libro_setIdEditorial(nuevoLibro, idEditorial) != 1)
		{
			free(nuevoLibro);
			nuevoLibro = NULL;
		}
	}

	return nuevoLibro;
}

int libro_setId(eLibro* this, int id)
{
	int seteoCorrecto;
	seteoCorrecto = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		seteoCorrecto = 1;
	}

	return seteoCorrecto;
}

int libro_getId(eLibro* this, int* id)
{
	int seObtuvoId;
	seObtuvoId = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		seObtuvoId = 1;
	}

	return seObtuvoId;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
	int seteoCorrecto;
	seteoCorrecto = -1;

	if(this != NULL && titulo != NULL && strlen(titulo) < LONGITUD_TITULO)
	{
		strcpy(this->titulo, titulo);
		seteoCorrecto = 1;
	}

	return seteoCorrecto;
}

int libro_getTitulo(eLibro* this, char* titulo)
{
	int seObtuvoTitulo;
	seObtuvoTitulo = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo, this->titulo);
		seObtuvoTitulo = 1;
	}

	return seObtuvoTitulo;
}

int libro_setAutor(eLibro* this, char* autor)
{
	int seteoCorrecto;
	seteoCorrecto = -1;

	if(this != NULL && autor != NULL && strlen(autor) < LONGITUD_AUTOR)
	{
		strcpy(this->autor, autor);
		seteoCorrecto = 1;
	}

	return seteoCorrecto;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int seObtuvoAutor;
	seObtuvoAutor = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(autor, this->autor);
		seObtuvoAutor = 1;
	}

	return seObtuvoAutor;
}

int libro_setPrecio(eLibro* this, float precio)
{
	int seteoCorrecto;
	seteoCorrecto = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		seteoCorrecto = 1;
	}

	return seteoCorrecto;
}

int libro_getPrecio(eLibro* this, float* precio)
{
	int seObtuvoPrecio;
	seObtuvoPrecio = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		seObtuvoPrecio = 1;
	}

	return seObtuvoPrecio;
}

int libro_setIdEditorial(eLibro* this, int idEditorial)
{
	int seteoCorrecto;
	seteoCorrecto = -1;

	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		seteoCorrecto = 1;
	}

	return seteoCorrecto;
}

int libro_getIdEditorial(eLibro* this, int* idEditorial)
{
	int seObtuvoIdEditorial;
	seObtuvoIdEditorial = -1;

	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		seObtuvoIdEditorial = 1;
	}

	return seObtuvoIdEditorial;
}

int libro_determinarOrdenPorAutor(void* pLibroUno, void* pLibroDos)
{
	int orden;
	eLibro* auxLibro = NULL;
	char autorLibroUno[LONGITUD_AUTOR];
	char autorLibroDos[LONGITUD_AUTOR];

	orden = 0;

	if(pLibroUno != NULL && pLibroDos != NULL)
	{
		auxLibro = (eLibro*)pLibroUno;
		libro_getAutor(auxLibro, autorLibroUno);

		auxLibro = (eLibro*)pLibroDos;
		libro_getAutor(auxLibro, autorLibroDos);

		if(strcmp(autorLibroUno, autorLibroDos) > 0)
		{
			orden = 1;
		}
		else
		{
			if(strcmp(autorLibroUno, autorLibroDos) < 0)
			{
				orden = -1;
			}
		}
	}

	return orden;
}

int libro_mostrarEnPantallaSinAutor(eLibro* this)
{
	int sePudoImprimir;
	sePudoImprimir = 0;

	if(this != NULL)
	{
		printf("%-4d  %-50s %-30s %7.2f  ", this->id, this->titulo, this->autor, this->precio);
	}

	return sePudoImprimir;
}

int libro_filtrarEditorialMinotauro(void* element)
{
	int esMinutauro;
	int editorial;
	eLibro* auxLibro = NULL;
	esMinutauro = -1;

	if(element != NULL)
	{
		esMinutauro = 0;
		auxLibro = (eLibro*)element;
		libro_getIdEditorial(auxLibro, &editorial);

		if(editorial == 4)
		{
			esMinutauro = 1;
		}
	}

	return esMinutauro;
}

eLibro* libro_desempacar(void* element)
{
	eLibro* pLibro = NULL;

	if(element != NULL)
	{
		pLibro = (eLibro*)element;
	}

	return pLibro;
}

int GuardarListaLibroEnArchivo(char* path, LinkedList* listaLibros)
{
	int sePudoGuardar;
	int longitud;
	Node* nodoIterarLista = NULL;
	FILE* pArchivo = NULL;

	sePudoGuardar = -1;

	if(listaLibros != NULL && ll_len(listaLibros) > 0 && path != NULL)
	{
		sePudoGuardar = 0;
		longitud = ll_len(listaLibros);
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			fprintf(pArchivo, "id,titulo,autor,precio,idEditorial\n");

			nodoIterarLista = listaLibros->pFirstNode;

			for(int i=0; i<longitud; i++)
			{
				libro_agregarEnArchivoCsv(nodoIterarLista->pElement, pArchivo);
				nodoIterarLista = nodoIterarLista->pNextNode;
			}

			sePudoGuardar = 1;
			fclose(pArchivo);
		}
	}

	return sePudoGuardar;
}

int libro_agregarEnArchivoCsv(void* element, FILE* pArchivo)
{
	int sePudoAgregar;
	eLibro* pLibro = NULL;

	sePudoAgregar = 0;

	if(element != NULL && pArchivo != NULL)
	{
		pLibro = libro_desempacar(element);
		fprintf(pArchivo, "%d,%s,%s,%f,%d\n", pLibro->id, pLibro->titulo, pLibro->autor, pLibro->precio, pLibro->idEditorial);
		sePudoAgregar = 1;
	}

	return sePudoAgregar;
}

int libro_contarLibrosSegunEditorial(void* element)
{
	int contador;
	eLibro* libroAux = NULL;
	contador = 0;

	if(element != NULL)
	{
		libroAux = libro_desempacar(element);

		if(libroAux->idEditorial == 4)
		{
			contador = 1;
		}
	}

	return contador;
}

int libro_aplicarDescuento(eLibro* libro, int descuento)
{
	int seAplicoDescuento;
	float porcentaje;

	seAplicoDescuento = 0;

	if(libro != NULL && descuento > -1 && descuento < 101)
	{
		porcentaje = (float)descuento/100;
		libro->precio = libro->precio * (1-porcentaje);
		seAplicoDescuento = 1;
	}

	return seAplicoDescuento;
}

int libro_mapearLibroSegunEditorial(void* element)
{
	int seMapeo;
	eLibro* libroDesempacado;
	seMapeo = 0;

	if(element != NULL)
	{
		libroDesempacado = libro_desempacar(element);

		if(libroDesempacado->idEditorial == 1 && libroDesempacado->precio >= 300)
		{
			seMapeo = libro_aplicarDescuento(libroDesempacado, 20);
		}
		else
		{
			if(libroDesempacado->idEditorial == 2 && libroDesempacado->precio <= 200)
			{
				seMapeo = libro_aplicarDescuento(libroDesempacado, 10);
			}
		}
	}

	return seMapeo;
}
