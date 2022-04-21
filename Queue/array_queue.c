#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int *arr, front, rear, size;
};

void creat(struct Node *queue, int n)
{
    queue->size = n;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    queue->front = queue->rear = -1;
}

int isFull(struct Node *queue)
{
    if(queue->rear == queue->size-1)
        return 1;
    return 0;
}

int isEmpty(struct Node *queue)
{
    if(queue->front == queue->rear)
        return 1;
    return 0;
}

int queueTop(struct Node *queue)
{
    if(!isEmpty(queue))
        return queue->arr[queue->front+1];
    return 0;
}

void enqueue(struct Node *queue, int x)
{
    if(!isFull(queue))
        queue->arr[++queue->rear] = x;
    else
        printf("Queue overflow\n");
}

int dequeue(struct Node *queue)
{
    int x=-1;
    if(!isEmpty(queue))
        x = queue->arr[++queue->front];
    else
        printf("Queue underflow\n");
    return x;
}

int peek(struct Node *queue, int pos)
{
    int ex_pos = pos + queue->front + 1;
    if(!(ex_pos >= 0 && ex_pos <= queue->rear))
        return -1;
    return queue->arr[ex_pos];
}

void display(struct Node *queue)
{
    if(isEmpty(queue))
        printf("Enpty Queue\n");
    else
    {
        int i;
        for(i=queue->front+1; i<=queue->rear; i++)
            printf("%d\t", queue->arr[i]);
        printf("\n");
    }
}

int main()
{
    struct Node *queue;
    int size=10, i;
    creat(queue, size);
    for(i=10; i<81; i+=10)
        enqueue(queue, i);

    display(queue);
    dequeue(queue);
    dequeue(queue);
    printf("\n%d\n", queueTop(queue));
    printf("\n%d\n", queue->front);
    display(queue);
    printf("\n%d\n", peek(queue, 6));

    while (!isEmpty(queue))
    {
        printf("%d\t", dequeue(queue));
    }

    return 0;
}
