#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    /* data */
    int length, breath;
    int a[5];
    int *A;
};

// call by value 
void change_length(struct Rectangle r1, int len)
{
    r1.length = len;
    printf("call by value new length inside function = %d\n", r1.length);
}

// call by address
void change(struct Rectangle *p, int len)
{
    p->length = len;
    printf("Call by address new length inside function = %d\n", p->length);
}

// struct array passing by value
void by_value(struct Rectangle r2)
{
    printf("array in fuction and pass by value = ");
    for (int i = 0; i < 5; i++)
    {
        /* code */
        r2.a[i] = i+5;
        printf("\t%d", r2.a[i]);
    }
    printf("\n");
}

// struct array passing by address
void by_address(struct Rectangle *p1)
{
    printf("array by pass by address = ");
    for (int i = 0; i < 5; i++)
    {
        /* code */
        p1->a[i] = i+100;
        printf("\t%d", p1->a[i]);
    }
    printf("\n");
}

struct Rectangle * creat_obj()
{
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 1000;
    p->breath = 2000;
    p->A = (int *)malloc(5 * sizeof(int));
    p->A[0] = 128;
    p->A[1] = 64;
    p->A[2] = 32;
    p->A[3] = 16;
    return p;
}

int main()
{
    struct Rectangle r={20, 30};
    change_length(r, 10);
    printf("after calling the lenght = %d\n", r.length);

    change(&r, 100);
    printf("after calling the length = %d\n", r.length);

    //structure pass array with pass by value
    printf("your array is = ");
    for (int i = 0; i < 5; i++)
    {
        /* code */
        r.a[i] = i;
        printf("\t%d", r.a[i]);
    }
    printf("\n");

    by_value(r);
    printf("your array after passby value  = ");
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("\t%d", r.a[i]);
    }
    printf("\n");


    by_address(&r);
    printf("your array is after pass by address= ");
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("\t%d", r.a[i]);
    }
    printf("\n");

    // creating heap object og Rectangle
    struct Rectangle *ptr = creat_obj();
    printf("heap length = %d\nheap breath = %d\n", ptr->length, ptr->breath);
    printf("array is : ");
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("\t%d", ptr->A[i]);
    }
    
    free(ptr);
    return 0;
}
