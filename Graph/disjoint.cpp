#include<stdlib.h>
#include<stdio.h>

struct Array
{
    int *arr;
    int size;
};

void creat(struct Array *a, int n)
{
    a->size = n;
    a->arr = (int *)malloc(a->size * sizeof(int));
    int i=0;
    for(i=0; i<a->size; i++)
        a->arr[i] = -1;
};

void creat_universal_set(struct Array *u, struct Array set1, struct Array set2)
{   
    int i=0, j=0, k=0;
    u->arr[ set1.arr[0] ] = set1.size * -1;
    u->arr[ set2.arr[0] ] = set2.size * -1;
    for(i=1; i<set1.size; i++)
        u->arr[ set1.arr[i] ] = set1.arr[0];

    for(i=0; i<set2.size; i++)
        u->arr[ set2.arr[j] ] = set2.arr[0];
}

void Union(struct Array *u, int x, int y)
{
    if(u->arr[x] < u->arr[y])
    {
        u->arr[x] = u->arr[x] + u->arr[y];
        u->arr[y] = x;
    }
    else
    {
        u->arr[y] = u->arr[x] + u->arr[y];
        u->arr[x] = y;
    }
}

int find(struct Array u, int x)
{
    while(u.arr[x] >= 0)
        x = u.arr[x];
    return x;
}

int main()
{
    struct Array set1, set2;
    creat(&set1, 3);
    creat(&set2, 4);
    set1.arr[0] = 3; set1.arr[1] = 5; set1.arr[2] = 9;
    set2.arr[0] = 4; set2.arr[1] = 7; set2.arr[2] = 8; set2.arr[3] = 10;

    struct Array U;
    creat(&U, set1.size+set2.size+1);
    creat_universal_set(&U, set1, set2);
    Union(&U, set1.arr[0], set2.arr[0]);
    return 0;
}