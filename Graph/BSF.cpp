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


int no_of_edges= 8, no_of_node = 6;

int ** adjoint_form()
{
    int length = no_of_node;
    int i=0, j=0;
    int **arr = (int **)malloc(no_of_node * sizeof(int *));

    for(i=0; i<no_of_node; i++)
        arr[i] = (int *)malloc(no_of_node * sizeof(int));


    for(i=0; i<length; i++)
    {
        printf("Enter the Link for node %d \n", i+1);
        for(j=0; j<length; j++)
        {
            if(i != j)
            {
                printf("with node %d = ", j+1);
                scanf("%d", &arr[i][j]);
            }
            else
                arr[i][j] = 0;
        }
    }

    printf("\n\nMatrix is : \n");
    for(i=0; i<length; i++)
    {
        for(j=0; j<length; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
    // int (*array)[no_of_node] = arr;
    return arr;
}

void BSF(int element)
{
    int **arr = adjoint_form();
    printf("\n");
    struct Node *queue=(struct Node *)malloc(sizeof(struct Node));
    int visited[no_of_node] = {0};
    creat(queue, no_of_node);
    int i=0, j=0, x;

    printf("%d\t", element);
    visited[element-1] = 1;
    enqueue(queue, element-1);
    while(!isEmpty(queue))
    {
        x = dequeue(queue);
        for(j=0; j<no_of_node; j++)
        {
            if(arr[x][j] != 0 && visited[j] != 1)
            {
                printf("%d\t", j+1);
                enqueue(queue, j);
                visited[j] = 1;
            }
        }
    }
}


int main()
{
    BSF(1);
    return 0;
}