#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param number - numarul pe care il are copilul
 * @param name - numele copilului
 * @param next  - adresa urmatorului nod
 * @return childNode* - nou nod creat
 */
childNode *makeChildNode(int number, const char *name, childNode *next)
{
    //3.1: primul pas in implementarea cerintei 3
    childNode *nou;
    nou = (childNode *)malloc(sizeof(childNode));
    nou->number = number;
    nou->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(nou->name, name);
    nou->next = next;
    return nou;
}

/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeChildNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return childNode* 
 */
childNode *makeCircularList(FILE *file)
{
    //2.2: al doilea pas in implementarea cerintei 3
    childNode *head, *n, *c;
    int x;
    char y[20];
    fscanf(file, "%d%s", &x, y);
    head = makeChildNode(x, y, NULL);
    c = head;
    while (fscanf(file, "%d%s", &x, y) != EOF)
    {
        n = makeChildNode(x, y, head);
        head = n;
    }
    c->next = head;
    return head;
}

/**
 * @brief Functie ce 
 * 
 * @param head - capul listei ce reprezinta cercul de copii
 * @param p - pasul ce va fi luat pentru eliminarea copiilor
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p)
{
    // 3.3: se va return o lista creata prin adaugarea
    // cu complexitatea O(1) a copiilor in ordinea in care
    // sunt eliminati
    childNode *n, *cap=NULL;
    int i=0;
    do
    {
        i++;
        if(i+1==p)
        {
            cap=makeChildNode(head->next->number,head->next->name,cap);
            n=head->next;
            head->next=head->next->next;
            free(n);
            free(n->name);
            i=0;
            head=head->next;
        }
        else
        {
            head=head->next;
        }
    } while (head->next != head);
    cap=makeChildNode(head->number,head->name,cap);
    free(head);
    free(head->name);
    return cap;
}