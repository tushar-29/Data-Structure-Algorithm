#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *arr, size, flag;
};

void set(struct Matrix *mat, int m, int n, int x)
{
    if(m+n <= mat->flag - 1)
        mat->arr[ mat->size - (( (mat->flag-m) * (mat->flag-(m-1)) )/2) + n] = x;
    
}

int get(struct Matrix mat, int m, int n)
{
    if(m+n <= mat.flag - 1)
        return mat.arr[ mat.size - (( (mat.flag-m) * (mat.flag-(m-1)) )/2) + n];
    return 0;
}

void display(struct Matrix mat)
{
    int i, j;
        for(i=0; i<mat.flag; i++)
    {
        for(j=0; j<mat.flag; j++)
            printf("%d\t", get(mat, i, j));
        printf("\n");
    }
}

int main()
{
    //matrix to be converted into diagonal 1d array
    int a[5][5] = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 0},
                        {10, 11, 12, 0, 0},
                        {13, 14, 0, 0, 0 },
                        {15, 0, 0, 0, 0}};


    struct Matrix mat;
    mat.flag = 5;
    mat.size = mat.flag * (mat.flag + 1) / 2;
    mat.arr = (int *)malloc(mat.size * sizeof(int));
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            set(&mat, i, j, a[i][j]);
    }
    //printing the 1d array as 2d upper triangle matrix
    display(mat);
}


/*
1   2   3   4   5   |   6   7   8   9   |   10  11  12  |  13  14   |  15  
0   1   2   3   4  |    5   6   7   8   |   9    10  11  |  12  13   |  14
a[2][1] = 11 at index 10
[5 + 4] + 1    || 15 -  (5-2)*(5-(2-1))/2 + 1 = 15 - (3*4)/2 +1 = 15-6+1 = 10
15- = 10

a[3][1] =  14 at index 13
15 - (5-3)* (5-(3-1))/2 + 1 = 15 - (2*3)/2 +1 = 15 - 3 + 1 = 13

a[1][3] = 9 at index 8
15 - [ (5-1) * (5-(1-1))]/2 + 3 = 15 - (4*5)/2 + 3 = 15-10 + 3 = 8

a[0][0] = 1 at index 0
15 - (5-0)*(5-(0-1))/2 + 0 = 15 - (5*6)/2 + 0 =0;

a[i][j] =
size - [ (dim - i) * (dim - (i - 1)) ]/2 + j 


00  01   02   03    04
10  11   12   13    14`
20  21   22   23`   24`
30  31   32`  33`   34`
40  41`  42`  43`   44`
*/
