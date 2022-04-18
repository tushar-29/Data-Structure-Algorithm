#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *p)
{
    if(p)
   {
        while(p)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
   }
   else
        printf("No elemet present\n");
}

int length(struct Node *p)
{
    if(p == NULL)
        return 0;

    int i=1;    
    for(; p; p=p->next)
        i++;
    return i;
}

void insert(struct Node **real, int x, int pos=-1)
{
    struct Node *p=*real;
    if(pos == -1)
        pos = length(p);

    if(pos > length(p)+1 || pos < 0)
        return;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp ->next = NULL;
    if(pos == 0 || pos == 1)
    {
        temp->next =  *real;
        *real = temp;
    }
    else
    {
        int i=0;
        for(i=1; i<pos-1; i++)
            p=p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

struct Node *  concatinate(struct Node *first, struct Node *second)
{
    struct Node *p=first;
    while(p->next)
        p = p->next;
    p->next = second;
    second = NULL;
    return first;
}

struct Node * mearge(struct Node *first, struct Node *second)
{
    struct Node *p=NULL, *last=NULL;
    while(first!= NULL&& second!=NULL)
    {
        if(first->data < second->data)
        {
            if(p == NULL)
                p  = first;
            else
                last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else if(first->data > second->data)
        {
            if(p == NULL)
                p = second;
            else
                last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
        else
        {
            if(p == NULL)
                p = first;
            else
                last->next = first;
            second = second->next;
            first = first->next;
            last->next = NULL;
        }
    printf("hello\n");
    }
    for(; first!=NULL; first = first->next)
    {
        if(p == NULL)
            p = first;
        else
            last->next = first;
        last = first;
        last->next = NULL;
    }
    for(; second!=NULL; second = second->next)
    {
         if(p == NULL)
            p = second;
        else
            last->next = second;
        last = second;
        last->next = NULL;
    }
    return p;
}

int main()
{
    struct Node *first=NULL, *second=NULL, *third=NULL;
    insert(&first, 10);
    display(first);
    insert(&first, 15);
    insert(&first, 30);
    insert(&first, 40);
    insert(&first, 85);
    display(first);
    insert(&second, 5);
    insert(&second, 20);
    insert(&second, 60);
    insert(&second, 80);
    insert(&second, 100);
    display(second);
    // first = concatinate(first, second); 
    third = mearge(first, second);
    display(third);
    return 0;
}