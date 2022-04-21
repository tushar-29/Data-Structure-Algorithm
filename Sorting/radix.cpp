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

int digit_count(int x)
{
    int i=1, count =0;
    while((x / i) % 10 != 0)
    {
        count++;
        i *= 10;
    }
    return count;
}

//  Time Comp = order(n)
//  Space Comp = order(n)
void radix_sort(int *arr, int n)
{
    int digit_size = digit_count(max(arr, n));
    struct Node *bin[10]={NULL};
    struct Node *ptr=NULL;
    int i=0, k=0, j=0, flag=1, index=0;
    for(i=0; i<digit_size; i++)
    {
        k =0;
        for(j=0; j<n; j++)
        {
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = arr[j];
            temp->next = NULL;
            index = (arr[j] / flag) % 10;
            if(!bin[index])
                bin[index] = temp;
            else
            {
                ptr = bin[index];
                while(ptr->next)
                    ptr = ptr->next;
                ptr->next = temp;
            }
        }
        flag *= 10;
        for(j=0; j<10; j++)
        {
            ptr = bin[j];
            while(ptr)
            {   
                arr[k++] = ptr->data;
                ptr = ptr->next;
            }
            bin[j] = NULL;
        }
    }
}

int main()
{
    int array[10] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = 10;
    radix_sort(array, n);
    display(array, n);
    return 0;
}