#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(int *arr, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int max(int *arr, int n)
{
    int i=0, large=arr[0];
    for(i=1; i<n; i++)
    {
        if(large < arr[i])
            large = arr[i];
    }
    return large;
}

void bin_sort(int *arr, int n)
{
    int ind = max(arr, n) + 1;
    struct Node *bin[ind] = {NULL};
    int i=0, k=0;
    struct Node *ptr=NULL;

    for(i=0; i<n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if(!bin[arr[i]])
            bin[arr[i]] = temp;
        else
        {
            ptr = bin[arr[i]];
            while(ptr->next)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }

    for(i=0; i<ind; i++)
    {
        ptr = bin[i];
        while(ptr)
        {   
            arr[k++] = ptr->data;
            ptr = ptr->next;
        }
    }
}

int main()
{
    int array[10] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    int n= 10;
    bin_sort(array, n);
    display(array, n);
    return 0;
}
