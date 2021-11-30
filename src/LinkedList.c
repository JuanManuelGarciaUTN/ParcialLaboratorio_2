#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int longitud;
    longitud = -1;

    if(this != NULL)
    {
    	longitud = this->size;
    }

    return longitud;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;

		for(int i=0; i<nodeIndex; i++)
		{
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
    Node* pNewNode = NULL;
    Node* pNodeAnterior = NULL;

    returnAux = -1;

    if(this != NULL && nodeIndex > -1 && nodeIndex <=ll_len(this))
    {
    	pNewNode = (Node*)malloc(sizeof(Node));

    	if(pNewNode != NULL)
    	{
    		pNewNode->pElement = pElement;

        	if(nodeIndex == 0)
        	{
        		pNewNode->pNextNode = this->pFirstNode;
        		this->pFirstNode = pNewNode;
        	}
        	else
        	{
        		pNodeAnterior = getNode(this, nodeIndex-1);

        		pNewNode->pNextNode = pNodeAnterior->pNextNode;
        		pNodeAnterior->pNextNode = pNewNode;
        	}

        	returnAux = 0;
        	this->size += 1;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux;

    returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);

    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
    Node* pNodeAux = NULL;

    returnAux = -1;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNodeAux = getNode(this, index);
    	if(pNodeAux != NULL)
    	{
    		pNodeAux->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux;
    Node* pNodeRemove = NULL;
    Node* pNodeAnterior = NULL;

    returnAux = -1;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNodeAnterior = getNode(this, index-1);

    	if(pNodeAnterior == NULL)
    	{
    		pNodeRemove = this->pFirstNode;
			this->pFirstNode = pNodeRemove->pNextNode;

			free(pNodeRemove);
    	}
    	else
    	{
    		pNodeRemove = pNodeAnterior->pNextNode;
    		pNodeAnterior->pNextNode = pNodeRemove->pNextNode;

    		free(pNodeRemove);
    	}

    	returnAux = 0;
    	this->size -= 1;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux;
    int longitud;

    returnAux = -1;

    if(this != NULL)
    {
    	longitud = ll_len(this);

    	for(int i=0; i<longitud; i++)
    	{
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;

    returnAux = -1;

    if(this != NULL)
    {
        if(ll_clear(this) == 0)
        {
        	free(this);
        	returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
    int longitud;

    returnAux = -1;

    if(this != NULL)
    {
    	longitud = ll_len(this);

    	for(int i=0; i<longitud; i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}


/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux;
    returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 1;

    	if(ll_len(this) != 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
    returnAux = -1;

    if(this != NULL && index > -1 && index <= ll_len(this))
    {
        if(addNode(this, index, pElement) == 0)
        {
        	returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;

    returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int longitudListaDos;

    returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	longitudListaDos = ll_len(this2);

    	for(int i=0; i<longitudListaDos; i++)
    	{
    		if(ll_contains(this, ll_get(this2, i)) != 1)
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from > -1 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(int i=from; i<to; i++)
    		{
    			ll_add(cloneArray, ll_get(this, i));
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;
    
    int longitud;
    int longitudMenosUno;
    int criterio;
    
    Node* pNodeUno;
    Node* pNodeDos;
    void* elementAux;

    returnAux = -1;
    criterio = -1;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	longitud = ll_len(this);
    	longitudMenosUno = longitud - 1;
    	
    	if(order == 1)
    	{
    		criterio = 1;
    	}

    	pNodeUno = this->pFirstNode;

    	for(int i=0; i<longitudMenosUno; i++)
    	{
    		pNodeDos = pNodeUno;

    		for(int j=i+1; j<longitud; j++)
    		{
    			pNodeDos = pNodeDos->pNextNode;

				if(pFunc(pNodeUno->pElement, pNodeDos->pElement) == criterio)
				{
					elementAux = pNodeUno->pElement;
					pNodeUno->pElement = pNodeDos->pElement;
					pNodeDos->pElement = elementAux;
				}
    		}

    		pNodeUno = pNodeUno->pNextNode;
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Crea una nueva linked list vacia. Itera por cada elemento de la linked list
 * 			recibida por parametro y los añade a la nueva linked list segun la funcion criterio
 *
 * \param this LinkedList* Puntero a la lista
 * \param fn (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna  (NULL) Error: si algun puntero es NULL
 *                              (puntero a nueva linked list) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* listaFiltrada = NULL;
	Node* auxParaIterarLista = NULL;
	int longitud;

	if(this != NULL && fn != NULL)
	{
		listaFiltrada = ll_newLinkedList();

		if(listaFiltrada != NULL)
		{
			auxParaIterarLista = this->pFirstNode;
			longitud = ll_len(this);

			for(int i=0; i<longitud; i++)
			{
				if(fn(auxParaIterarLista->pElement) == 1)
				{
					ll_add(listaFiltrada, auxParaIterarLista->pElement);
				}
				auxParaIterarLista = auxParaIterarLista->pNextNode;
			}
		}
	}

	return listaFiltrada;
}


/** \brief Devuelve un contador obtenido al iterar por todos los elementos de una lista
 * 			e incrementar el contador segun la funcion criterio recibida por parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param fn (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si algun puntero es NULL
 *                      (contador) Si ok
 */
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int contador;
	int longitud;
	Node* nodoIterarLista = NULL;
	contador = -1;

	if(this != NULL && fn != NULL)
	{
		contador = 0;
		longitud = ll_len(this);

		nodoIterarLista = this->pFirstNode;
		for(int i=0; i<longitud; i++)
		{
			contador += fn(nodoIterarLista->pElement);

			nodoIterarLista = nodoIterarLista->pNextNode;
		}
	}

	return contador;
}

//Aca hay unas pruebas que hice, pero no implemente

/* Hice un insertion sort,
 * pero al probarla es mas lenta que el burbujeo
 * porque llama demasiado a la funcion getNode()
 * y es necesario recorrer hacia atras la LinkedList,
 * asi que no pude evitar usar getNode()
 * pero lo deje aca por las dudas
 *
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;

    int longitud;
    int criterio;
    int j;

    void* key;
    Node* pNodeUno;
    Node* pNodeDos;
	Node* pNodeTres;
	Node* pNodeCuatro;

    returnAux = -1;
    criterio = -1;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	longitud = ll_len(this);

    	if(order == 1)
    	{
    		criterio = 1;
    	}

		pNodeUno = this->pFirstNode;
		pNodeCuatro = pNodeUno;

		for (int i = 1; i < longitud; i++)
		{
			pNodeUno = pNodeUno->pNextNode;

			key = pNodeUno->pElement;
			j = i - 1;

			pNodeDos = pNodeCuatro;

			while (j >= 0 && pFunc(pNodeDos->pElement, key) == criterio)
			{
				pNodeTres = pNodeDos->pNextNode;

				pNodeTres->pElement = pNodeDos->pElement;

				j -= 1;

				pNodeDos = getNode(this, j);
			}

			pNodeDos = getNode(this, j+1);

			pNodeDos->pElement = key;

			pNodeCuatro = pNodeCuatro->pNextNode;
		}

    	returnAux = 0;
    }

    return returnAux;
}*/

/* Sort pero con un vector auxiliar e insertion sort
 * permitiendo que solamente se recorra la LinkedList una vez al cargar el vector
 * y aprovechandolo para acelerar el sort
 *
 * Tardo 8 segundos en ordenar una LinkedList del TP_3 con 30.000 Employees segun Salario y Nombre
 * en vez de los 35 segundos del burbujeo, pero como usa un vector y no LinkedList no lo use en el TP
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int seOrdeno;
	int j;
	int longitud;
	int criterio;

    void* key = NULL;
    Node* pNodeAux = NULL;
    Node** vectorNodos = NULL;

	seOrdeno = -1;
	criterio = -1;

	if(this != NULL && pFunc != NULL && (order==1 || order==0))
	{
		longitud = ll_len(this);

    	if(order == 1)
    	{
    		criterio = 1;
    	}

		vectorNodos = (Node**)malloc(sizeof(Node*)*longitud);

		if(vectorNodos!= NULL)
		{
			pNodeAux = this->pFirstNode;

			for(int i=0; i<longitud; i++)
			{
				*(vectorNodos+i) = pNodeAux;
				pNodeAux = pNodeAux->pNextNode;
			}

			for(int i=1; i<longitud; i++)
			{
				key = (*(vectorNodos+i))->pElement;
				j = i - 1;

				while(j > -1 && pFunc((*(vectorNodos+j))->pElement, key) == criterio)
				{
					(*(vectorNodos+j+1))->pElement = (*(vectorNodos+j))->pElement;
					j = j - 1;
				}

				(*(vectorNodos+j+1))->pElement = key;
			}

			free(vectorNodos);
			seOrdeno = 0;
		}
	}

	return seOrdeno;
}
*/

