#include<stdio.h>
#include<stdlib.h>

struct Matrix 
{
    int *arr, size, n;
};

void creat(struct Matrix *mat, int dim)
{
    mat->n = dim;
    mat->size = mat->n + 2 * (mat->n -1);
    mat->arr = (int *)malloc(mat->size * sizeof(int));
}

void set(struct Matrix *mat, int m, int n, int x)
{
    if(m-n == 1)
        mat->arr[m] = x;
    else if (m-n == 0)
        mat->arr[mat->n-1 + m] = x;
    else if(m-n == -1)
        mat->arr[2 * (mat->n) - 1 + m] = x;    
}

int get(struct Matrix mat, int m, int n)
{
        if(m-n == 1)
        return mat.arr[m];
    else if (m-n == 0)
        return mat.arr[mat.n-1 + m];
    else if(m-n == -1)
        return mat.arr[2 * (mat.n) - 1 + m]; 
    else
        return 0;
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
    int a[5][5]={{43, 65, 0, 0, 0},
                        {87, 76, 12, 0, 0},
                        {0, 45, 25, 93, 0},
                        {0, 0, 22, 65, 87},
                        {0, 0, 5, 87, 34}};

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
