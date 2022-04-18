#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int x;
};


void pass_by_value(int *p)
{
    *p +=10;
    printf("pass_by_value p = %d\n", *p);
}

void pass_by_ref(int **p)
{
    **p += 100;
    printf("pss_by_address_value = %d\n", **p);
}

void pass_by_value_arr(int *a)
{
    a[0] = 100;
    a[1] = 200;
    printf("pass_by_value arr = %d\t%d\n", a[0], a[1]);
}

void pass_by_ref_arr(int **a)
{
    *a[0] = 1000;
    *a[1] = 2000;
    printf("pss_by_address_value_arr = %d\t%d\n", *a[0], *a[1]);
}

void pass_by_value_str(struct Student *s)
{
    s->x = 100;
    printf("pass_by_value in struct = %d\n", s->x);
}

void pass_by_ref_str(struct Student **s)
{
    struct Node *temp= *s;

}

int main()
{
    // for int 
    printf("FOR INT\n");
    int b =1;
    int *p = &b;
    printf("value of a = %d\n", b);
    printf("calue of p = %d\n", *p);
    pass_by_value(p);
    printf("value of p after pass_by_value = %d\n", *p);
    pass_by_ref(&p);
    printf("value of p after pss_by_add = %d\n", *p);
    printf("\n\n");

    // conc: int pointer change in both cases;'



    // for array
    int arr[]={10, 20, 30, 40, 50};
    int *a;
    a = arr;
    
    printf("\n\nFOR INT POINTER TO ARRAY\n");
    printf("array 1st elemet = %d\t 2nd element = %d\n", a[0], a[1]);
    pass_by_value_arr(a);
    printf("array 1st elemet = %d\t 2nd element = %d\n", a[0], a[1]);
    printf("array real = %d\t%d\n = ", arr[0], arr[1]);
    // pass_by_value_arr(&a); since a is just address of 1 singe element of arr 
    //  value change with pass by value int pointer and pass by ref. does not work in int pointer

    printf("\n\nFOR ARRAY POINTER TO ARRAY\n");
    int *ptr[5];
    ptr[0] = &arr[0];
    ptr[1] = &arr[1];
    pass_by_value_arr(*ptr);
    printf("array 1st elemet = %d\t 2nd element = %d\n", *ptr[0], *ptr[1]);
    printf("array real = %d\t%d\n = ", arr[0], arr[1]);

    pass_by_ref_arr(ptr);
    printf("array 1st elemet = %d\t 2nd element = %d\n", *ptr[0], *ptr[1]);
    printf("array real = %d\t%d\n = ", arr[0], arr[1]);

// value does not change in both case of array of pointers;

    printf("\n\nFOR ARRAY POINTER TO ARRAY\n");
    int (*qtr)[5];
    qtr = &arr;
    *qtr[0] = 123;
    *qtr[1] = 456;
    printf("real value = %d\t%d\n", arr[0], arr[1]);
    printf("pass_by_value array_ pointer= %d\t%d\n", *qtr[0], *qtr[1]);
    pass_by_value_arr(*qtr);
    printf("pass_by_value =array_pointer %d\t%d\n", *qtr[0], *qtr[1]);
    printf("real value = %d\t%d\n", arr[0], arr[1]);

    pass_by_ref_arr(ptr);
    printf("pass_by_ref =array_pointer %d\t%d\n", *qtr[0], *qtr[1]);
    printf("real value = %d\t%d\n", arr[0], arr[1]);
    // value changes for 1st pos only 

    printf("\n\nFOR STRUCT\n\n");
    struct Student s={10};
    struct Student *st=&s;
    st->x = 10;
    pass_by_value_str(st);
    printf("real value = %d\n", st->x);

    pass_by_ref_str(&st);
    printf("real value  = %d\n", st->x);

}