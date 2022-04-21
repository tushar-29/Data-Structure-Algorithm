#include<stdio.h>
#include<stdlib.h>

int no_of_node, no_of_edges;

struct Node 
{
    int data;
    int weight;
    struct Node *next;
};

void adjoint_form()
{
    int arr[no_of_node][no_of_node];
    int length = no_of_node;
    int i=0, j=0;
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
}

void insert(struct Node **ptr, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = *ptr;
    temp->data = x;
    temp->next = NULL;
    printf("Enter its Weight = ");
    scanf("%d", &temp->weight);

    if(!*ptr)
        *ptr = temp;
    else
    {
    while(p && p->next)
        p = p->next;
    p->next = temp;
    }
}

void linked_form()
{
    struct Node *arr[no_of_node]={NULL};
    struct Node *p;
    int i=0, j=0, length=no_of_node;
    int ans=0;
    for(i=0; i<length; i++)
    {
        printf("For link %d \n", i+1);
        for(j=0; j<length; j++)
        {
            if(i != j)
            {
                printf("Have link with %d (1, 0) = ", j+1);
                scanf("%d", &ans);
                if(ans) insert(&arr[i], j+1);
            }
        }
    }


    for(i=0; i<length; i++)
    {
        p = arr[i];
        while(p)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void compact_form()
{
    int length = no_of_node + 2 * no_of_edges + 1;
    int arr[length] = {0};
    int i=0, j=no_of_node+1, k=0, x=0;
    for(i=0; i<no_of_node; i++)
    {
        arr[i] = j;
        k = 1;
        printf("For Node %d\n", i+1);
        while(k <= 5)
        {
            if(k != i+1)
            {
                printf("Enter the weight with link %d = ", k);
                scanf("%d", &x);
            }
            if(x)
                arr[j++] = x;
            k++;
        }
    }

    printf("\nArray\n");
    for(i=0; i<length; i++)
        printf("%d\t", arr[i]);
}

int main()
{
    no_of_node = 5,
    no_of_edges = 7;
    compact_form();
    return 0;
}