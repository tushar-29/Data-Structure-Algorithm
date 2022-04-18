#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

int length()
{
    struct Node *p=NULL;
    int i=0;
    if(p)
        return i;
    i = 1;
    for(p=first; p; p=p->next)
        i++;
    return i;
}

void display()
{
    struct Node *p=first;
    printf("Elements are :\t");
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
    int i;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(pos ==0 || pos == 1)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        for(i=1; i<pos-1; i++)
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
}
// count duplicate and display duplicate
void is_duplicate()
{
    struct Node *p=first, *q=NULL;
    if(!(p->next || p))
        return;
    
    int flag=-1, count=0;
    while(p->next)
    {
        q = p->next;
        if(p->data == q->data)
        {
            if(p->data != flag)
            {
                printf("%d is duplicated ", p->data);
                flag = p->data;
            }
            count++;
            // p->next = q->next;
            // free(q);
        }
        else if(count > 0)
        {
            printf("%d times\n", count);
            count =0;
        }
        p = p->next;
    }
}

void del_duplicate()
{
    struct Node *p=first, *q=NULL;
    if(!(p->next || p))
        return;
    
    q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = p->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}


int main()
{
    int i;
    for(i=10; i<101; i=i+10)
    {
        insert(i);
        display();
    }

    insert(30, 4);
    insert(30, 4);
    insert(30, 4);
    insert(50, 8);
    insert(50, 8);
    insert(50, 8);
    insert(50, 9);
    display(); 
    is_duplicate();
    del_duplicate();
    display();
}