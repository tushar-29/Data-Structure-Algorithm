#include<stdio.h>
#include<stdlib.h>

int find(int *u, int x)
{
    while(u[x] >= 0)
        x = u[x];
    return x;
}

void Union(int *u, int a, int b)
{
    if(a < b)
    {
        u[b] = u[a] + u[b];
        u[a] = b;
    }
    else
    {
        u[a] = u[a] + u[b];
        u[b] = a;
    }
}


int no_of_nodes = 7;
int no_of_edges = 9;

void kruskal(int arr[3][9])
{
    int spanning[2][no_of_nodes-1] = {0};
    int included[no_of_edges] = {0};
    int set[no_of_edges+1];

    int i=0, j=0, small = arr[2][0], pos1=0, pos2=0, index=0;

    for(i=0; i<=no_of_edges; i++)
        set[i] = -1;  

    while(j<no_of_nodes-1)
    {
        small = INT_MAX;
        for(i=0; i<no_of_edges; i++)
        {
            if(small > arr[2][i] && included[i] == 0)
            {
                index = i;
                pos1 = arr[0][i];
                pos2 = arr[1][i];
                small = arr[2][i];
            }
        }
        pos1 = find(set, pos1);
        pos2 = find(set, pos2);
        if(pos1 != pos2)
        {
            Union(set, pos1, pos2);
            spanning[0][j] = pos1;
            spanning[1][j] = pos2;
            j++;
        }
        included[index] = 1;
    } 
    for(j=0; j<2; j++)
    {
        for(i=0; i<no_of_nodes-1; i++)
            printf("%d\t", spanning[j][i]);
        printf("\n");
    }   
}

int main()
{
    int edge[3][9]={
            {1, 1, 2, 2, 3, 4, 4, 5, 5},
            {2, 6, 3, 7, 4, 5, 7, 6, 7},
            {25, 5, 12, 10, 8, 16, 14, 20, 18}
    };
    kruskal(edge);
    return 0;
}