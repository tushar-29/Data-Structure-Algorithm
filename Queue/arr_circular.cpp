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
    if((queue->rear+1) % queue->size == queue->front)
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
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->arr[queue->rear] = x;
    }
    else
        printf("Queue overflow\n");
}

int dequeue(struct Node *queue)
{
    int x=-1;
    if(!isEmpty(queue))
    {
        queue->front = (queue->front+1) % queue->size;
        x = queue->arr[queue->front];
    }
    else
        printf("Queue underflow\n");
    return x;
}

void display(struct Node *queue)
{
    if(isEmpty(queue))
        printf("Empty Queue\n");
    int i = queue->front + 1;
    do
    {
        printf("%d\t", queue->arr[i]);
        i = (i+1) % queue->size;
    }while (i != (queue->rear+1) % queue->size);
    

    printf("\n");
}

int main()
{
    struct Node *queue;
    int size=10, i;
    creat(queue, size);
    for(i=10; i<81; i+=10)
        enqueue(queue, i);

    display(queue);
    while (!isEmpty(queue))
    {
        printf("%d\t", dequeue(queue));
    }
    return 0;
}
