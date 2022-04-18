#include<stdlib.h>
#include<stdio.h>

struct Node 
{
    int data;
    struct Node *prev, *next;
}*first=NULL;

int length()
{
    struct Node *p=first;
    int i=0;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}

void creat(int *arr, int n)
{
    struct Node *p, *temp;
    int i;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = arr[0];
    p->next = NULL;
    p->prev = NULL;
    first = p;

    for(i=1; i<n; i++, p = p->next)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        temp->prev = p;
        p->next = temp;
    }
}

void display()
{
    printf("Elemets are :\t");
    struct Node *p = first;
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(int x, int pos=length())
{
    if(pos > length()+1 || pos < 0)
        return;
    struct Node *p=first, *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(pos == 0)
    {
        temp->prev = first;
        if(first)
            temp->next = first->next;
        else   
            temp->next = NULL; 
        first = temp;
    }
    else
    {
        int i;
        for(i=0; i<pos-1; i++)
            p = p->next;
        
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        if(temp->next)
            temp->next->prev = temp;
    }
}

int del_node(int pos=length())
{
    if(pos > length() || pos < 0)
        return -1;
    struct Node *p=first;
    int i, x;
    if(pos == 0)
    {   
        x = first->data;
        p = p->next;
        p->prev = NULL;
        free(first);
        first = p;
    }
    else
    {
        for(i=0; i<pos-1; i++)
            p = p->next;

        x = p->next->data;
        if(p->next)
        {
            p = p->next;
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }    
        else   
        {
            p = p->next;
            p->prev->next = NULL;
        }
        free(p);
    }
    return x;
}

void reverse()
{
    if(length() <= 1)
        return;
    struct Node *p=first, *temp;
    while(p->next)
        p = p->next;

    first = p;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->next;
    }
}

int main()
{
    int arr[] = {20, 60, 30, 90, 40};
    creat(arr, 5);
    display();
    insert(100, 0);
    insert(10);
    display();
    printf("del element = %d\n", del_node(0));
    display();
    printf("del element = %d\n", del_node(3));
    display();
    reverse();
    display();
}