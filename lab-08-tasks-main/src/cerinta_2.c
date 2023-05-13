#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
graph_matrix *listToMatrix(graph_list *graph)
{
    graph_matrix *x = NULL;
    int i;
    x = (graph_matrix *)malloc(sizeof(graph_matrix));
    x->E = graph->E;
    x->V = graph->V;
    x->matrix = (int **)malloc(x->V * sizeof(int *));
    for (i = 0; i < x->V; i++)
        x->matrix[i] = (int *)calloc(x->V, sizeof(int));
    for (i = 0; i < graph->V; i++)
    {
        node *y = graph->listHeads[i];
        while (y != NULL)
        {
            x->matrix[i][y->vertexNr] = 1;
            y = y->next;
        }
    }
    free_graph_list(&graph);
    return x;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_list(graph_list **graph)
{
    int i;
    for (i = 0; i < (*graph)->V; i++)
    {
        while ((*graph)->listHeads[i])
        {
            node *x = (*graph)->listHeads[i];
            (*graph)->listHeads[i] = (*graph)->listHeads[i]->next;
            free(x);
        }
    }
    free((*graph)->listHeads);
    (*graph)->E = 0;
    (*graph)->V = 0;
    free(*graph);
    (*graph) = NULL;
}

void print_graph_matrix(graph_matrix *graph)
{
    // nice to have; functie de afiseaza continutul unui graf reprezentat prin matrice de adiacenta
}