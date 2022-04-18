#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void display()
{
    if(first != NULL)
   {
        struct Node *p=first;
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

int length()
{
    if(first == NULL)
        return 0;

    struct Node *p=NULL;
    int i=0;    
    for(p=first; p; p=p->next)
        i++;
    return i;
}

void insert(int x, int pos=length())
{
    if(pos > length()+1 || pos < 0)
        return;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp ->next = NULL;
    if(pos == 1 || pos == 0)
    {
        temp->next =  first;
        first = temp;
    }
    else
    {
        struct Node *p=first;
        int i=0;
        for(i=1; i<pos-1; i++)
            p=p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

// space comp = order(n) and space comp. = order(n)
void reverse_elemet()
{
    if(!first || !first->next)
        return;
        int arr[length()];
    struct Node *p=first;
    int i;
    while(p)
    {
        arr[i++] = p->data;
       p=p->next;
    }
    p = first;
    while(p)
    {
        p->data = arr[--i];
        p = p->next;
    }
}


void reverse_node()
{
    Node *p=first, *q=NULL, *r=NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_recc(struct Node *p, struct Node *q=NULL)
{
    if(p)
    {
        reverse_recc(p->next, p);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    insert(10);
    insert(30, 2);
    insert(20, 2);
    insert(40, 4);
    display();
    reverse_elemet();
    display();
    reverse_node();
    display();
    reverse_recc(first);
    display();
    return 0;
}
