#include <stdio.h>
#include <stdlib.h>
struct object
{
    float value;
    float weight;
};
typedef struct object obj;
typedef struct backpack
{
    obj **o;
    float w_max;
    int N;
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
    backpack *b = (backpack *)malloc(sizeof(backpack));
    if (b == NULL)
    {
        printf("Alocare nereusita");
        exit(1);
    }
    fscanf(f, "%d", &b->N);
    fscanf(f, "%f", &b->w_max);
    b->o = (obj **)malloc(sizeof(obj *) * (b->N + 1));
    if (b->o == NULL)
    {
        printf("Alocare nereusita");
        exit(1);
    }
    for (int i = 0; i < b->N; i++)
    {
        b->o[i] = (obj *)malloc(sizeof(obj));
        fscanf(f, "%f %f", &b->o[i]->value, &b->o[i]->weight);
    }
    mergesort(b->o, 0, b->N - 1);
    fclose(f);
    f = fopen("output.txt", "wt");
    if (f == NULL)
    {
        printf("Deschidere nereusita");
        exit(1);
    }
    for (int i = 0; i < b->N; i++)
    {
        if (b->o[i]->weight <= b->w_max)
        {
            fprintf(f, "%.2f %.2f\n", b->o[i]->value, b->o[i]->weight);
            b->w_max = b->w_max - b->o[i]->weight;
        }
        else if (b->w_max < b->o[i]->weight)
        {
            fprintf(f, "%.2f %.2f\n", (b->o[i]->value / b->o[i]->weight) * b->w_max, b->w_max);
            b->w_max = 0;
            exit(1);
        }
        else
            return 0;
    }
    for (int i = 0; i < b->N; i++)
        free(b->o[i]);
    free(b->o);
    free(b);
    b=NULL;
}