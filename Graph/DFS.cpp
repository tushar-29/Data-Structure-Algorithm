#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *arr;
    int size;
};

struct stack
{
    struct Array *a;
    int top;
};


void creat(struct stack *s, int n)
{
    s->a->size= n;
    s->a->arr = (int *)malloc(s->a->size * sizeof(int));
    s->top = -1;
}

int isFull(struct stack *s)
{
    if(s->top+1 == s->a->size)
        return 1;
    return 0;
}

int isEmpty(struct stack *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

void push(struct stack *s, int x)
{
    if(!isFull(s))
        s->a->arr[++s->top] = x; 
    else
        printf("Stack Overflow\n");
}

int pop(struct stack *s)
{
    int x;
    if(!isEmpty(s))
        return  s->a->arr[s->top--];
    else   
        printf("Stack Underflow\n");
    return -1;
}

int const no_of_edges= 8, no_of_node = 6;

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

//  Order of (n)
void DFS(int element)
{
    int **arr = adjoint_form();
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->a = (struct Array *)malloc(sizeof(struct Array));
    int visited[no_of_node] = {0};
    int i=0, j=0, x;
    creat(stack, no_of_node);

    printf("\n%d\t", element);
    visited[element-1] = 1;
    push(stack, element-1);
    while(!isEmpty(stack))
    {
        x = pop(stack);
        for(j=0; j<no_of_node; j++)
        {
            if(arr[x][j] != 0 && visited[j] != 1)
            {
                printf("%d\t", j+1);
                visited[j] = 1;
                push(stack, j);
            }
        }
    }
}

int visit[no_of_node] = {0};

void DFS_recc(int **arr, int element)
{

    int i=0;
    if(visit[element-1] == 0)
    {
        printf("%d\t", element);
        visit[element-1] = 1;
        for(i=0; i<no_of_node; i++)
        {
            if(arr[element-1][i] != 0 && visit[i] != 1)
                DFS_recc(arr, i+1);
        }
    }
}

int main()
{
    int **array = adjoint_form();
    DFS_recc(array, 1);
    return 0;
}