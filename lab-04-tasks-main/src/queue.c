#include "utils.h"
#include "queue.h"
#include "queue_node.h"

/**
 * @brief Functie ce aloca dinamic memorie pentru coada,
 *        initializand campurile front si rear
 * 
 * @param queue - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru coada
 */
void createQueue(Queue **queue)
{
    //2.1: Functia va fi folosita pentru a initializa structura Queue
    *queue = (Queue *)malloc(sizeof(Queue));
    if (*queue == NULL)
        return;
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
}

/**
 * @brief Functie ce va fi folosita pentru a adauga un nod in coada queue
 * 
 * * Hint:
 *         * se va folosi functia createQueueNode pentru crearea unui nou nod
 *         * trebuie actualizati poniterii rear si front sau doar front
 *         * a se citi cursul :)
 * 
 * @param queue - coada in care trebuie adaugat un nou nod cu informatia data
 * @param data - datele noului nod
 */
void en(Queue *queue, char *data)
{
    //2.3: adauga un nou nod in coada, noul nod are informatia data
    queue_node *q;
    q = createQueueNode(data);
    if (queue->front == NULL)
        queue->front = q;
    if (queue->rear == NULL)
        queue->rear = q;
    else
    {
        queue->rear->next = q;
        queue->rear = queue->rear->next;
    }
}

/**
 * @brief Functie ce scoate din coada urmatorul nod si
 *        returneaza datele stocate in nod.
 * * Hint:
 *        * a se citi cursul :)
 * 
 * @param queue - coada din care va fi scos nodul 
 * @return char* - datele din interiorul nodului
 */
char *de(Queue *queue)
{
    //2.4: scoate urmatorul nod din coada si returneaza informatia acestuia
    queue_node *q;
    char *cpy;
    if (queue == NULL)
        return 0;
    else
    {
        q = queue->front;
        cpy = queue->front->data;
        queue->front = queue->front->next;
        free(q);
    }
    return cpy;
}

/**
 * @brief Functie ce va elibera memoria asociata fiecarui nod al cozi
 *  
 *  * Hint:
 *          * se poate folosi functia deleteQueueNode
 * @param queue - coada a carui noduri vor fi sterse
 */
void deleteQueue(Queue *queue)
{
    // Nice to have
}

/**
 * @brief Functie ce testeaza pointerii rear si front pentru 
 *        a determina daca coada este goala
 * 
 * @param queue - coada ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyQueue(Queue *queue)
{
    //2.5: Needed by the tests
    return queue->front == NULL;
}
