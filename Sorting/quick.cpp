#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *arr, int n=9)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

// no. of passes = n-1
// no. of comparision = n(logbase2 n) comparison
// no. of swap = 
// Time Comp. = order (nlogn)
// min time = order(nlog n)
// max time = order(n^2)
void quick(int *arr, int low, int high)
{
    int pivot=low;
    int i=low+1, j=high;
     while(i<=j)
    {
        while(arr[i] <= arr[pivot] && i<=high)
            i++;
        while(arr[j] > arr[pivot] && j>=low)
            j--;
        if(i<=j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[pivot], &arr[j]);
    if(j>low)
        quick(arr, low, j-1);
    if(i<high)
        quick(arr, j+1, high);

}

int main()
{
    int array[9] = {50, 70, 30, 20, 60, 90, 10, 40, 80};
    int n = 9;
    display(array, n);
    quick(array, 0, n-1);
    display(array, n);
    return 0;
}