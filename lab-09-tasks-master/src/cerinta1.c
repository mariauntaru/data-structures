#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati o functie care citeste dintr-un fisier de intrare
 * nr-ul de varfuri, muchii, iar pe urmatoarele linii
 * nod u, nod v si distanta[u][v], pentru a putea reprezenta ulterior matricea de adiacenta
 * @param  input: fisierul de intrare
 * @note   -Atentie! Nu redeschideti fisierul de intrare
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
Graph *createGraph(FILE *input)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
    {
        printf("Eroare alocare");
        return NULL;
    }
    fscanf(input, "%d %d", &(g->V), &(g->E));
    int i, j;
    g->mat = (int **)malloc(g->V * sizeof(int *));
    for (i = 0; i < g->V; i++)
        g->mat[i] = (int *)calloc(g->V , sizeof(int));
    if (g->mat == NULL)
    {
        printf("Eroare alocare");
        return NULL;
    }
    while (!feof(input))
    {
        fscanf(input, "%d %d", &i, &j);
        fscanf(input, "%d", &(g->mat[i][j]));
        g->mat[j][i] = g->mat[i][j];
    }
    return g;
}
/**
 * TODO: Implementati functia de afisare a matricei de adiacenta
 * @param  g: graful creat anterior
 * @note : Nice to have
 * @retval - None
 */
void printMat(Graph *g)
{
    int i, j;
    for (i = 0; i < g->V; i++)
    {
        for (j = 0; j < g->V; j++)
            printf("%d ", g->mat[i][j]);
        printf("\n");
    }
}