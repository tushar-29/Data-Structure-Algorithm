#include<stdio.h>
#include<stdlib.h>

struct Matrix 
{
    int *arr, size, n;
};

void creat(struct Matrix *mat, int dim)
{
    mat->n = dim;
    mat->size = 2 * (mat->n) -1;
    mat->arr = (int *)malloc(mat->size * sizeof(int));
}

void set(struct Matrix *mat, int m, int n, int x)
{
    if(m == 0)
        mat->arr[n] = x;
    else if (n == 0 && m != 0)
        mat->arr[mat->n + m - 1] = x;    
}

int get(struct Matrix mat, int m, int n)
{
    if(m <= n)
        return mat.arr[n - m];
    return mat.arr[mat.n + m - n - 1];
}

void display(struct Matrix mat)
{
    int i, j;
    printf("your array is : \n");
    for(i=0; i<mat.n; i++)
    {
        for(j=0; j<mat.n; j++)
            printf("%d\t", get(mat, i, j));
        printf("\n");
    }
}

int main()
{
    int a[5][5]={{2, 3, 4, 5, 6},
                        {7, 2, 3, 4, 5},
                        {8, 7, 2, 3, 4},
                        {9, 8, 7, 2, 3},
                        {10, 9, 8, 7, 2}};

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
