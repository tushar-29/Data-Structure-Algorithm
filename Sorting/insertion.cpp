#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        struct Node *p = first;
        while(p->next)
            p = p->next;
        p->next = temp;
    }
}

void display_node()
{
    struct Node *p = first;
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// no. of element = n
// no. of passes = n-1
// no. of comparison = 1+2+3+.....+(n-1) = n(n-1)/2 = order(n^2)
// no. of swaps = 1+2+3+.....+(n-1) = n(n-1)/2 = order(n^2)
//  so T.C. depend on no. of comparision so, Time Comp = order(n^2)
// Insertion sort is more useful in linked list rather the array
//  It is Adaptive by nature
// It is Stable too.
//  max time = order(n^2) when array is descending order.
//  min time = order(n) when array is in ascending order.

void insertion(int *arr, int n)
{
    int i=0, j=0;
    for(i=1; i<n; i++)
    {
        for(j=i; j>0; j--)
        {
            if(arr[j-1] > arr[j])
                swap(&arr[j-1], &arr[j]);
            else
                break;
        }
    }
}

void display(int *arr, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void insertion_node()
{
    if(!first)
        return;
    struct Node *p=NULL;
    struct Node *q = first->next;
    while(q)
    {
        p=first;
        while(p != q)
        {
            if(p->data > q->data)
                swap(&p->data, &q->data);
            p = p->next;
        }
        q = q->next;
    }
}

int main()
{
    int arr[9]={50, 20, 30, 60, 80, 70, 20, 90, 10};
    insertion(arr, 9);
    display(arr, 9);

    insert(50);
    insert(20);
    insert(30);
    insert(60);
    insert(80);
    insert(70);
    insert(40);
    insert(90);
    insert(10);
    display_node();
    insertion_node();
    display_node();
    return 0;
}