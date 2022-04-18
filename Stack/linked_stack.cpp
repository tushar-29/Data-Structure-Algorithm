#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;


int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp)
        return 0;
    return 1; 
}

int isEmpty()
{
    if(top)
        return 0;
    return 1;
}

int stackTop()
{
    if(top)
        return top->data;
    return -1;
}

void push(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(!isFull())
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }   
    else
        printf("Stack Overflow\n");
}

int pop()
{
    struct node *p=top;
    int x=-1;
    if(!isEmpty())
    {
        top = top->next;
        x = p->data;
        free(p);
    }
    else 
        printf("Stack Underflow\n");
    return x;
}

int peek(int pos)
{
    if(pos < 0)
        return -1;

    struct node *p=top;
    int i=0;
    for(i=0; i<=pos; i++)
    {
        if(p)
            p = p->next;
        else
            -1;
    }
    return p->data;
}

void display()
{
    struct node *p = top;
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

int main()
{
    int i=0;
    for(i=10; i< 51; i+=10)
        push(i);

    display();
    printf("\n");
    struct node *q = top;
    while(q != NULL)
    {
        q = q->next;
        printf("%d\t", pop());
    }
    return 0;
}
