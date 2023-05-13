#include "heap.h"

/**
 * TODO: Returnati un vector ce contine cele mai mari k elemente din vector.
 * HINT: Nu trebuie sa sortati tot vectorul, se poate utiliza un heap de
 * dimensiune mai mica. Pentru sortarea intregului vector se pot aplica penalizari
 * @param  *buffer: vectorul initial
 * @param  dimensiune: dimensiunea vectorului
 * @param  k: numarul de elemente returnate
 * @retval - vectorul cu cele mai mari k elemente din buffer
 *  Metoda I</b>: Folositi un min heap de dimensiune k pentru a stoca primele k elemente 
 * din vectorul primit ca parametru, apoi parcurgeti restul elementelor din vector. Daca
 * elementul curent este mai mare decat varful heap-ului adaugati 
 * elementul in heap in locul varfului.
 */
int *kMaxElem(int *buffer, int dimensiune, int k)
{
    int i;
    Heap *v;
    v = create(k);
    populateHeap(v,buffer,k);
    for (i = 0; i <= dimensiune - 1; i++)
    {
        if (v->vec[0] < buffer[i])
            {
                v->vec[0] = buffer[i];
                heapify(v,0);
            }
    }
    heapsort(v, v->vec, k);
    return v->vec;
}
