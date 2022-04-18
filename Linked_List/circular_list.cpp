#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

int length()
{
    struct Node *p=head;
    int i=0;
    do
    {
       i++;
       p = p->next;
    } while (p!=head);
    return i;
}

void creat(int *arr, int n)
{
    struct Node *temp, *p;
    int i;

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = arr[0];
    p->next = p;
    head = p;

    for(i=1; i<n; i++, p = p->next)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = head;
        p->next = temp;
    }
}

void display()
{
    struct Node *p=head;
    printf("Your list is :\t");
    do
    {
        printf("%d\t", p->data);
        p = p->next;
    } while (p!=head);
    printf("\n");
}

void display_recc(struct Node *p)
{
    static int flag=0;
    if(p != head || flag != 1)
    {
        flag = 1;
        printf("%d\t", p->data);
        display_recc(p->next);
    }
    flag = 0;
}

void insert(int x, int pos=length())
{
    if(pos > length()+1 || pos < 0)
        return;
    
    struct Node *p=head, *temp;
    int i;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    if(pos == 0)
    {
        temp->next = head;
        while(p->next !=head)
            p = p->next;
        p->next = temp;
        head = temp;
    }
    else
    {
        for(i=0; i<pos-1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

int del_node(int pos)
{
    if(pos > length() || pos < 0)
        return -1;
    struct Node *p = head;
    int x;
    if(pos == 0)
    {
        x = head->data;
        while(p->next != head)
            p = p->next;
        p->next = head->next;
        free(head);
        head = p->next;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
            p= p->next;
        x = p->next->data;
        p->next = p->next->next;
        p = p->next;
        free(p);
    }
    return x;
}

int main()
{
    int arr[] = {10, 40, 20, 50, 80, 30};
    creat(arr, 6);
    display();
    // display_recc(head);
    insert(100, 0);
    display();
    insert(70, 2);
    display();
    insert(90);
    display();
    printf("element %d at pos 0 has been deleted.\n", del_node(0));
    display();
    printf("element %d at pos 4 has been deleted.\n", del_node(4));
    display();
    return 0;
}