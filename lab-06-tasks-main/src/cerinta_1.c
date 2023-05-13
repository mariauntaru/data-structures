#include "utils.h"

/**
 * TODO: Implementati o functie ce creaza un arbore balansat din datele
 * 	din fisierul f. Arborele nu trebuie sa respecte alta proprietate decat
 *  cea mentionala anterior 
 * @note   
 * @param  N: Numarul de noduri ale arborelui
 * @param  *f: Fisierul din care sunt citite datele de intrare 
 * @retval	Nodul radacina al arborelui creat 
 */
BST *createBalanced(int N, FILE *f)
{
    int x;
    BST *node;
    if (N != 0)
    {
        fscanf(f, "%d", &x);
        node = createBSTNode(x);
        node->left = createBalanced(N / 2, f);
        if (node->left != NULL)
            node->left->parent = node;

        node->right = createBalanced(N - 1 - N / 2, f);
        if (node->right != NULL)
            node->right->parent = node;
        return node;
    }
    return NULL;
}

/**
 * TODO:   Implementati o functie ce testeaza daca un arbore binar este
 * 	un arbore binar de cautare.
 * @note   
 * @param  root: Radacina arborelui
 * @param  max_value: Valoarea maxima intalnita pana la nodul curent
 * @param  min_value: Valoarea minima intalnita pana la nodul curent
 * @retval - true daca arborele este un BST, false in caz contrar
 */
bool checkBST(BST *root, int max_value, int min_value)
{
    if (root == NULL)
        return 1;
    if (root->data < min_value)
        return 0;
    if (root->data > max_value)
        return 0;
    return checkBST(root->left, root->data, min_value) && checkBST(root->right, max_value, root->data);
}

/**
 * TODO:  Implementati o functie ce aloca memorie pentru un nod 
 * 	si salveaza datele in acesta
 * @note   
 * @param  data: Datele ce trebuie stocate in nod
 * @retval Nodul creat
 */

BST *createBSTNode(int data)
{
    BST *node;
    node = (BST *)malloc(sizeof(BST));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    return node;
}
/**
 * TODO: Implementati o functie ce insereaza un nod nou intr-un BST cu
 * 	pastrarea proprietatiilor acestui tip de arbore binar
 * @note   
 * @param  root: Nodul radacina
 * @param  data: Valoarea ce trebuie inserata in arbore
 * @retval Radacina arborelui modificat anterior
 */
BST *insertInBST(BST *root, int data)
{
    if (root == NULL)
        return createBSTNode(data);
    if (root->data > data)
    {
        root->left = insertInBST(root->left, data);
        if (root->left != NULL)
            root->left->parent = root;
    }
    else if (root->data < data)
    {
        root->right = insertInBST(root->right, data);
        if (root->right != NULL)
            root->right->parent = root;
    }

    return root;
}