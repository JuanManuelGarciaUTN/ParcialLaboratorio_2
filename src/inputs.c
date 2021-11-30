/*
 * input.c
 *
 *  Created on: 12 oct. 2021
 *      Author: juanm
 */

#include"inputs.h"

int PedirSustantivoPropio(char mensaje[], char mensajeError[], char cadena[], int longitud)
{
	int retorno;
	char buffer[longitud];

	retorno = 0;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGets(buffer, longitud) && EsSustantivo(buffer))
		{
			retorno = 1;
			FormatearSustantivoPropio(buffer);
			strcpy(cadena,buffer);
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirNombreArchivo(char mensaje[], char mensajeError[], char cadena[], int longitud)
{
	int retorno;
	int intentos;
	char buffer[longitud];

	retorno = 0;
	intentos = 0;

	while(intentos < 5)
	{
		printf("%s", mensaje);
		if(MiGets(buffer, longitud) && EsArchivo(buffer))
		{
			retorno = 1;
			strcpy(cadena,buffer);
			break;
		}
		printf("%s", mensajeError);

		intentos++;
	}

	return retorno;
}

int PedirNombreArchivoSinExtension(char mensaje[], char mensajeError[], char cadena[], int longitud)
{
	int retorno;
	int intentos;
	char buffer[longitud];

	retorno = 0;
	intentos = 0;

	while(intentos < 5)
	{
		printf("%s", mensaje);
		if(MiGets(buffer, longitud) && EsArchivoSinExtension(buffer))
		{
			retorno = 1;
			strcpy(cadena,buffer);
			break;
		}
		printf("%s", mensajeError);

		intentos++;
	}

	return retorno;
}


int PedirEnteroValidado(char mensaje[], char mensajeError[], int* pEntero, int minimo, int maximo)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			if(enteroIngresado >= minimo && enteroIngresado <= maximo)
			{
				*pEntero = enteroIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirEnteroMayorQue(char mensaje[], char mensajeError[], int* pEntero, int mayorQue)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			if(enteroIngresado > mayorQue)
			{
				*pEntero = enteroIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirEntero(char mensaje[], char mensajeError[], int* pEntero)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			*pEntero = enteroIngresado;
			retorno = 1;
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int MiGetInt(int* pEntero)
{
	int respuesta;
	char buffer[TAMANIO_BUFFER];

	respuesta = 0;

	if(pEntero != NULL)
	{
		if(MiGets(buffer, TAMANIO_BUFFER) && EsEntero(buffer))
		{
			*pEntero = atoi(buffer);
			respuesta = 1;
		}
	}

	return respuesta;
}

int MiGets(char cadena[], int longitud)
{
	fflush(stdin);
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
			return 1;
		}
	}
	return 0;
}

//Funciones para validar si una cadena es de un tipo segun el formato Es[validacio] ej EsEntero, etc
int EsEntero(char cadena[])
{
	int i;
	int esNumerica;

	i = 0;
	esNumerica = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9')  && !(i==0 && cadena[0] == '-'))
			{
				esNumerica = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esNumerica = 0;
	}

	return esNumerica;
}

int EsSustantivo(char cadena[])
{
	int i;
	int esSustantivoPropio;

	i = 0;
	esSustantivoPropio = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(iscntrl(cadena[i]) || isdigit(cadena[i]) || ispunct(cadena[i]))
			{
				esSustantivoPropio = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esSustantivoPropio = 0;
	}

	return esSustantivoPropio;
}

int EsArchivo(char cadena[])
{
	int i;
	int cantidadPuntos;
	int esUnArchivo;

	i = 0;
	cantidadPuntos = 0;
	esUnArchivo = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] == '"' || cadena[i] == ':' || cadena[i] == '\\' || cadena[i] == '/' || cadena[i] == '*' || cadena[i] == '?' || cadena[i] == '|' || cadena[i] == '<' || cadena[i] == '>' || (i==0 && cadena[i] == ' '))
			{
				esUnArchivo = 0;
				break;
			}

			if(cadena[i] == '.')
			{
				cantidadPuntos++;
				if(cantidadPuntos == 1)
				{
					esUnArchivo = 1;
				}
				else
				{
					esUnArchivo = 0;
					break;
				}
			}

			i++;
		}
	}

	return esUnArchivo;
}


int EsArchivoSinExtension(char cadena[])
{
	int i;
	int esUnArchivo;

	i = 0;
	esUnArchivo = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] == '.' ||cadena[i] == '"' || cadena[i] == ':' || cadena[i] == '\\' || cadena[i] == '/' || cadena[i] == '*' || cadena[i] == '?' || cadena[i] == '|' || cadena[i] == '<' || cadena[i] == '>' || (i==0 && cadena[i] == ' '))
			{
				esUnArchivo = 0;
				break;
			}
			i++;
		}
	}

	return esUnArchivo;
}

void FormatearSustantivoPropio(char cadena[])
{
	int i;
	i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(i==0 || isspace(cadena[i-1]))
			{
				cadena[i] = toupper(cadena[i]);
			}
			else
			{
				cadena[i] = tolower(cadena[i]);
			}
			i++;
		}
	}
}
