#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *arr, size, n;
};

void creat(struct Matrix *mat, int dim)
{
    mat->n = 5;
    mat->size = mat->n * (mat->n-1) / 2;
    mat->arr = (int *)malloc(mat->size * sizeof(int));
}

void set(struct Matrix *mat, int m, int n, int x)
{
    if(m>=n)
        mat->arr[ ((m * (m+1)) / 2) + n] = x;
}

int get(struct Matrix mat, int m, int n)
{
    if(m>=n)
        return mat.arr[ ((m * (m+1)) / 2) + n];
    return 0;
}

void display(struct Matrix mat)
{
    int i, j;
    printf("Your matrix is : \n");
    for(i=0; i<mat.n; i++)
    {
        for(j=0; j<mat.n; j++)
        {
            if(i>=j)
                printf("%d\t", get(mat, i, j));
            else
                printf("%d\t", get(mat, j, i));
        }
        printf("\n");
    }
}

int main()
{
    int a[5][5]={{2, 2, 2, 2, 2},
                        {2, 3, 3, 3, 3},
                        {2, 3, 4, 4, 4},
                        {2, 3, 4, 5, 5},
                        {2, 3, 4, 5, 6}};

    struct Matrix mat;
    creat(&mat, 5);

    int i, j;
    for(i=0; i<mat.n; i++)
    {
        for(j=0; j<mat.n; j++)
            set(&mat, i, j, a[i][j]);
    }
    display(mat);
}
