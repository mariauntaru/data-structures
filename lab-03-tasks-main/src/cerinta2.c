#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce elimina elementele cu informatii duplicate
 * Hint:
 *      * parcurgeti lista si modificati nodurile a.i sa elimi-
 *        nati duplicatele
 *      * daca capul listei nu se modifica va trebuii 
 *        sa il returnati
 * 
 * @param list - capul listei ce trebuie sa fie procesata
 * @return node* - returneaza capul listei
 */
node *removeDuplicates(node *list)
{
    //2: metoda ce realizeaza eliminarea de noduri duplicate
    node *head = list, *i, *c, *ci;
    for (i = head; i->next != NULL; i = ci)
    {
        
        if (i->data == i->next->data)
        {
            c = i->next;
            i->next = i->next->next;
            free(c);
            ci = i;
        }
        else
        {
            ci = i->next;
        }
    }
    return head;
}
