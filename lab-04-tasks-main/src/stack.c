#include "utils.h"
#include "stack.h"
#include "stack_node.h"

/**
 * @brief Functie ce aloca dinamic memorie pentru stiva,
 *        initializand campurile head si size
 * 
 * @param stack - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru stiva
 */

void createStack(Stack **stack)
{
    //1.1: functie ce aloca memorie pentru o stiva noua
    *stack = (Stack *)malloc(sizeof(Stack));
    if (*stack == NULL)
        return;
    (*stack)->head = NULL;
    (*stack)->size = 0;
}

/**
 * @brief Functie ce dealoca memoria pentru stiva
 * 
 * @param stack - stiva a carei elemente trebuie sterse
 */
void deleteStack(Stack *stack)
{
    stack_node *c;
    if (stack->head == NULL)
    {
        free(stack);
        return;
    }
    else
    {
        while (stack->head != NULL)
        {
            c = stack->head;
            stack->head = stack->head->next;
            free(c);
            stack->size--;
        }
    }
    free(stack);
    // Nice to have
}

/**
 * @brief Functie ce adauga un nou nod in stiva
 * 
 *  * Hint:
 *          * a se citi cursul :)
 *          * se va modifica pointer-ul head al structurii Stack
 * 
 * @param stack - stiva in care se va adauga un nou nod
 * @param data - informatiile noului nod
 */
void push(Stack *stack, char data)
{
    //1.3: functie ce adauga un nou nod in stiva
    stack_node *a;
    a = createStackNode(data);
    a->next = stack->head;
    stack->head = a;
    stack->size++;
}

/**
 * @brief Functie ce elimina urmatorul nod din stiva
 * 
 *  * Hint:
 *          * a se citi cursul :)
 *          * se va modifica pointer-ul head al structurii Stack
 * 
 * @param stack - stiva din care se va elimina nodul
 * @param data - informatiile noului scos
 */
char pop(Stack *stack)
{
    stack_node *c;
    char cpy;
    //1.4: functie ce elimina urmatorul nod din stiva
    if (stack->head == NULL)
        return 0;
    else
    {
        c = stack->head;
        cpy = stack->head->data;
        stack->head = stack->head->next;
        free(c);
        stack->size--;
    }
    return cpy;
}

/**
 * @brief Functie ce testeaza dimensiune stivei pentru a vedea daca este goala
 * 
 * @param stack - stiva ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyStack(Stack *stack)
{
    //1.5: Needed by the tests
    return stack->head == NULL;
}
