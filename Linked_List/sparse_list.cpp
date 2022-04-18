#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int col_no, data;
    struct Node *next;
}*arr[5]={NULL};


void set(int i, int j, int x)
{
    // p is local scope of arr[i] 
    struct Node *temp, *p=arr[i];
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->col_no = j;
    temp->data = x;
    temp->next = NULL;
    if(p)
    {
        while(p->next)
            p = p->next;
        p->next = temp;
    }
    // here p = temp does not work because,
    // temp address is stored in p not the arr[i] address is been replace by p to link temp; 
    else   
        arr[i] = temp;
}

int get(int i, int j)
{
    struct Node *p= arr[i];
    while(p)
    {
        if(p->col_no == j)
            return p->data;
        p = p->next;
    }
    return 0;
}


void display()
{
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            printf("%d\t",get(i, j));
        printf("\n");
    }
}

int main()
{
    int a[5][5] = {{0 , 0 , 7, 0, 0},
                        {0, 8, 0, 9, 0},
                        {1, 0 ,0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 4, 5, 0, 2}};

    int i=0, j=0, row=5, col=5;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(a[i][j] != 0)
                set(i, j, a[i][j]);
        }
    }    
    display();

    return 0;
}
