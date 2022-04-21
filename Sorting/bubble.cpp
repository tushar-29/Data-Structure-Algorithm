#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// no. of element = n
// no. of passes = n-1
// no. of comparison = 1+2+3+.....+(n-1) = n(n-1)/2 = order(n^2)
// no. of swaps = 1+2+3+.....+(n-1) = n(n-1)/2 = order(n^2)
//  so T.C. depend on no. of comparision so, Time Comp = order(n^2)
// note no. of each passes give that no. of largest elements
// Each largest elemet settle down in each passes, so no need to compare last element after each passes
// It is made adaptive by adding flag variable to it. (by nature Bubble Sort is not adaptive)
// It is Stable the order of duplicates does not changes 
//  max time = order(n^2) when array is descending order.
//  min time = order(n) when array is in ascending order.

void bubble(int *arr, int n)
{
    int i=0, j=0, flag=0;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            flag = 0;
            if(arr[j] > arr[j+1]) // arr[i] > arr[j] --for decending order
            {      
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}

void display(int *arr, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[9]={50, 20, 30, 60, 80, 70, 40, 90, 10};
    bubble(arr, 9);
    display(arr, 9);
    return 0;
}
