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

int is_loop(struct Node *first)
{
    struct Node *p = first, *q = first;
    while(p && q && p!=q)
    {
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : NULL;
    }
    return p == q ? 1 : 0;
}

int main()
{
    struct Node *first, *p;
    insert(&first, 10);
    insert(&first, 20);
    insert(&first, 30);
    insert(&first, 30);
    insert(&first, 40);
    insert(&first, 50);
    insert(&first, 60);
    insert(&first, 70);
    display(first);
    p =first;
    while(p->next)
        p = p->next;
    p->next = first;
    printf("IS LOOP = %d\n", is_loop(first));
    return 0;
}