#include "utils.h"
#include "counting.h"

//----- Counting Sort -----

/**
 * // Implementarea algoritmului counting sort
 * Restrictii: 0 <= arr[i] < 50
 * Dimensiunea vectorului de frecventa va fi 50
 * @param arr - vectorul care trebuie sortat
 * @param dim - dimensiunea vectorului
 * @return vectorul de frecventa utilizat in algoritm
 */
int* countingSort(int *arr, int dim)
{
    int frecventa[50] = {0},i,j,k = 0;
    for (i=0; i<dim; i++)
        frecventa[arr[i]]++;//Numaram aparitiile unei anumite valori, inregistrandu-le in vectorul de frecventa
    for (i=0; i<50; i++)//Parcurgem vectorul de frecventa
        if (frecventa[i] > 0)
            for (j=0; j<frecventa[i]; j++)
            {
                 arr[k] = i;
                 k++;
            }
//Adaugarea in arr a elementelor, in ordine crescatoare, de numarul de iteratii care a fost gasit in vectorul de frecvente
    return frecventa;
}

/**
 * //Care este complexitatea spatiala si cea temporala?
 * O(dim) ambele complexitati
 * De ce nu este mai folosit?
 * Deoarece nu poate fi folosit cu numere negative, pentru ca nu exista indici negativi in arr
 * (i-ul porneste de la 0 si are mereu valori pozitive).
 */