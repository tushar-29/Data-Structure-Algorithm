#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10]={4, 6, 3, 9, 2, 5};
    printf("a value at index 2 = %d\n", a[3]);
    int b[5]={0};
    printf("b value at any index = %d\n", b[3]);
    int c[]={4, 6, 7};
    printf("c value at index 3 = %d\n", c[2]);

    int *p, i;
    p = (int *)malloc(5 * sizeof(int));
    printf("pointer array = ");
    for(i; i<5; i++)
    {
        p[i] = i+10;
        printf("\t%d", p[i]);
    }
    printf("\n");

    //changing the size of array

    int *q;
    q = (int *)malloc(10 * sizeof(int));
    for (i = 0; i < 5; i++)
        q[i] = p[i];
    p = q;
    q = NULL;
    
    printf("pointer array with extra space = ");
    for(i=0; i<10; i++)
    {
        p[i] = i+10;
        printf("\t%d", p[i]);
    }
    printf("\n");

}