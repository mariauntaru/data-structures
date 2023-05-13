#include "heap.h"
/**
 * TODO: Implementati functia de creare MinHeap avand o capacitate data
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
MinHeap *create(int capacitate)
{
	MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
	if (h == NULL)
	{
		printf("Eroare alocare");
		return NULL;
	}
	h->capacity = capacitate;
	h->size = 0;
	h->poz = (int *)malloc(sizeof(int) * capacitate);
	if (h->poz == NULL)
	{
		printf("Eroare alocare");
		return NULL;
	}
	for (int i = 0; i < capacitate; i++)
		h->poz[i] = -1;
	h->arr = (HeapNode **)malloc(sizeof(HeapNode *) * capacitate);
	if (h->poz == NULL)
	{
		printf("Eroare alocare");
		return NULL;
	}
	for (int i = 0; i < capacitate; i++)
		h->arr[i] = NULL;
	return h;
}

/**
 * TODO: Implementati functia de creare HeapNode 
 * @param  v:  varful care trebuie adaugat
 * @param dist: distanta rezultata in urma implementarii algoritmului Dijkstra
 * @retval - HeapNode-ul creat
 */
HeapNode *createHeapNode(int v, int dist)
{
	HeapNode *h = (HeapNode *)malloc(sizeof(HeapNode));
	h->distanta = dist;
	h->v = v;
	return h;
}

/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din MinHeap
 * @param  heap: MinHeap-ul
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */

int parent(MinHeap *heap, int i)
{
	if (i > heap->size - 1 || i <= 0)
		return -1;
	return (i - 1) / 2;
}
/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */

int leftChild(MinHeap *heap, int i)
{
	int poz = 2 * i + 1;
	if (poz > heap->size - 1 || i < 0)
		return -1;
	return poz;
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(MinHeap *heap, int i)
{
	int poz = 2 * i + 2;
	if (i < 0 || poz > heap->size - 1)
		return -1;
	return poz;
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap   
 * @param  heap: MinHeap-ul
 * @retval - HeapNode-ul in care este stocata radacina
 */
HeapNode *returnRoot(MinHeap *heap)
{
	return heap->arr[0];
}

/**
 * TODO: Implementati functia heapify
 * @param  heap: MinHeap-ul
 * @param  i: pozitia de pe care se doreste
 * @retval None
 */
void heapify(MinHeap *heap, int i)
{
	int aux;
	while (i > 0 && heap->arr[i] < heap->arr[(i - 1) / 2])
	{
		aux = heap->arr[(i - 1) / 2];
		heap->arr[(i - 1) / 2] = heap->arr[i];
		heap->arr[i] = aux;
		i = (i - 1) / 2;
	}
}
/**
 * TODO: Implementati functia de redimensionare a MinHeap-ului  
 * @param  heap: MinHeap-ul
 * @retval None
 */
void resize(MinHeap *heap)
{
	int *v = (int *)realloc(heap->poz, heap->capacity *= 2);
	if (v == NULL)
	{
		printf("Eroare memorie");
		return;
	}
	if (heap->poz != NULL)
		free(heap->poz);
	heap->poz = v;
	HeapNode **x = (HeapNode **)realloc(heap->arr, heap->capacity *= 2);
	if (x == NULL)
	{
		printf("Eroare memorie");
		return;
	}
	if (heap->arr != NULL)
	{
		for (int i = 0; i < heap->size; i++)

			free(heap->arr[i]);
		free(heap->arr);
	}
	heap->arr = x;
}
/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  heap: MinHeap-ul
 * @param  x: HeapNode-ul care urmeaza a fi inserat
 * @retval None
 */

void insert(MinHeap *heap, HeapNode *x)
{
	int i;
	if (heap->size == heap->capacity)
		resize(heap);
	i = heap->size;
	heap->size++;
	while (i > 0 && x > heap->arr[(i - 1) / 2])
	{
		heap->arr[i] = heap->arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	heap->arr[i] = x;
}

/**
 * TODO: Implementati functia stergere a unui heap
 * @param  h: MinHeap-ul
 * @retval None
 */
void deleteMinHeap(MinHeap **heap)
{
	if (*heap == NULL)
		return;
	if ((*heap)->poz != NULL)
		free((*heap)->poz);
	if ((*heap)->arr != NULL)
	{
	for (int i = 0; i < (*heap)->size; i++)
			free((*heap)->arr[i]);
		free((*heap)->arr);
	}
	free(*heap);
	*heap = NULL;
}
/**
 * TODO: Implementati functia de afisare a unui heap
 * @param  heap: MinHeap-ul
 * @note : se va afisa si pozitia HeapNode-urilor, pe langa componentele HeapNode-ului
 * @retval None
 */
void printHeap(MinHeap *heap)
{
	//nice to have
}
/**
 * TODO: Implementati functia de stergere a radacinii
 * @param  heap: MinHeap-ul
 * @retval HeapNode-ul care s-a sters, fosta radacina
 */
HeapNode *deleteNode(MinHeap *heap)
{
	HeapNode *i=heap->arr[0];
	for (int j = heap->arr[0]; j < heap->size - 1; j++)
    {
        heap->arr[j] = heap->arr[j + 1];
    }
    heap->size--;
}
