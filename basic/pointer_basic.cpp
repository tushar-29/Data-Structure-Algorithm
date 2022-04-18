#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 5;
    int *p;         // decleration of pointer p
    p = &a;     // at p address of a is stored and initialisation of pointer
    printf("a = %d\n", a);
    printf("p = %d\n", p);
    printf("address of a = %d\n", &a);
    printf("value of pointer which it point = %d\n", *p);

    // accessing heap memory
    // adding header file to access it 

    int *q;
    q = (int *)malloc(5 * sizeof(int));     //array of 5 space in heap
    // in c++ it is q = new int[5];

    q[0] = 5;   //  in stack memory or heap memory pointer act as name of array
    printf("%d\n", q[0]);    
    int arrd[5];
    arrd[0] = 100;
    arrd[2] = 200;
    printf("%d\n", arrd[0]);
    int *r;
    r = arrd;        // no need '&' symbol to access array data type since array is itself act like pointers
    printf("%d\n%d\n", r[0], r[3]);
    int *s;
    printf("Size: int = %d\n", sizeof(int));
    printf("char  = %d\n", sizeof(char));
    printf("float  = %d\n", sizeof(float));
    printf("double  = %d\n", sizeof(double));
    printf("pointer  = %d\n", sizeof(s));
    free(q);
    return 0;
}

    /** all pointer take 8byte of memory 
    int take 4 byte in program but in pen-paper it take 2 byte
    char take 4byte memory but in pen-paper it take 1byte* */