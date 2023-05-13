#include "utils.h"

/**
 * TODO:   Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */
int **findPaths(graph_matrix *graph)
{

    int **a = (int **)malloc(graph->V * sizeof(int *)), i, j, k;
    for (i = 0; i < graph->V; i++)
        a[i] = (int *)malloc(graph->V * sizeof(int));
    for (i = 0; i < graph->V; i++)
        for (j = 0; j < graph->V; j++)
            a[i][j] = graph->matrix[i][j];
    for ( k = 0; k < graph->V; k++)
        for ( i = 0; i < graph->V; i++)
            for ( j = 0; j < graph->V; j++)
                if (i != j && a[i][j] == 0 && a[i][k] == 1 && a[k][j] == 1)
                    a[i][j] = 1;
    return a;
}