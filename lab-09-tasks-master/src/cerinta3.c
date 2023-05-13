#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati algoritmul Floyd-Warshall pentru un graf cu matricea de adiacenta data
 * @param  g: graful dat
 * @retval - Matricea costurilor pentru toate nodurile
 */
int **Floyd_Warshall(Graph *g)
{
    int **matrix = (int **)malloc(g->V * sizeof(int *)), i, j, k;
    for (i = 0; i < g->V; i++)
        matrix[i] = (int *)malloc(g->V * sizeof(int));
    for (i = 0; i < g->V; i++)
        for (j = 0; j < g->V; j++)
        {
            matrix[i][j] = g->mat[i][j];
            if (g->mat[i][j] == 0)
                matrix[i][j] = INF_MAX;
        }
    for (k = 0; k < g->V; k++)
    {
        for (i = 0; i < g->V; i++)
        {
            for (j = 0; j < g->V; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    return matrix;
}