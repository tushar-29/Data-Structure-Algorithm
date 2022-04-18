#include <stdio.h>
#include <stdlib.h>

void show(int **p)
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }
}

void show_1(int *p)
{
    int i, j;
    printf("\n Second array B\n");
    for(j=0; j<4; j++)
        printf("%d\t", p[j]);

}

int main()
{
    int A[3][4];
    int i, j, z=0;
    printf("static 2D array : \n");
    for(i=0; i<3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            A[i][j] = ++z;
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    //row = 3 & column = 4
    int *B[3];
    for(i=0; i<3; i++)
        B[i] = (int *)malloc(4 * sizeof(int));
    printf("Semi-dynamic 2D Array : \n");
    for(i=0; i<3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            B[i][j] = i + j + 10;
            printf("%d\t", B[i][j]);
        }
    printf("\n");
    }

    int **C;
    // creating row
    C = (int **)malloc(3 * sizeof(int));
    for (i = 0; i < 4; i++)
        C[i] = (int *)malloc(4 * sizeof(int));

    printf("dynamic 2D Array : \n");
    for(i=0; i<3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            C[i][j] = i + j + 100;
            printf("%d\t", C[i][j]);
        }
    printf("\n");
    }
    
    int *D = (int *)malloc(3 * 4 * sizeof(int));
    printf("Single Dynamic Array : \n");
    for(i=0; i< 3; i++)
    {
        for(j=0; j<4; j++)
        {
            *(D + i*4 + j) = i + j + 1000;
            printf("%d\t", *(D + i*4 + j));
        }
        printf("\n");
    }
    printf("\n");

    show(C);
    show(B);
    show_1(B[0]); // only one row is send
    show_1(C[0]); // only one row is send 

    for(i=0; i<3; i++)
    {
        free(B[i]); // B is a 1D array in stack and value of cell in B is array in heap making 2D array, cell allocation is freed only
        free(C[i]); // C is a 2D array in heap, so cell allocation is freed then 
    }
    return 0;
}

/*
https://www.log2base2.com/C/pointer/arr+1-vs-address-of-arr+1.html
1 int = 4bytes
arr = base address is 1000

for 1 Darray : 

 if Array `arr` of length 5 take memory of 1020 = 1000 + (5 * 4)
 so whole `arr` take memory of 1000 to 1020. So in program we write: 

 &arr :  it refer to whole 1000 to 1020 memmory.

 arr : it refer to only the base address that is 1000;
 arr + 0 : it refer to memory 1000 to 1004. address
 arr +1 : it refer to memory 1004 to 1008. address
 ................................................................................
 arr + 5: it refer to memory 1016 to 1020. address

 if we write this in program:

 arr + 1 : it refer to arr[1] address
 &(arr + 1): it refer to another memory which take 1020 to 1040 memory. It will be another array
 so, 
 *(arr + 2) : 
                (arr + 2) : it mean arr[2] address
                *(arr + 2) : value at address arr[2]


using double pointer to access 1D array

if Array `arr` of length 5 is copied to double pointer then :
int *p[5];
p = &arr;
here whole  memory of 1000 to 1020 is copied in pointer p
*p act as arr i.e base address which is 1000;
*(p+1) or *p+1 or arr+1 act as address of 2nd element in array i.e 1004 to 1008bytes.

to access the element we use
**p  or *(arr) to access first value in the array;


*/
