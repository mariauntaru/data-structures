#include "heap.h"

/**
 * TODO: Alocati memorie si cititi datele din fisier
 * @param  **v: vectorul cu datele citite
 * @param  dimensiune: dimensiunea vectorului
 * @param  input: fisierul de intrare
 * @retval None
 */
void readVector(int **v, int dimensiune, FILE *input)
{
    int i = 0;
    *v = (int *)malloc(sizeof(int) * dimensiune);
    while (!feof(input))
    {
        fscanf(input, "%d", *v + i);
        i++;
    }
}

/** 
 * TODO:   Stergeti elementul de pe pozitia i din heap
 * @param  *h: heap binar 
 * @param  i: index-ul elementului ce trebuie sters din heap
 * @retval None
 */
void deleteNode(Heap *h, int i)
{
    for (int j = i; j < h->size - 1; j++)
    {
        h->vec[j] = h->vec[j + 1];
    }
    h->size--;
    populateHeap(h, h->vec, h->size);
}
/**
 * TODO: Implementati algoritmul heapsort
 * @param  *h: heap-ul binar ce contine datele vectorului sortat
 * @param  *buf: vectorul ce trebuie sortat
 * @param  dimensiune: dimensiunea vectorului ce trebuie sortat
 * @retval None
 */
void heapsort(Heap *h, int *buf, int dimensiune)
{
    populateHeap(h, buf, dimensiune);
    for (int i = dimensiune - 1; i >= 0; i--)
    {
        int aux = h->vec[0];
        h->vec[0] = h->vec[i];
        h->vec[i] = aux;
        h->size = i;
        heapify(h, 0);
    }
    h->size = dimensiune;
    printHeap(h);
}
