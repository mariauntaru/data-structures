#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat de o matrice de adiacenta 
 * intr-unul reprezentat cu ajutorul listelor de adiacenta
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - Graful in reprezentarea liste de adiacenta
 */
graph_list *matrixToList(graph_matrix *graph)
{
    graph_list *y;
    y = (graph_list *)malloc(sizeof(graph_list));
    if (y == NULL)
    {
        printf("Alocare esuata");
        return NULL;
    }
    y->V = graph->V;
    y->E = graph->E;
    y->listHeads = (node **)malloc(sizeof(node *) * y->V);
    int i, j;
    for (i = 0; i < graph->V; i++)
        y->listHeads[i] = NULL;
    for (i = 0; i < graph->V; i++)
    {
        node *z = NULL;
        for (j = 0; j < graph->V; j++)
            if (graph->matrix[i][j] != 0)
            {
                if (y->listHeads[i] == NULL)
                {
                    y->listHeads[i] = (node *)malloc(sizeof(node));
                    y->listHeads[i]->vertexNr = j;
                    y->listHeads[i]->next = NULL;
                    z = y->listHeads[i];
                }
                else
                {
                    node *x = NULL;
                    x = (node *)malloc(sizeof(node));
                    x->vertexNr = j;
                    x->next = NULL;
                    z->next = x;
                    z = z->next;
                }
            }
    }
    free_graph_matrix(&graph);
    return y;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_matrix(graph_matrix **graph)
{
    int i;
    if (*graph == NULL)
        return;
    for (i = 0; i < (*graph)->V; i++)
        free((*graph)->matrix[i]);
    free((*graph)->matrix);
    (*graph)->matrix = NULL;
    (*graph)->V = 0;
    (*graph)->E = 0;
    free(*graph);
    (*graph) = NULL;
}

node *push_values(node *root, int val)
{
    // nice to have; functie de adauga o valoare intr-o lista
}

void print_graph_list(graph_list *graph)
{
    // nice to have; functie care afiseaza continutul unui graf reprezentat prin liste de adiacenta
}
