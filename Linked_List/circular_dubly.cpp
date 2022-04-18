#include<stdlib.h>
#include<stdio.h>

struct Node 
{
    int data;
    struct Node *prev, *next;
}*head=NULL;

int length()
{
    struct Node *p=head;
    int i=0;
    do
    {
        i++;
        p = p->next;
    }while(p != head);
    return i;
}

void creat(int *arr, int n)
{
    struct Node *p, *temp;
    int i;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = arr[0];
    p->prev = p;
    p->next = p;
    head = p;

    for(i=1; i<n; i++, p = p->next)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        p->next = temp;
        temp->prev = p;
        temp->next = head;
        head->prev = temp;
    }
}

void display()
{
    printf("Elemets are :\t");
    struct Node *p = head;
    do
    {
        printf("%d\t", p->data);
        p = p->next;
    }while(p != head);
    printf("\n");
}

void insert(int x, int pos=length())
{
    if(pos > length()+1 || pos < 0)
        return;
    struct Node *p=head, *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = temp;
    temp->next = temp;
    if(pos == 0)
    {
        if(head)
        {
            temp->prev = head->prev;
            temp->next = head;
            head->prev->next = temp;
            head->prev = temp;
        }
        head = temp;
    }
    else
    {
        int i;
        for(i=0; i<pos-1; i++)
            p = p->next;
        
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        temp->next->prev = temp;
    }
}

int del_node(int pos=length())
{
    if(pos > length() || pos < 0)
        return -1;
    struct Node *p=head;
    int i, x;
    if(pos == 0)
    {   
        x = head->data;
        p->prev->next = head->next;
        p = p->next;
        free(head);
        head = p;
    }
    else
    {
        for(i=0; i<pos-1; i++)
            p = p->next;

        x = p->next->data;
        p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
    return x;
}

int main()
{
    int arr[] = {20, 60, 30, 90, 40};
    creat(arr, 5);
    display();
    insert(100, 0);
    display();
    insert(10);
    display();
    printf("del element = %d\n", del_node(0));
    display();
    printf("del element = %d\n", del_node(3));
    display();
}
