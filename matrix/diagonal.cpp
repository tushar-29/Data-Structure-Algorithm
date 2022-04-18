#include<stdio.h>

struct Matrix
{
    int arr[5], length;
};

void set(struct Matrix *mat, int m, int n, int x)
{
    if(m==n)
        mat->arr[m] = x;
}

int get(struct Matrix mat, int m, int n)
{
    if(m==n)
        return mat.arr[m];
    return 0;
}

void display(struct Matrix mat)
{
    int i, j;
        for(i=0; i<mat.length; i++)
    {
        for(j=0; j<mat.length; j++)
            printf("%d\t", get(mat, i, j));
        printf("\n");
    }
}

int main()
{
    //matrix to be converted into diagonal 1d array
    int a[5][5] = {{1, 0, 0, 0, 0},
                        {0, 2, 0, 0, 0},
                        {0, 0, 3, 0, 0},
                        {0, 0, 0, 4, 0 },
                        {0, 0, 0, 0, 5}};
    
    struct Matrix mat={{0}, 5};
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            set(&mat, i, j, a[i][j]);
        }
    }

    //printing the 1d array as 2d diagonal matrix
    display(mat);
}
