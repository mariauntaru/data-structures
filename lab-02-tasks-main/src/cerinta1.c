#include "merge.h"
#include "quick.h"
#include "utils.h"

//----- MergeSort -----

/**
 * // Implementarea metodei "merge" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param middle - pozitia din mijloc
 * @param right - pozitia finala
 */
void merge(int *arr, int left, int middle, int right)
{   //Interclasarea a 2 vectori ordonati
    int temp[right - left + 1];//Dam vectorului temporar dimensiunea vectorului initial
	int i = left, j = middle+1, k = 0;

	while(i <= middle && j <= right) 
        {
		if(arr[j] > arr[i]) 
        {
    //Comparam valorile din vectorii injumatatiti deja sortati, trecand valoarea mai mica in vectorul temporar 
			temp[k] = arr[i];
			k ++;//Creste dimensiunea pozitiilor ocupate din vectorul temporar
            i ++;//Trecem la urmatorul element in vectorul din care am extras valoarea cea mai mica
		}

		else//La fel ca mai sus, in cazul in care valoarea cea mai mica se afla pe pozitia j in a doua jumatate
        {
			temp[k] = arr[j];
			k ++,j ++;
		}
	}

	while(i <= middle) {
		temp[k] = arr[i];
		k ++,i ++;
	} 

	while(j <= right) {
		temp[k] = arr[j];
		k ++,j ++;
	}//Completarea cu valorile ramase in vector, in cazul in care nu s-au transmis toate valorile la pasul anterior
	
    for(i = left; i <= right; i ++) 
		arr[i] = temp[i - left];

    }

/**
 * // Implementarea metodei "mergesort" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param right - pozitia finala
 */
void mergesort(int *arr, int left, int right)
{
	if(right > left) {
		int middle = (left + right) / 2;
		mergesort(arr, left, middle);//Apelarea functiei recursive pentru jumatatea din stanga
		mergesort(arr, middle+1, right);//Apelarea functiei recursive pentru jumatatea din dreapta
		merge(arr, left, middle, right);//Interclasarea celor doua
	}

}

//----- Quick Sort -----

/**
 * // Implementarea metodei de interschimbare a doua elemente
 * @param x - primul element
 * @param y - al doilea element
 */
void swap(int *x, int *y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

/**
 * // Implementarea metodei de partitionare din cadrul algoritmului Quick Sort
 * Consideram pivotul a fi ultimul element din vector
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
int partition(int *arr, int low, int high)
{
    int p_index,j,pivot;
    pivot = arr[high];//Consideram pivotul ultimul element din vector
    p_index = (low - 1);//Salvam pozitia pivotului

    for (j = low; j <= high-1; j++)//Parcurgem vectorul initial
    {

        if (arr[j] < pivot)
        {
            p_index++;
            swap(arr+j, arr+p_index);
        }

    }//Pasul acesta interschimba valorile intre ele, pentru a afla pozitia pivotului
    swap(arr+high, arr +p_index + 1);//Punem pivotul pe pozitia corespunzatoare
    
    return (p_index + 1);
}

/**
 * // Implementarea metodei "quicksort" din cadrul algoritmului Quick Sort
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
void quicksort(int *arr, int low, int high)
{
    int p_index;// Pozitia pivotului
    if (low < high)
    {
        p_index = partition(arr, low, high);//Apelarea functiei partition pentru separarea array-ului
        quicksort(arr, low, p_index - 1); //Apelarea recursiva a sortarii rapide pentru jumatatea din stanga 
        quicksort(arr, p_index + 1, high); //Apelarea recursiva a sortarii recursive pentru jumatatea din dreapta
        //Cele doua jumatati nu sunt jumatate propriu-zisa din array, ci valorile mai mici, respectiv mai mari decat pivotul
    }
}

//----- Analiza functiilor -----

/**
 * // Care dintre metodele anterior implementate reprezinta metode de sortare stabile
 * si care reprezinta metode de sortare instabile? Argumentati.
 * Mergesort e mai stabila, deoarece functioneaza bine pe vectori de orice lungime.
 * Quicksort e metoda mai instabila, deoarece, desi e o metoda rapida,
 * fata de Mergesort ce are o viteza consistenta, Quicksort opereaza bine
 * doar pe vectori de lungimi mici, fiind ineficient cand vine vorba de vectori
 * cu lungime mare.
 */