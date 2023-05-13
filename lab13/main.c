#include <stdio.h>
#include <stdlib.h>
typedef struct matr
{
    int N;
    int nr_obj;
    int **m;
} matr;
matr *citire(FILE *f)
{
    matr *m = (matr *)malloc(sizeof(matr));
    if (m == NULL)
    {
        printf("Alocare nereusita");
        return NULL;
    }
    fscanf(f, "%d", &m->N);
    m->nr_obj = 0;
    m->m = (int **)malloc(sizeof(int *) * m->N);
    if (m->m == NULL)
    {
        printf("Alocare nereusita");
        return NULL;
    }
    for (int i = 0; i < m->N; i++)
    {
        m->m[i] = (int *)malloc(sizeof(int) * m->N);
        if (m->m[i] == NULL)
        {
            printf("Alocare nereusita");
            return NULL;
        }
        for (int j = 0; i < m->N; j++)
            fscanf(f, "%d", &m->m[i][j]);
    }
    return m;
}
int **bordare(matr *m)
{
    int **a = (int **)malloc(sizeof(int *) * (m->N + 2));
    if (a == NULL)
    {
        printf("Alocare nereusita");
        return NULL;
    }
    int i, j;
    for (i = 0; i < m->N + 2; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * (m->N + 2));
        if (a[i] == NULL)
        {
            printf("Alocare nereusita");
            return NULL;
        }
    }
    for (i = 0; i < m->N + 2; i++)
    {
        for (j = 0; j < m->N + 2; j++)
        {
            if (i == 0 || j == 0 || i == m->N + 1 || j == m->N + 1)
                a[i][j] = -1;
            else
                a[i][j] = m->m[i - 1][j - 1];
        }
    }
    return a;
}
int sol(int **a, int nr, int i, int j, int N)
{
    if (i == N - 1)
        return nr;
    if (a[i][j] == 0)
    {
        nr++;
        a[i][j] = nr;
    }
    if (a[i][j] > 0)
    {
        if (a[i - 1][j - 1] == 0)
            a[i - 1][j - 1] = a[i][j];
        if (a[i - 1][j] == 0)
            a[i - 1][j] = a[i][j];
        if (a[i - 1][j + 1] == 0)
            a[i - 1][j + 1] = a[i][j];
        if (a[i][j - 1] == 0)
            a[i][j - 1] = a[i][j];
        if (a[i][j + 1] == 0)
            a[i][j + 1] = a[i][j];
        if (a[i + 1][j - 1] == 0)
            a[i + 1][j - 1] = a[i][j];
        if (a[i + 1][j] == 0)
            a[i + 1][j] = a[i][j];
        if (a[i + 1][j + 1] == 0)
            a[i + 1][j + 1] = a[i][j];
    }
    if (j == N - 1)
        sol(a, nr, i + 1, 0, N);
    else
        sol(a, nr, i, j + 1, N);
}
void afisare(int **a, int nr, int N, FILE *f)
{
    fprintf(f, "%d\n", nr);
    int i, j;
    for (i = 1; i < N - 1; i++)
    {
        for (j = 1; j < N - 1; j++)
        {
            fprintf(f, "%d ", a[i][j]);
        }
        fprintf(f, "\n");
    }
}
int main()
{
    FILE *f;
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
    matr *m = citire(f);
    int **a = bordare(m);
    int i, j;
    for (i = 0; i < m->N + 2; i++)
    {
        for (j = 0; j < m->N + 2; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    /*int nr = 0, i = 0, j = 0;
    nr = sol(a, nr, i, j, m->N + 2);
    fclose(f);
    if (c == 1)
    {
        f = fopen("input1.txt", "wt");
        if (f == NULL)
        {
            printf("Deschidere nereusita");
            exit(1);
        }
    }
    else if (c == 2)
    {
        f = fopen("input2.txt", "wt");
        if (f == NULL)
        {
            printf("Deschidere nereusita");
            exit(1);
        }
    }
    else
        exit(1);
    afisare(a, nr, m->N + 2, f);
    fclose(f);*/
    return 0;
}