#include "stack_node.h"

/**
 * @brief Functie ce creaza un nod pentru stiva
 * 
 * 
 * @param data - informatiile noului nod
 * @return stack_node* - pointer-ul noului 
 */
stack_node *createStackNode(char data)
{
    // 1.2: functie ce atribuie campului data parametru primit
    stack_node *nou = (stack_node *)malloc(sizeof(stack_node));
    nou->data = data;
    nou->next = NULL;
    return nou;
}