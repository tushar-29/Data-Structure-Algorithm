#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;


void creat(int *arr, int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for(i=1; i<n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next= NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *ptr)  //pass by value pointer
{
    printf("Your array is : \n");
    while(ptr)
    {
        printf("%d\t", ptr->data);
        ptr= ptr->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int sum(struct Node *p)
{
    int s=0;
    while(p)
    {
        s += p->data;
        p= p->next;
    }
    return s;
}

int sum_recc(struct Node *p)
{
    if(p)
        return sum_recc(p->next) + p->data;
    return 0;
}

int max(struct Node *p)
{
    int m=INT_MIN;
    while(p)
    {
        if(p->data > m)
            m = p->data;
        p=p->next;
    }
    return m;
}

int min(struct Node *p)
{
    int m=INT_MAX;
    while(p)
    {
        if(p->data < m)
            m = p->data;
        p=p->next;
    }
    return m;
}

int max_recc(struct Node *p)
{
    int x=0;
    if(!p)
        return INT_MIN;
    x = max_recc(p->next);
    return p->data > x? p->data : x;
}

int search(struct Node *p, int x)
{
    while(p)
    {
        if(p->data == x)
            return 1;
        p = p->next;
    }
    return 0;
}

int search_recc(struct Node *p, int x)
{
    if(!p)
        return 0;
    if(p->data == x)
        return 1;
    return search_recc(p->next, x);
}

int search_improve(struct Node *p, int x)
{
    struct Node *q;
    while(p)
    {
        if(p->data == x)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return 1;
        }
    q = p;
    p = p->next;
    }
    return 0;
}

void insert(struct Node *p, int pos, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if(pos == 0 || pos == 1)
    {
        temp->next = first;
        first = temp;
    }
    if(pos > 1 && pos <= count(p)+1)    
    {
        int i = 0;
        for(i=1; i<pos-1; i++)    
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
}

void sort_insert(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(p == NULL)
        first = temp;
    
    else if(p->data > x)
    {
        temp->next = p;
        first = temp;
    }
    else
    {
        while(p->next && p->next->data < x)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

int del_node(struct Node *p, int x)
{
    if(p == NULL)
        return -1;

    struct Node *q=NULL;
    while(p)
    {
        if(p->data == x)
        {
            if(p == first)
                first = first->next;
            else
                q->next = p->next;
            free(p);
            return x;
        }
        q = p;
        p = p->next;
    }
    return -1;
}

int is_sorted(struct Node *p)
{
    int flag = INT_MIN;
    while(p)
    {
        if(p->data < flag)
            return 0;
        flag = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int arr[]= {10, 20, 30, 40, 50, 7, 80, 100};
    creat(arr, 8);
    display(first);     //pointer pass by value
    printf("IS sorded %d\n", is_sorted(first));
    // // printf("search for 7 recc = %d\n", search_improve(first, 7));
    // // display(first);
    // printf("no of nodes = %d\n", count(first));
    // printf("sum of all element = %d\n", sum(first));
    // printf("sum recc = %d\n", sum_recc(first));
    // printf("Max element = %d\n", max(first));
    // printf("Min element = %d\n", min(first));
    // printf("Max recc = %d\n", max_recc(first));
    // printf("search for 7 = %d\n", search(first, 7));
    // printf("Search 100 = %d\n", search(first, 100));
    // printf("search for 7 recc = %d\n", search_recc(first, 7));
    // printf("Search 100 recc = %d\n", search_recc(first, 100));
    // printf("insert 33 at pos 0 :\n");
    // insert(first, 0, 33);
    // display(first);
    // printf("insert 79 at pos 1:\n");
    // insert(first, 1, 79);
    // display(first);
    // printf("insert 67 at pos 5:\n");
    // insert(first, 5, 67);
    // display(first);
    // printf("insert 100 at pos 12:\n");
    // insert(first, 12, 1);
    // display(first);

    // sort_insert(first, 10);
    // display(first);
    // sort_insert(first, 5);
    // display(first);
    // sort_insert(first, 30);
    // display(first);
    // sort_insert(first, 20);
    // display(first);
    // sort_insert(first, 100);
    // display(first);
    // sort_insert(first, 1);
    // display(first);
    // del_node(first, 1);
    // display(first);
    // del_node(first, 20);
    // display(first);
    // del_node(first, 100);
    // display(first);
    return 0;
}
