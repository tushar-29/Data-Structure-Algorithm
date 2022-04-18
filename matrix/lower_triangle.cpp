#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *arr, size, flag;
};

void set(struct Matrix *mat, int m, int n, int x)
{
    if(m>=n)
        mat->arr[((m * (m+1)) / 2) + n] = x;

// another formula if coloum is stored
//  mat->arr[ ((mat->flag*n)-( n * (n - 1)) / 2)  + (m-n)] = x;
    
}

int get(struct Matrix mat, int m, int n)
{
    int ind;
    if(m>=n)
        return mat.arr[ ((m * (m+1)) / 2) + n];
    return 0;
}

void display(struct Matrix mat)
{
    int i, j;
        for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            printf("%d\t", get(mat, i, j));
        printf("\n");
    }
}

int main()
{
    //matrix to be converted into diagonal 1d array
    int a[5][5] = {{1, 0, 0, 0, 0},
                        {2, 3, 0, 0, 0},
                        {4, 5, 6, 0, 0},
                        {7, 8, 9, 10, 0 },
                        {11, 12, 13, 14, 15}};


    struct Matrix mat;
    mat.flag = 5;
    mat.size = mat.flag * (mat.flag+1) / 2;
    mat.arr = (int *)malloc(mat.size * sizeof(int));
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            set(&mat, i, j, a[i][j]);
    }

    //printing the 1d array as 2d diagonal matrix
    display(mat);
}

/*
`00   01   02   03   04
`10  `11   12   13   14
`20  `21  `22   23   24
`30  `31  `32  `33   34
`40  `41  `42  `43  `44

1   2   4   7   11  |   3   5   8   12  |   6   9   13  |   10  14  |   15
0   1   2   3   4       5    6   7    8       9  10  11      12  13     14

arr[3][2] = 9 at index 10
(5 + 4) + (i-j) = 9+1 = 10
n + n-1 + n-2.......+ n-(j-1)

nj - (j-1)j/2 + (i-j)
arr[4][3] = 14 at index 13
(5*3) - (3 * (3-1)/2 + (4-3) => (15 - (6/2) + 1) => 16 - 3 => 13

arr[1][1]
(5*1) - 

arr[4][2] = 13 at index 11


*/