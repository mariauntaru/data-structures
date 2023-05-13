#include "utils.h"

/**
 * TODO: Implementati o functie de cautare a unui nod in
 * 	functie de valoarea din acesta
 * @note   
 * @param  root: Radacina arborelui
 * @param  data: Valoarea de cautat
 * @retval Nodul cautat, daca nu este gasit se returneaza NULL
 */
BST *findNode(BST *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data == root->data)
        return root;
    else if (data < root->data)
        return findNode(root->left, data);
    else if (data > root->data)
        return findNode(root->right, data);
}
/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea maxima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea maxima din arbore/subarbore
 */
BST *findMax(BST *root)
{
    if (root->right != NULL)
        return findMax(root->right);
    return root;
}

/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea minima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea minima din arbore/subarbore
 */
BST *findMin(BST *root)
{
    if (root->left != NULL)
        return findMin(root->left);
    return root;
}

/**
 * TODO: Implementati o functie ce returneaza succesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui succesor trebuie gasit
 * @retval Succesorul nodului root
 */
BST *findSuccesor(BST *root)
{
    int copy = root->data;
    if (root->right != NULL)
        return findMin(root->right);
    else
    {
        while (root->parent != NULL)
        {
            if (copy < root->parent->data)
                return root->parent;
            else
                root = root->parent;
        }
    }
    return NULL;
}

/**
 * TODO: Implementati o functie ce returneaza predecesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui predecesor trebuie gasit
 * @retval Predecesorul nodului root
 */
BST *findPredecessor(BST *root)
{
    int copy = root->data;
    if (root->left != NULL)
        return findMax(root->left);
    else
        while (root->parent != NULL)
        {
            if (copy > root->parent->data)
                return root->parent;
            else
                root = root->parent;
        }
    return NULL;
}
