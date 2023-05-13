#include <stdio.h>
#include <stdlib.h>
int N;
struct object
{
    float value;
    float weight;
};
typedef struct object obj;
typedef struct backpack
{
    struct backpack *left, *right, *parent;
    obj *o;
    float p;
    float w_max;
} backpack;
void merge(obj **o, int left, int middle, int right)
{
    obj *temp[right - left + 1];
    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right)
    {
        if (o[j]->value / o[j]->weight < o[i]->value / o[i]->weight)
        {
            temp[k] = o[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = o[j];
            k++, j++;
        }
    }
    while (i <= middle)
    {
        temp[k] = o[i];
        k++, i++;
    }

    while (j <= right)
    {
        temp[k] = o[j];
        k++, j++;
    }
    for (i = left; i <= right; i++)
        o[i] = temp[i - left];
}
void mergesort(obj **o, int left, int right)
{
    if (right > left)
    {
        int middle = (left + right) / 2;
        mergesort(o, left, middle);
        mergesort(o, middle + 1, right);
        merge(o, left, middle, right);
    }
}
void backtracking(backpack *b, obj **o)
{
    static int i = 0;
    while (i < N  && o[i]->weight > b->w_max)
        i++;
    if (i == N)
        return;
    b->left = (backpack *)malloc(sizeof(backpack));
    if (b->left == NULL)
    {
        printf("Alocare esuata");
        return;
    }
    b->left->o = o[i];
    b->left->left = NULL;
    b->left->right = NULL;
    b->left->parent = b;
    b->left->w_max = b->w_max - o[i]->weight;
    b->left->p = b->p + o[i]->value;
    b->right = (backpack *)malloc(sizeof(backpack));
    if (b->right == NULL)
    {
        printf("Alocare esuata");
        return;
    }
    b->right->o = b->o;
    b->right->left = b->right->right = NULL;
    b->right->parent = b;
    b->right->w_max = b->w_max;
    b->right->p = b->p;
    i++;
    backtracking(b->left, o);
    backtracking(b->right, o);
}
void p_max(backpack *b, float *max)
{
    if (b == NULL)
        return;
    if (b->left == NULL && b->right == NULL && b->p > (*max))
        (*max) = b->p;
    p_max(b->left, max);
    p_max(b->right, max);
}
void sol(backpack *b, float p_max, FILE *f)
{
    if (b == NULL)
        return;
    if (b->p == p_max)
    {
        backpack *c = b;
        for (c = b; c->o != NULL; c = c->parent)
        {
            while (c->o == c->parent->o)
                c = c->parent;
            fprintf(f, "%f %f\n", c->o->value, c->o->weight);
        }
        fprintf(f, "\n");
    }
    sol(b->left, p_max, f);
    sol(b->right, p_max, f);
}
int main()
{
    FILE *f = NULL;
    int c;
    printf("Pentru deschiderea fisierului 1 apasati 1; pentru fisierul 2 tasta 2:\n");
    scanf("%d", &c);
    if (c == 1)
    {
        f = fopen("input1.txt", "rt");
        if (f == NULL)
        {
            printf("Deschidere nereusita");
            exit(1);
        }
    }
    else if (c == 2)
    {
        f = fopen("input2.txt", "rt");
        if (f == NULL)
        {
            printf("Deschidere nereusita");
            exit(1);
        }
    }
    else
        exit(1);
    fscanf(f, "%d", &N);
    obj **o;
    o = (obj **)malloc(sizeof(obj *) * (N + 1));
    if (o == NULL)
    {
        printf("Alocare nereusita");
        exit(1);
    }
    int i;
    for (i = 0; i < N; i++)
    {
        o[i] = (obj *)malloc(sizeof(obj));
        fscanf(f, "%f %f", &o[i]->value, &o[i]->weight);
    }
    mergesort(o, 0, N - 1);

    backpack *b = (backpack *)malloc(sizeof(backpack));
    if (b == NULL)
    {
        printf("Alocare nereusita");
        exit(1);
    }
    b->o = NULL;
    b->left = b->parent = b->right = NULL;
    b->p = 0;
    fscanf(f, "%f", &b->w_max);
    backpack *d = b;
    backtracking(d, o);
    d = b;
    fclose(f);
    f = fopen("output.txt", "wt");
    if (f == NULL)
    {
        printf("Deschidere nereusita");
        exit(1);
    }
    float max = 0;
    p_max(d, &max);
    sol(b, max, f);
}