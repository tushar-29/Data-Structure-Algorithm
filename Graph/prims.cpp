#include<stdio.h>
#include<stdlib.h>

int const no_of_edges= 9, no_of_node = 7;

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
            if(j< i)
            {
                printf("with node %d = ", j+1);
                scanf("%d", &arr[i][j]);
                arr[j][i] = arr[i][j];
            }
            else if(i == j)
                arr[i][j] = -1;
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

void initial_min(int arr[no_of_node][no_of_node], int spanning[no_of_node][2])
{
    int i=0, j=0, small=INT_MAX;
    for(i=0; i<no_of_node; i++)
    {
        for(j=0; j<no_of_node && j<i; j++)
        {
            if(arr[i][j] != -1&& arr[i][j] < small)
            {
                spanning[0][0] = j;
                spanning[0][1] = i;
                small = arr[i][j];
            }
        }
    }
}

int node_near(int arr[no_of_node][no_of_node], int *visited, int index_check)
{
    int i=0, small=INT_MAX, close_ind = visited[0];
    for(i=0; visited[i] != -1; i++)
    {
        if(arr[ visited[i] ][index_check] < small && arr[ visited[i] ][index_check] != -1)
        {
            small = arr[ visited[i] ][index_check];
            close_ind = visited[i];
        }
    }
    return close_ind;
}

int find_min_link(int arr[no_of_node][no_of_node], int *temp)
{
    int i=0, j=0, small=INT_MAX, y=0;
    for(j=0, i=temp[j]; j<no_of_node; j++, i =temp[j])
    {
        if(i != -2 && arr[i][j] != -1 && arr[i][j] < small)
        {
            small = arr[i][j];
            y = j;
        }
    }
    return y;
}

void display_spanning(int spanning[no_of_node-1][2])
{
    int i=0;
    printf("\nSpanning tree\n");
    for(i=0; i<no_of_node-1; i++)
    {
        printf("%d\t", spanning[i][0]);
        printf("%d\n", spanning[i][1]);
    }   
}

void prims(int arr[no_of_node][no_of_node])
{
    int temp[no_of_node];
    int visited[no_of_node];
    int i=0, index=0, y=0;

    for(i=0; i<no_of_node; i++)
    {
        temp[i] = -1;
        visited[i] = -1;
    }

    int spanning[no_of_node-1][2]={{0}};

    initial_min(arr, spanning);
    temp[spanning[0][0]] = temp[spanning[0][1]] = -2;
    visited[0] = spanning[0][0];
    visited[1] = spanning[0][1];

    y=2;
    i=1;
    while(visited[no_of_node-1] == -1)
    {
        for(index=0; index<no_of_node; index++)
        {
            if(temp[index] != -2)
                temp[index] = node_near(arr, visited, index);
        }
        visited[y] = find_min_link(arr, temp);
        spanning[i][0] = visited[y];
        spanning[i][1] = temp[visited[y]];
        temp[visited[y]] = -2;
        i++;
        y++;
    }
    display_spanning(spanning);
}

void initial_min_link_2(int arr[no_of_node+1][no_of_node+1], int spanning[2][no_of_node-1])
{
    int i=0, j=0, small=INT_MAX;
    for(i=2; i<=no_of_node; i++)
    {
        for(j=1; j<=no_of_node && j<i; j++)
        {
            if(arr[i][j] != 0 && arr[i][j] < small)
            {
                small = arr[i][j];
                spanning[0][0] = j;
                spanning[1][0] = i;
            }
        }
    }
}

void display_spanning_2(int spanning[2][no_of_node-1])
{
    int i=0, j=0;
    for(i=0; i<2; i++)
    {
        for(j=0; j<no_of_node-1; j++)
        {
            printf("%d\t", spanning[i][j]);
        }
        printf("\n");
    }
}

void prims_2(int arr[no_of_node+1][no_of_node+1])
{
    int near[no_of_node+1];
    int spanning[2][no_of_node-1]={{0}};
    int i=0, j=0, index=0, small=0;
    for(i=0; i<=no_of_node; i++)
        near[i] = INT_MAX;

    // initial steps
    initial_min_link_2(arr, spanning);
    near[spanning[0][0]] = 0;
    near[spanning[1][0]] = 0;

    for(i=1; i<=no_of_node; i++)
    {
        if(near[i] != 0)
        {
            if(arr[i][spanning[0][0]] != 0 && arr[i][spanning[1][0]] != 0 && arr[i][spanning[0][0]] < arr[i][spanning[1][0]])
                near[i] = spanning[0][0];
            else
                near[i] = spanning[1][0];
        }
    }

    // repeation step
    for(i=1; i<no_of_node-1; i++)
    {
        small = INT_MAX;
        for(j=1; j<=no_of_node; j++)
        {
            if(near[j] != 0 && arr[j][near[j]] != 0 && arr[j][near[j]] < small)
            {
                small = arr[j][ near[j] ];
                index = j;
            }
        }

        spanning[0][i] = index;
        spanning[1][i] = near[index];
        near[index] = 0;

        for(j=1; j<=no_of_node; j++)
        {
            if(near[j]!=0 && arr[j][index] != 0)
            {
                if(arr[j][near[j]] != 0 && arr[j][index] < arr[j][near[j]])
                    near[j] = index;
                else if(arr[j][near[j]] == 0)
                    near[j] = index;
            }
        }
    }
    display_spanning_2(spanning);
}
int main()
{
    // int **array = adjoint_form();
    int array[no_of_node][no_of_node] = {
        {-1, 25, -1, -1, -1, 5, -1},
        {25, -1, 12, -1, -1, -1, 10},
        {-1, 12, -1, 8, -1, -1, -1},
        {-1, -1, 8, -1, 16, -1, 14},
        {-1, -1, -1, 16, -1, 20, 18},
        {5, -1, -1, -1, 20, -1, -1},
        {-1, 10, -1, 14, 18, -1, -1}
    };
    // prims(array);

    int array2[no_of_node+1][no_of_node+1] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 25, 0, 0, 0, 5, 0},
        {0, 25, 0, 12, 0, 0, 0, 10},
        {0, 0, 12, 0, 8, 0, 0, 0},
        {0, 0,  0, 8, 0, 16, 0, 14},
        {0, 0, 0, 0, 16, 0, 20, 18},
        {0, 5, 0, 0, 0, 20, 0, 0},
        {0, 0, 10, 0, 14, 18, 0, 0}
    };
    prims_2(array2);
    return 0;
}