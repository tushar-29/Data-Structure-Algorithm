#include <stdio.h>
#include<stdlib.h>

// array is type of pointer
void fun(int A[], int n) // to be more spicific we can write (int *A, int n)
{
    printf("\narray = ");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("\t%d", A[i]);
    }
    
}

int * creat_array(int n)   // int [] creat_array(...) also works
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return (p);
}

int main()
{
    int a[5];
    a[0] = 10;
    a[1] = 20;
    fun(a, 5);   // no need to pass address of `a` since array itself behave like pointer 

    // creating array in heap and returning to a variable
    int *q;
    q = creat_array(5);
    q[0] = 100;
    q[1] = 200;
    fun(q, 5);
    free(q);
    return 0;
}