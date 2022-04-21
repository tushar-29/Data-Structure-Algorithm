#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*front={NULL}, *rear={NULL};

int isFull()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp)
        return 0;
    return 1;
}

int isEmpty()
{
    if(front)
        return 0;
    return 1;
}

int queueTop()
{
    if(!isEmpty())
        return front->data;
    return -1;
}

void enqueue(int x)
{
    if(!isFull())
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = NULL;
        if(front == NULL)
            front = rear = temp;
        else 
        {
            rear->next = temp;
            rear = rear->next;
        }    
    }
    else
        printf("Queue overflow\n");
}

int dequeue()
{
    int x = -1;
    if(!isEmpty())
    {
        struct Node *temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
    }
    else
        printf("Queue underflow\n");
    return x;
}

void display()
{
    struct Node *temp=front;
    while(temp)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int i;
    for(i=10; i<81; i+=10)
        enqueue(i);
    display();
    while(!isEmpty())
        printf("%d\t", dequeue());
}
